#include "figure_entertainer.h"

#include "core/calc.h"
#include "grid/road_network.h"
#include "grid/road_access.h"
#include "graphics/image.h"
#include "figure/image.h"
#include "grid/building.h"
#include "figure/service.h"

void figure_entertainer::bandstand_coverage(building* b, int shows) {
    b->data.house.bandstand_juggler = MAX_COVERAGE;
    if (shows == 2) {
        b->data.house.bandstand_musician = MAX_COVERAGE;
    }
}

void figure_entertainer::senet_coverage(building *b, int shows) {
    b->data.house.senet_player = MAX_COVERAGE;
}

int figure_entertainer::provide_entertainment(int shows, void (*callback)(building*, int)) {
    int serviced = 0;
    grid_area area = map_grid_get_area(tile(), 1, 2);
    map_grid_area_foreach(area.tmin, area.tmax, [&] (tile2i t) {
        int building_id = map_building_at(t);
        if (!building_id) {
            return;
        }

        building *b = building_get(building_id);
        if (b->house_size && b->house_population > 0) {
            callback(b, shows);
            serviced++;
        }
    });
    return serviced;
}

int figure_entertainer::determine_venue_destination(tile2i tile, const svector<e_building_type, 4> &btypes) {
    int road_network = map_road_network_get(tile);

    svector<building *, 128> venues;
    buildings_valid_do([&] (building &b) {
        const bool found = (std::find(btypes.begin(), btypes.end(), b.type) != btypes.end());
        if (!found) {
            return;
        }

        if (b.distance_from_entry && b.road_network_id == road_network) {
            if (!b.is_main()) { // only send directly to the main building
                return;
            }
            venues.push_back(&b);
        }
    });

    if (venues.empty()) {
        return 0;
    }

    int min_building_id = 0;
    int min_distance = 10000;
    for (building *v: venues) {
        building* b = v->main();
        if (!b->num_workers) {
            continue;
        }

        int days_left;
        if (btypes.size() == 3) {
            days_left = b->data.entertainment.days3_or_play;
        } else if (btypes.size() == 2) {
            days_left = b->data.entertainment.days2;
        } else {
            days_left = b->data.entertainment.days1;
        }
        int dist = days_left + calc_maximum_distance(tile, b->tile);

        if (dist < min_distance) {
            min_distance = dist;
            min_building_id = v->id;
        }
    }

    return min_building_id;
}

int figure_entertainer::determine_closest_venue_destination(tile2i tile, const svector<e_building_type, 4> &btypes) {
    int road_network = map_road_network_get(tile);

    svector<building *, 128> venues;
    buildings_valid_do([&] (building &b) {
        const bool found = (std::find(btypes.begin(), btypes.end(), b.type) != btypes.end());
        if (!found) {
            return;
        }

        if (b.distance_from_entry && b.road_network_id == road_network) {
            if (!b.is_main()) { // only send directly to the main building
                return;
            }
            venues.push_back(&b);
        }
    });

    if (venues.empty()) {
        return 0;
    }

    int min_distance = 10000;
    int min_building_id = 0;
    for (building *v : venues) {
        building *b = v->main();

        int dist = calc_maximum_distance(tile, b->tile);

        if (dist < min_distance) {
            min_distance = dist;
            min_building_id = v->id;
        }
    }

    return min_building_id;
}

void figure_entertainer::figure_action() {
    base.wait_ticks_missile++;
    if (base.wait_ticks_missile >= 120) {
        base.wait_ticks_missile = 0;
    }

    building* b = home();
    int speed_factor = (type() == FIGURE_CHARIOR_RACER ? 2 : 1);
    switch (action_state()) {
    case FIGURE_ACTION_150_ATTACK:
        base.figure_combat_handle_attack();
        //            figure_image_increase_offset(32);
        break;

    case FIGURE_ACTION_149_CORPSE:
        base.figure_combat_handle_corpse();
        break;

    case FIGURE_ACTION_90_ENTERTAINER_AT_SCHOOL_CREATED:
        base.anim.frame = 0;
        base.wait_ticks_missile = 0;
        wait_ticks--;
        if (wait_ticks <= 0) { // todo: summarize
            tile2i road_tile = map_closest_road_within_radius(b->tile, b->size, 2);
            if (road_tile.valid()) {
                base.action_state = FIGURE_ACTION_91_ENTERTAINER_EXITING_SCHOOL;
                base.set_cross_country_destination(road_tile);
                base.roam_length = 0;
            } else {
                poof();
            }
        }
        break;

    case FIGURE_ACTION_91_ENTERTAINER_EXITING_SCHOOL:
        base.use_cross_country = true;
        if (base.move_ticks_cross_country(1) == 1) {
            int dst_building_id = determine_venue_destination(tile(), allow_venue_types());

            if (dst_building_id) { // todo: summarize
                building* b_dst = building_get(dst_building_id);
                tile2i road_tile = map_closest_road_within_radius(b_dst->tile, b_dst->size, 2);
                if (road_tile.valid()) {
                    set_destination(dst_building_id);
                    advance_action(FIGURE_ACTION_92_ENTERTAINER_GOING_TO_VENUE);
                    destination_tile = road_tile;
                    base.roam_length = 0;
                } else {
                    advance_action(FIGURE_ACTION_93_ENTERTAINER_GOING_TO_RANDOM_ROAD);
                }
            } else {
                advance_action(FIGURE_ACTION_93_ENTERTAINER_GOING_TO_RANDOM_ROAD);
            }
        }
        break;

    case FIGURE_ACTION_93_ENTERTAINER_GOING_TO_RANDOM_ROAD:
        {
            int dst_building_id = determine_closest_venue_destination(tile(), allow_venue_types());
            if (dst_building_id) { // todo: summarize
                building* b_dst = building_get(dst_building_id);
                tile2i road_tile = map_closest_road_within_radius(b_dst->tile, b_dst->size, 2);
                if (road_tile.valid()) {
                    set_destination(dst_building_id);
                    advance_action(FIGURE_ACTION_92_ENTERTAINER_GOING_TO_VENUE);
                    destination_tile = road_tile;
                    base.roam_length = 0;
                } else {
                    advance_action(ACTION_11_RETURNING_EMPTY);
                }
            } else {
                advance_action(ACTION_11_RETURNING_EMPTY);
            }
        }
        break;

    case 10:
    case FIGURE_ACTION_92_ENTERTAINER_GOING_TO_VENUE:
        //            is_ghost = false;
        base.roam_length++;
        if (base.roam_length >= 3200) {
            poof();
        }

        if (do_gotobuilding(destination())) {
            building *b_dst = destination();
            int labores = b_dst ? model_get_building(b_dst->type)->laborers : 999;
            if (b_dst && b_dst->num_workers > labores / 2) {
                update_shows();
            } else {
                advance_action(ACTION_11_RETURNING_EMPTY);
            }
        }
        break;

    case 12:
        //        case ACTION_10_DELIVERING_FOOD:
    case FIGURE_ACTION_94_ENTERTAINER_ROAMING:
        do_roam(TERRAIN_USAGE_ROADS, ACTION_2_ROAMERS_RETURNING);
        break;

    case ACTION_11_RETURNING_EMPTY:
    case ACTION_13_RETURNING_TO_VENUE:
        //        case FIGURE_ACTION_95_ENTERTAINER_RETURNING:
        do_returnhome(TERRAIN_USAGE_ROADS);
        break;
    }
}

void figure_entertainer::update_animation() {
    int dir = figure_image_normalize_direction(direction() < 8 ? direction() : base.previous_tile_direction);

    //if (type() == FIGURE_CHARIOR_RACER) {
    //    base.cart_image_id = 0;
    //    if (action_state == FIGURE_ACTION_150_ATTACK || action_state == FIGURE_ACTION_149_CORPSE) {
    //        sprite_image_id = image_id_from_group(GROUP_FIGURE_CHARIOTEER) + dir;
    //    } else
    //        sprite_image_id = image_id_from_group(GROUP_FIGURE_CHARIOTEER) + dir + 8 * anim_frame;
    //    return;
    //}

    int image_id;
    if (type() == FIGURE_JUGGLER || type() == FIGURE_MUSICIAN) {
        image_id = anim("walk").first_img();
    } else if (type() == FIGURE_DANCER) {
        image_id = image_group(ANIM_DANCER_WALK);
        if (base.wait_ticks_missile >= 96) {
            image_id = image_id_from_group(GROUP_FIGURE_DANCER_WHIP);
        }

        base.cart_image_id = image_id_from_group(GROUP_FIGURE_LION);
    } else {
        return;
    }

    if (action_state() == FIGURE_ACTION_150_ATTACK) {
        if (type() == FIGURE_MUSICIAN)
            image_id = image_id + 104 + dir + 8 * (base.anim.frame / 2);
        else
            image_id = image_id + dir;
    } else if (action_state() == FIGURE_ACTION_149_CORPSE) {
        image_id = image_id + 96 + base.figure_image_corpse_offset();
        base.cart_image_id = 0;
    } else
        image_id = image_id + dir + 8 * base.anim.frame;
    if (base.cart_image_id) {
        base.cart_image_id += dir + 8 * base.anim.frame;
        base.figure_image_set_cart_offset(dir);
    }
}

building *figure_entertainer::current_destination() {
    if (action_state() == FIGURE_ACTION_94_ENTERTAINER_ROAMING
        || action_state() == FIGURE_ACTION_95_ENTERTAINER_RETURNING) {
        return home();
    }

    return destination();
}

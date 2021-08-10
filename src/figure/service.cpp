#include "service.h"

#include "building/building.h"
#include "building/model.h"
#include "core/config.h"
#include "figuretype/crime.h"
#include "game/resource.h"
#include "map/building.h"
#include "map/grid.h"

#define MAX_COVERAGE 96

static int provide_culture(int x, int y, void (*callback)(building *)) {
    int serviced = 0;
    int x_min, y_min, x_max, y_max;
    map_grid_get_area(x, y, 1, 2, &x_min, &y_min, &x_max, &y_max);
    for (int yy = y_min; yy <= y_max; yy++) {
        for (int xx = x_min; xx <= x_max; xx++) {
            int grid_offset = map_grid_offset(xx, yy);
            int building_id = map_building_at(grid_offset);
            if (building_id) {
                building *b = building_get(building_id);
                if (b->house_size && b->house_population > 0) {
                    callback(b);
                    serviced++;
                }
            }
        }
    }
    return serviced;
}
static int provide_entertainment(int x, int y, int shows, void (*callback)(building *, int)) {
    int serviced = 0;
    int x_min, y_min, x_max, y_max;
    map_grid_get_area(x, y, 1, 2, &x_min, &y_min, &x_max, &y_max);
    for (int yy = y_min; yy <= y_max; yy++) {
        for (int xx = x_min; xx <= x_max; xx++) {
            int grid_offset = map_grid_offset(xx, yy);
            int building_id = map_building_at(grid_offset);
            if (building_id) {
                building *b = building_get(building_id);
                if (b->house_size && b->house_population > 0) {
                    callback(b, shows);
                    serviced++;
                }
            }
        }
    }
    return serviced;
}
static int provide_missionary_coverage(int x, int y) {
    int x_min, y_min, x_max, y_max;
    map_grid_get_area(x, y, 1, 4, &x_min, &y_min, &x_max, &y_max);
    for (int yy = y_min; yy <= y_max; yy++) {
        for (int xx = x_min; xx <= x_max; xx++) {
            int building_id = map_building_at(map_grid_offset(xx, yy));
            if (building_id) {
                building *b = building_get(building_id);
                if (b->type == BUILDING_NATIVE_HUT || b->type == BUILDING_NATIVE_MEETING)
                    b->sentiment.native_anger = 0;

            }
        }
    }
    return 1;
}
static int provide_service(int x, int y, int *data, void (*callback)(building *, int *)) {
    int serviced = 0;
    int x_min, y_min, x_max, y_max;
    map_grid_get_area(x, y, 1, 2, &x_min, &y_min, &x_max, &y_max);
    for (int yy = y_min; yy <= y_max; yy++) {
        for (int xx = x_min; xx <= x_max; xx++) {
            int grid_offset = map_grid_offset(xx, yy);
            int building_id = map_building_at(grid_offset);
            if (building_id) {
                building *b = building_get(building_id);
                callback(b, data);
                if (b->house_size && b->house_population > 0)
                    serviced++;

            }
        }
    }
    return serviced;
}

static void theater_coverage(building *b) {
    b->data.house.theater = MAX_COVERAGE;
}
static void amphitheater_coverage(building *b, int shows) {
    b->data.house.amphitheater_actor = MAX_COVERAGE;
    if (shows == 2)
        b->data.house.amphitheater_gladiator = MAX_COVERAGE;

}
static void colosseum_coverage(building *b, int shows) {
    b->data.house.colosseum_gladiator = MAX_COVERAGE;
//    if (shows == 2)
//        b->data.house.magistrate = MAX_COVERAGE;
}
static void hippodrome_coverage(building *b) {
    b->data.house.hippodrome = MAX_COVERAGE;
}
static void magistrate_coverage(building *b) {
    b->data.house.magistrate = MAX_COVERAGE;
}
static void religion_coverage_ceres(building *b) {
    b->data.house.temple_ceres = MAX_COVERAGE;
}
static void religion_coverage_neptune(building *b) {
    b->data.house.temple_neptune = MAX_COVERAGE;
}
static void religion_coverage_mercury(building *b) {
    b->data.house.temple_mercury = MAX_COVERAGE;
}
static void religion_coverage_mars(building *b) {
    b->data.house.temple_mars = MAX_COVERAGE;
}
static void religion_coverage_venus(building *b) {
    b->data.house.temple_venus = MAX_COVERAGE;
}
static void school_coverage(building *b) {
    b->data.house.school = MAX_COVERAGE;
}
static void academy_coverage(building *b) {
    b->data.house.academy = MAX_COVERAGE;
}
static void library_coverage(building *b) {
    b->data.house.library = MAX_COVERAGE;
}
static void barber_coverage(building *b) {
    b->data.house.barber = MAX_COVERAGE;
}
static void clinic_coverage(building *b) {
    b->data.house.clinic = MAX_COVERAGE;
}
static void hospital_coverage(building *b) {
    b->data.house.hospital = MAX_COVERAGE;
}
static void water_supply_coverage(building *b) {
    b->data.house.bathhouse = MAX_COVERAGE;
}
static void engineer_coverage(building *b, int *max_damage_seen) {
    if (b->type == BUILDING_HIPPODROME || b->type == BUILDING_WAREHOUSE_SPACE)
        b = b->main();

    if (b->damage_risk > *max_damage_seen)
        *max_damage_seen = b->damage_risk;

    b->damage_risk = 0;
}
static void prefect_coverage(building *b, int *min_happiness_seen) {
    if (b->type == BUILDING_HIPPODROME || b->type == BUILDING_WAREHOUSE_SPACE)
        b = b->main();

    b->fire_risk = 0;
    if (b->sentiment.house_happiness < *min_happiness_seen)
        *min_happiness_seen = b->sentiment.house_happiness;

}
static void policeman_coverage(building *b, int *max_anger_seen) {
    b->house_criminal_active = 0;
    if (b->sentiment.native_anger > *max_anger_seen)
        *max_anger_seen = b->damage_risk;
}
static void tax_collector_coverage(building *b, int *max_tax_multiplier) {
    if (b->house_size && b->house_population > 0) {
        int tax_multiplier = model_get_house(b->subtype.house_level)->tax_multiplier;
        if (tax_multiplier > *max_tax_multiplier)
            *max_tax_multiplier = tax_multiplier;

        b->house_tax_coverage = 50;
    }
}
static void labor_seeker_coverage(building *b) {
    // nothing here, the labor seeker works simply via the `houses_covered` variable
}

static void distribute_good(building *b, building *market, int stock_wanted, int inventory_resource) {
    int amount_wanted = stock_wanted - b->data.house.inventory[inventory_resource];
    if (market->data.market.inventory[inventory_resource] > 0 && amount_wanted > 0) {
        if (amount_wanted <= market->data.market.inventory[inventory_resource]) {
            b->data.house.inventory[inventory_resource] += amount_wanted;
            market->data.market.inventory[inventory_resource] -= amount_wanted;
        } else {
            b->data.house.inventory[inventory_resource] += market->data.market.inventory[inventory_resource];
            market->data.market.inventory[inventory_resource] = 0;
        }
    }
}
static void distribute_market_resources(building *b, building *market) {
    int level = b->subtype.house_level;
    if (level < HOUSE_LUXURY_PALACE)
        level++;

    int max_food_stocks = 4 * b->house_highest_population;
    int food_types_stored_max = 0;
    for (int i = INVENTORY_MIN_FOOD; i < INVENTORY_MAX_FOOD; i++) {
        if (b->data.house.inventory[i] >= max_food_stocks)
            food_types_stored_max++;

    }
    const model_house *model = model_get_house(level);
    if (model->food_types > food_types_stored_max) {
        for (int i = INVENTORY_MIN_FOOD; i < INVENTORY_MAX_FOOD; i++) {
            if (b->data.house.inventory[i] >= max_food_stocks)
                continue;

            if (market->data.market.inventory[i] >= max_food_stocks) {
                b->data.house.inventory[i] += max_food_stocks;
                market->data.market.inventory[i] -= max_food_stocks;
                break;
            } else if (market->data.market.inventory[i]) {
                b->data.house.inventory[i] += market->data.market.inventory[i];
                market->data.market.inventory[i] = 0;
                break;
            }
        }
    }
    if (model->pottery) {
        market->data.market.pottery_demand = 10;
        distribute_good(b, market, 8 * model->pottery, INVENTORY_GOOD1);
    }
    int goods_no = 4;
    if (config_get(CONFIG_GP_CH_MORE_STOCKPILE))
        goods_no = 8;


    if (model->jewelry_furniture) {
        market->data.market.furniture_demand = 10;
        distribute_good(b, market, goods_no * model->jewelry_furniture, INVENTORY_GOOD2);
    }
    if (model->linen_oil) {
        market->data.market.oil_demand = 10;
        distribute_good(b, market, goods_no * model->linen_oil, INVENTORY_GOOD3);
    }
    if (model->beer_wine) {
        market->data.market.wine_demand = 10;
        distribute_good(b, market, goods_no * model->beer_wine, INVENTORY_GOOD4);
    }
}
static int provide_market_goods(building *market, int x, int y) {
    int serviced = 0;
//    building *market = building_get(market);
    int x_min, y_min, x_max, y_max;
    map_grid_get_area(x, y, 1, 2, &x_min, &y_min, &x_max, &y_max);
    for (int yy = y_min; yy <= y_max; yy++) {
        for (int xx = x_min; xx <= x_max; xx++) {
            int grid_offset = map_grid_offset(xx, yy);
            int building_id = map_building_at(grid_offset);
            if (building_id) {
                building *b = building_get(building_id);
                if (b->house_size && b->house_population > 0) {
                    distribute_market_resources(b, market);
                    serviced++;
                }
            }
        }
    }
    return serviced;
}

#include "game/tutorial.h"

building *figure::get_entertainment_building() {
    if (action_state == FIGURE_ACTION_94_ENTERTAINER_ROAMING ||
        action_state == FIGURE_ACTION_95_ENTERTAINER_RETURNING) {
        return home();
    } else { // going to venue
        return destination();
    }
}
int figure::figure_service_provide_coverage() {
    int houses_serviced = 0;
//    int x = x;
//    int y = y;
    building *b;
    switch (type) {
        case FIGURE_PATRICIAN:
            return 0;
        case FIGURE_LABOR_SEEKER:
            houses_serviced = provide_culture(tile_x, tile_y, labor_seeker_coverage);
            break;
        case FIGURE_TAX_COLLECTOR: {
            int max_tax_rate = 0;
            houses_serviced = provide_service(tile_x, tile_y, &max_tax_rate, tax_collector_coverage);
            min_max_seen = max_tax_rate;
            break;
        }
        case FIGURE_MARKET_TRADER:
            houses_serviced = provide_market_goods(home(), tile_x, tile_y);
            break;
        case FIGURE_MARKET_BUYER:
            if (!config_get(CONFIG_GP_CH_NO_BUYER_DISTRIBUTION))
                houses_serviced = provide_market_goods(home(), tile_x, tile_y);

            break;
//        case FIGURE_BATHHOUSE_WORKER:
//        case FIGURE_MAGISTRATE:
//            houses_serviced = provide_culture(tile_x, tile_y, magistrate_coverage);
//            break;
        case FIGURE_SCHOOL_CHILD:
            houses_serviced = provide_culture(tile_x, tile_y, school_coverage);
            break;
        case FIGURE_TEACHER:
            houses_serviced = provide_culture(tile_x, tile_y, academy_coverage);
            break;
        case FIGURE_LIBRARIAN:
            houses_serviced = provide_culture(tile_x, tile_y, library_coverage);
            break;
        case FIGURE_BARBER:
            houses_serviced = provide_culture(tile_x, tile_y, barber_coverage);
            break;
        case FIGURE_DOCTOR:
            houses_serviced = provide_culture(tile_x, tile_y, clinic_coverage);
            break;
        case FIGURE_SURGEON:
            houses_serviced = provide_culture(tile_x, tile_y, hospital_coverage);
            break;
        case FIGURE_WATER_CARRIER:
            houses_serviced = provide_culture(tile_x, tile_y, water_supply_coverage);
            break;
        case FIGURE_MISSIONARY:
            houses_serviced = provide_missionary_coverage(tile_x, tile_y);
            break;
        case FIGURE_PRIEST:
            tutorial_on_religion();
            switch (home()->type) {
                case BUILDING_SMALL_TEMPLE_CERES:
                case BUILDING_LARGE_TEMPLE_CERES:
                    houses_serviced = provide_culture(tile_x, tile_y, religion_coverage_ceres);
                    break;
                case BUILDING_SMALL_TEMPLE_NEPTUNE:
                case BUILDING_LARGE_TEMPLE_NEPTUNE:
                    houses_serviced = provide_culture(tile_x, tile_y, religion_coverage_neptune);
                    break;
                case BUILDING_SMALL_TEMPLE_MERCURY:
                case BUILDING_LARGE_TEMPLE_MERCURY:
                    houses_serviced = provide_culture(tile_x, tile_y, religion_coverage_mercury);
                    break;
                case BUILDING_SMALL_TEMPLE_MARS:
                case BUILDING_LARGE_TEMPLE_MARS:
                    houses_serviced = provide_culture(tile_x, tile_y, religion_coverage_mars);
                    break;
                case BUILDING_SMALL_TEMPLE_VENUS:
                case BUILDING_LARGE_TEMPLE_VENUS:
                    houses_serviced = provide_culture(tile_x, tile_y, religion_coverage_venus);
                    break;
                default:
                    break;
            }
            break;
        case FIGURE_ACTOR:
            b = get_entertainment_building();
            if (b->type == BUILDING_THEATER)
                houses_serviced = provide_culture(tile_x, tile_y, theater_coverage);
            else if (b->type == BUILDING_AMPHITHEATER) {
                houses_serviced = provide_entertainment(tile_x, tile_y,
                                                        b->data.entertainment.days1 ? 2 : 1, amphitheater_coverage);
            }
            break;
        case FIGURE_GLADIATOR:
            b = get_entertainment_building();
            if (b->type == BUILDING_AMPHITHEATER) {
                houses_serviced = provide_entertainment(tile_x, tile_y,
                                                        b->data.entertainment.days2 ? 2 : 1, amphitheater_coverage);
            } else if (b->type == BUILDING_COLOSSEUM) {
                houses_serviced = provide_entertainment(tile_x, tile_y,
                                                        b->data.entertainment.days1 ? 2 : 1, colosseum_coverage);
            }
            break;
        case FIGURE_LION_TAMER:
            b = get_entertainment_building();
            houses_serviced = provide_entertainment(tile_x, tile_y,
                                                    b->data.entertainment.days2 ? 2 : 1, colosseum_coverage);
            break;
        case FIGURE_CHARIOTEER:
            houses_serviced = provide_culture(tile_x, tile_y, hippodrome_coverage);
            break;
        case FIGURE_ENGINEER: {
            int max_damage = 0;
            houses_serviced = provide_service(tile_x, tile_y, &max_damage, engineer_coverage);
            if (max_damage > min_max_seen)
                min_max_seen = max_damage;
            else if (min_max_seen <= 10)
                min_max_seen = 0;
            else
                min_max_seen -= 10;
            break;
        }
        case FIGURE_PREFECT: {
            int min_happiness = 100;
            houses_serviced = provide_service(tile_x, tile_y, &min_happiness, prefect_coverage);
            min_max_seen = min_happiness;
            break;
        }
        case FIGURE_RIOTER:
            if (figure_rioter_collapse_building() == 1)
                return 1;
            break;
        case FIGURE_POLICEMAN:
        case FIGURE_MAGISTRATE:
            int max_anger = 0;
            houses_serviced = provide_service(tile_x, tile_y, &max_anger, policeman_coverage);
            if (type == FIGURE_MAGISTRATE)
                houses_serviced = provide_culture(tile_x, tile_y, magistrate_coverage);
            if (max_anger > min_max_seen)
                min_max_seen = max_anger;
            else if (min_max_seen <= 10)
                min_max_seen = 0;
            else
                min_max_seen -= 10;
            break;
    }
    if (has_home()) {
        b = home()->main();
        b->houses_covered += houses_serviced;
        if (b->houses_covered >= 300)
            b->houses_covered = 300;
    }
    return 0;
}

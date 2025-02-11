#include "animal_hippo.h"

#include "js/js_game.h"
#include "core/profiler.h"
#include "grid/terrain.h"
#include "city/city.h"
#include "core/random.h"

figures::model_t<figure_hippo> hippo_m;

ANK_REGISTER_CONFIG_ITERATOR(config_load_figure_hippo);
void config_load_figure_hippo() {
    hippo_m.load();
}

void figure_hippo::figure_action() {
    OZZY_PROFILER_SECTION("Game/Run/Tick/Figure/Hippo");
    const formation* m = formation_get(base.formation_id);
    g_city.figures_add_animal();

    base.allow_move_type = EMOVE_HIPPO;
    base.roam_wander_freely = false;

    switch (action_state()) {
    case FIGURE_ACTION_24_HIPPO_CREATED: // spawning
    case 14: // scared
    case 15: // terrified
    case 18: // roosting
    case FIGURE_ACTION_19_HIPPO_IDLE: // idle
    case FIGURE_ACTION_196_HERD_ANIMAL_AT_REST:
        wait_ticks--;
        //            if (wait_ticks % 5 == 0 && is_nearby(NEARBY_ANY, 6))
        //                advance_action(ACTION_16_FLEEING);
        if (wait_ticks <= 0) {
            advance_action(ACTION_8_RECALCULATE);
        }
        break;

    case 199:
    case ACTION_8_RECALCULATE:
        wait_ticks--;
        if (wait_ticks <= 0) {
            if (base.herd_roost(/*step*/4, /*bias*/8, /*max_dist*/32, TERRAIN_IMPASSABLE_HIPPO)) {
                wait_ticks = 0;
                advance_action(FIGURE_ACTION_10_HIPPO_MOVING);
                do_goto(destination_tile, TERRAIN_USAGE_ANY, 18 + (random_byte() & 0x1), ACTION_8_RECALCULATE);
            } else {
                wait_ticks = 5;
            }
        }
        break;

    case 16: // fleeing
    case FIGURE_ACTION_10_HIPPO_MOVING:
    case FIGURE_ACTION_197_HERD_ANIMAL_MOVING:
        //            if (action_state == 16)
        //                while (destination_x == 0 || destination_y == 0)
        //                    herd_roost(4, 8, 22);
        if (do_goto(destination_tile, TERRAIN_USAGE_ANY, 18 + (random_byte() & 0x1), ACTION_8_RECALCULATE)) {
            wait_ticks = 50;
        }
        break;
    }
}

void figure_hippo::update_animation() {
    pcstr anim_key = "walk";
    switch (action_state()) {
    case ACTION_8_RECALCULATE:
    case FIGURE_ACTION_19_HIPPO_IDLE: anim_key ="idle"; break;
    case 18: anim_key ="eating"; break;

    case 16: // fleeing
    case FIGURE_ACTION_10_HIPPO_MOVING: // on the move
        anim_key ="walk"; break;
        break;

    case 15: // terrified
    case 14: // scared
        anim_key ="eating";
        base.anim.frame = 0;
        break;

    case FIGURE_ACTION_149_CORPSE:
        anim_key ="death";
        break;

    case FIGURE_ACTION_150_ATTACK: // unused?
        anim_key ="attack";
        break;

    default:
        anim_key ="eating";
        break;
    }

    image_set_animation(anim_key);
}

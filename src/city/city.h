#pragma once

#include <stdint.h>

#include "city/kingdome.h"
#include "city/entertainment.h"
#include "city/finance.h"
#include "city/houses.h"
#include "city/labor.h"
#include "city/health.h"
#include "city/military.h"
#include "city/resource.h"
#include "city/map.h"
#include "city/gods.h"
#include "city/victory.h"
#include "city/ratings.h"
#include "grid/point.h"
#include "grid/desirability.h"

struct empire_city;

struct city_t {
    struct {
        bool palace_placed;
        int32_t palace_building_id;
        tile2i palace_point;

        int32_t festival_building_id;
        tile2i festival_square;

        bool mansion_placed;
        int32_t mansion_building_id;
        tile2i mansion;

        int32_t senet_house_placed;

        struct {
            bool placed;
            int32_t building_id;
            tile2i tile;
        } recruiter;

        bool distribution_center_placed;
        int32_t distribution_center_building_id;
        tile2i distribution_center;

        int32_t trade_center_building_id;
        int8_t triumphal_arches_available;
        int8_t triumphal_arches_placed;
        int16_t working_wharfs;
        int32_t shipyard_boats_requested;
        int16_t working_docks;
        int16_t working_dock_ids[10];
        int16_t working_shipyards;
        int32_t mission_post_operational;
        tile2i main_native_meeting;
        int8_t unknown_value;

        bool temple_complex_placed;
        int32_t temple_complex_id;
    } buildings;

    struct {
        uint8_t fish_number;
        uint8_t animals_number;
        int32_t attacking_natives;
        int32_t enemies;
        int32_t kingdome_soldiers;
        int32_t rioters;
        int32_t soldiers;
        int32_t security_breach_duration;
    } figures;

    house_demands houses;
    desirability_t desirability;
    kingdome_relation_t kingdome;
    city_military_t military;
    vistory_state_t victory_state;
    struct {
        uint8_t city;
        int8_t city_foreign_months_left;
        int8_t total_count;
        int8_t won_count;
        uint8_t enemy_strength;
        uint8_t roman_strength;
        int8_t months_until_battle;
        int8_t roman_months_to_travel_forth;
        int8_t roman_months_to_travel_back;
        int8_t enemy_months_traveled;
        int8_t roman_months_traveled;
    } distant_battle;
    struct {
        int32_t treasury;
        int32_t tax_percentage;
        int32_t estimated_tax_uncollected;
        int32_t estimated_tax_income;
        int32_t estimated_wages;
        finance_overview last_year;
        finance_overview this_year;
        int32_t interest_so_far;
        int32_t salary_so_far;
        int32_t wages_so_far;
        int16_t stolen_this_year;
        int16_t stolen_last_year;
        int32_t cheated_money;
        int32_t tribute_not_paid_last_year;
        int32_t tribute_not_paid_total_years;
        int32_t wage_rate_paid_this_year;
        int32_t wage_rate_paid_last_year;
    } finance;
    struct {
        int32_t taxed_citizens;
        int32_t taxed_nobles;
        int32_t untaxed_citizens;
        int32_t untaxed_nobles;
        int32_t percentage_taxed_citizens;
        int32_t percentage_taxed_nobles;
        int32_t percentage_taxed_people;
        struct {
            int32_t collected_citizens;
            int32_t collected_nobles;
            int32_t uncollected_citizens;
            int32_t uncollected_nobles;
        } yearly;
        struct {
            int32_t collected_citizens;
            int32_t collected_nobles;
            int32_t uncollected_citizens;
            int32_t uncollected_nobles;
        } monthly;
    } taxes;

    struct {
        int32_t population;
        int32_t population_last_year;
        int32_t school_age;
        int32_t academy_age;
        int32_t working_age;
        struct {
            int32_t values[2400];
            int32_t next_index;
            int32_t count;
        } monthly;
        int16_t at_age[100];
        int32_t at_level[20];

        int32_t yearly_update_requested;
        int32_t yearly_births;
        int32_t yearly_deaths;
        int32_t lost_removal;
        int32_t lost_homeless;
        int32_t lost_troop_request;
        int32_t last_change;
        int32_t total_all_years;
        int32_t total_years;
        int32_t average_per_year;
        int32_t highest_ever;
        int32_t total_capacity;
        int32_t room_in_houses;

        int32_t people_in_huts;
        int32_t people_in_shanties;
        int32_t people_in_residences;
        int32_t people_in_manors;
        int32_t percentage_plebs;

        int32_t last_used_house_add;
        int32_t last_used_house_remove;
        int32_t graph_order;
    } population;
    city_labor_t labor;
    struct {
        int32_t immigration_duration;
        int32_t emigration_duration;
        int32_t immigration_amount_per_batch;
        int32_t emigration_amount_per_batch;
        int32_t immigration_queue_size;
        int32_t emigration_queue_size;
        int32_t immigrated_today;
        int32_t emigrated_today;
        int32_t refused_immigrants_today;
        int32_t no_immigration_cause;
        int32_t percentage;
        int32_t newcomers;
        int32_t emigration_message_shown;
        int32_t percentage_by_sentiment;
        uint16_t nobles_leave_city_this_year;
        bool migration_cap;
        bool invading_cap;
    } migration;
    struct {
        int32_t value;
        int32_t previous_value;
        int32_t message_delay;

        bool include_huts;
        int32_t unemployment;
        int32_t wages;
        int32_t low_mood_cause;

        int32_t protesters;
        int32_t criminals; // muggers+rioters
        bool can_create_mugger;
        bool can_create_protestor;
        short last_mugger_message;
        int32_t contribution_taxes;
        int32_t contribution_wages;
        int32_t contribution_employment;
        int32_t penalty_tents;
        int32_t religion_coverage;
        int32_t monuments;
    } sentiment;
    city_health_t health;
    city_ratings_t ratings;
    struct {
        int32_t average_entertainment;
        int32_t average_religion;
        int32_t average_education;
        int32_t average_health;
        int32_t religion_coverage;
    } culture;
    struct {
        god_state gods[MAX_GODS];
        int32_t least_happy_god;
        int32_t angry_message_delay;
        bool bast_curse_active;
        int32_t ra_150_export_profits_months_left;
        int32_t ra_harshly_reduced_trading_months_left;
        int32_t ra_no_traders_months_left;
        int32_t ra_slightly_reduced_trading_months_left;
        int32_t ra_slightly_increased_trading_months_left;
        int32_t osiris_sank_ships;
        int32_t seth_crush_enemy_troops;
        int32_t seth_protect_player_troops;
        bool osiris_double_farm_yield;
        int32_t osiris_flood_will_destroy_active;
    } religion;
    city_entertainment_t entertainment;
    struct {
        struct {
            int32_t months_to_go;
            int32_t god;
            int32_t size;
        } planned;
        struct {
            int32_t god;
            int32_t size;
        } selected;
        int32_t small_cost;
        int32_t large_cost;
        int32_t grand_cost;
        int32_t grand_alcohol;
        int32_t not_enough_alcohol;

        int32_t months_since_festival;
        int32_t first_festival_effect_months;
        int32_t second_festival_effect_months;
    } festival;
    struct {
        int16_t space_in_warehouses[RESOURCES_MAX];
        int16_t stored_in_warehouses[RESOURCES_MAX];
        //        int32_t space_in_workshops[6];
        //        int32_t stored_in_workshops[6];
        int16_t trade_status[RESOURCES_MAX];
        int16_t trading_amount[RESOURCES_MAX];
        int32_t stockpiled[RESOURCES_MAX];
        int16_t mothballed[RESOURCES_MAX];
        int16_t unk_00[RESOURCES_MAX];

        int32_t wine_types_available;
        //        int32_t food_types_available;
        //        int32_t food_types_eaten;
        int8_t food_types_available_arr[RESOURCES_FOODS_MAX];
        int8_t food_types_eaten_arr[RESOURCES_FOODS_MAX];
        int8_t food_types_allowed[4];
        int32_t food_types_available_num;
        int32_t food_types_eaten_num;
        int32_t granary_food_stored[RESOURCES_FOODS_MAX];
        int32_t granary_total_stored;
        int32_t food_supply_months;
        int32_t food_needed_per_month;
        int32_t food_consumed_last_month;
        int32_t food_produced_last_month;
        int32_t food_produced_this_month;
        int8_t food_types_arr_unk_00[RESOURCES_FOODS_MAX];
        int8_t food_types_arr_unk_01[RESOURCES_FOODS_MAX];
        struct {
            int operating;
            int not_operating;
            int not_operating_with_food;
            int understaffed;
        } granaries;
        int16_t last_used_warehouse;
    } resource;
    struct {
        int8_t march_enemy;
        int8_t march_horse;
        int8_t march_wolf;
        int8_t shoot_arrow;
        int8_t hit_soldier;
        int8_t hit_spear;
        int8_t hit_club;
        int8_t hit_elephant;
        int8_t hit_axe;
        int8_t hit_wolf;
        int8_t die_citizen;
        int8_t die_soldier;
    } sound;
    struct {
        int16_t num_land_routes;
        int16_t num_sea_routes;
        int16_t land_trade_problem_duration;
        int16_t sea_trade_problem_duration;
        e_resource caravan_import_resource;
        e_resource caravan_backup_import_resource;
        e_resource docker_import_resource;
        e_resource docker_export_resource;
    } trade;
    city_map_t map;
    struct {
        int32_t has_won;
        int32_t continue_months_left;
        int32_t continue_months_chosen;
        int32_t fired_message_shown;
        int32_t victory_message_shown;
        int32_t start_saved_game_written;
        int32_t tutorial_fire_message_shown;
        int32_t tutorial_disease_message_shown;
        int32_t tutorial_senate_built;
    } mission;

    struct {
        int8_t other_player[18904];
        int8_t unknown_00a0;
        int8_t unknown_00a1;
        int8_t unknown_00a2;
        int8_t unknown_00a3;
        int8_t unknown_00a4;
        int8_t unknown_00a6;
        int8_t unknown_00a7;
        int32_t unknown_00c0;
        int32_t unused_27d0;
        uint16_t unused_27d0_short;
        int32_t unknown_27e0[3];
        int16_t unknown_27f0;
        int16_t unknown_27f4[18];
        int16_t unknown_2828;
        int16_t unused_28ca;
        int8_t unknown_2924[272];
        int32_t unknown_2b6c;
        int32_t unknown_2c20[1400];
        int32_t houses_requiring_unknown_to_evolve[8];
        int32_t unknown_4238[4];
        int32_t unknown_4284;
        int32_t unknown_4294[2];
        int32_t unknown_4334;
        int32_t unknown_4374[2];
        int16_t unknown_439c[3];
        int8_t padding_43b2[2];
        int32_t unknown_43d8[5];
        int32_t unknown_43f0;
        int32_t unused_4454;
        int32_t unknown_446c[4];
        int32_t unused_4488;
        int32_t unused_native_force_attack;
        int32_t unused_44e0[2];
        int32_t unused_44ec;
        int32_t unused_44f8;
        int32_t unused_4524[11];
        uint8_t unknown_458e;
        int8_t unused_45a5[6];
        int8_t unknown_464c[232];
        int32_t unknown_order;
        int32_t faction_id;
        int16_t faction_bytes[2];
    } unused;

    struct fishing_points_t {
        void create();
        void reset();
        void clear();
        void update(int points_num);
    } fishing_points;

    struct environment_t {
        void river_update_flotsam();
    } environment;

    void houses_reset_demands();
    void houses_calculate_culture_demands();

    void migration_nobles_leave_city(int num_people);

    void init();
    void init_custom_map();
    void init_campaign_mission();
    int allowed_foods(int i);
    void set_allowed_food(int i, int resource);

    bool generate_trader_from(int city_id, empire_city &city);
    bool available_resource(e_resource resource);
    void update_allowed_resources();
    bool can_produce_resource(e_resource resource);
    void set_produce_resource(e_resource resource, bool v);

    void migration_update_status();
    void create_immigrants(int num_people);
    void create_emigrants(int num_people);
    void create_migrants();
    void migration_update();
    void migration_determine_reason();
    int migration_problems_cause() { return migration.no_immigration_cause; }
    void migration_advance_year() { migration.nobles_leave_city_this_year = 0; }
    int migration_no_room_for_immigrants();
    int migration_percentage() { return migration.percentage; }
    int migration_newcomers() { return migration.newcomers; }
    void migration_reset_newcomers() { migration.newcomers = 0; }

    void figures_reset();
    void figures_add_animal();
    void figures_add_attacking_native();
    void figures_add_enemy();
    void figures_add_kingdome_soldier();
    void figures_add_rioter(int is_attacking);
    void figures_add_soldier();
    void figures_update_day();
    int figures_total_invading_enemies();
    bool figures_has_security_breach();

    void update_prosperity_explanation();
    bool has_made_money();
    void update_prosperity_rating();
    void calculate_max_prosperity();
    void ratings_update_explanations();
    void ratings_update(bool is_yearly_update);

    bool determine_granary_get_foods(resource_foods &foods, int road_network);

    e_victory_state determine_victory_state();
    void victory_check();
};

const uint8_t* city_player_name();
void city_set_player_name(const uint8_t* name);
void city_save_campaign_player_name();
void city_restore_campaign_player_name();

extern city_t g_city;

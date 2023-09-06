#ifndef CITY_WARNING_H
#define CITY_WARNING_H

#include <stdint.h>

enum {
    WARNING_ORIENTATION = 1,
    WARNING_CLEAR_LAND_NEEDED = 2,
    WARNING_OUT_OF_MONEY = 3,
    WARNING_ONE_BUILDING_OF_TYPE = 4,
    WARNING_ROAD_ACCESS_NEEDED = 11,
    WARNING_NOT_AVAILABLE = 13,
    WARNING_NOT_AVAILABLE_YET = 14,
    WARNING_MARBLE_NEEDED_LARGE_TEMPLE = 15,
    WARNING_MARBLE_NEEDED_ORACLE = 16,
    WARNING_WORKERS_NEEDED = 17,
    WARNING_MORE_FOOD_NEEDED = 18,
    WARNING_BUILD_MARKET = 19,
    WARNING_MEADOW_NEEDED = 20,
    WARNING_WATER_NEEDED = 21,
    WARNING_ROCK_NEEDED = 22,
    WARNING_TREE_NEEDED = 23,
    WARNING_SHORE_NEEDED = 25,
    WARNING_IRON_NEEDED = 26,
    WARNING_VINES_NEEDED = 27,
    WARNING_OLIVES_NEEDED = 28,
    WARNING_CLAY_NEEDED = 29,
    WARNING_TIMBER_NEEDED = 30,
    WARNING_OPEN_TRADE_TO_IMPORT = 31,
    WARNING_TRADE_IMPORT_RESOURCE = 32,
    WARNING_BUILD_IRON_MINE = 33,
    WARNING_BUILD_VINES_FARM = 34,
    WARNING_BUILD_OLIVE_FARM = 35,
    WARNING_BUILD_CLAY_PIT = 36,
    WARNING_BUILD_TIMBER_YARD = 37,
    WARNING_WATER_PIPE_ACCESS_NEEDED = 38,
    WARNING_PLACE_RESERVOIR_NEXT_TO_WATER = 39,
    WARNING_CONNECT_TO_RESERVOIR = 40,
    WARNING_SENTRIES_NEED_WALL = 41,
    WARNING_BUILD_BARRACKS = 42,
    WARNING_WEAPONS_NEEDED = 43,
    WARNING_BUILD_ACTOR_COLONY = 44,
    WARNING_BUILD_GLADIATOR_SCHOOL = 45,
    WARNING_BUILD_DANCERS_SCHOOL = 46,
    WARNING_BUILD_CHARIOT_MAKER = 47,
    WARNING_WALL_NEEDED = 49,
    WARNING_ENEMY_NEARBY = 50,
    WARNING_LEGION_MORALE_TOO_LOW = 51,
    WARNING_MAX_LEGIONS_REACHED = 52,
    WARNING_PEOPLE_ON_BRIDGE = 55,
    WARNING_DOCK_OPEN_WATER_NEEDED = 56,
    WARNING_EDITOR_NEED_MAP_EDGE = 58,
    WARNING_EDITOR_NEED_OPEN_WATER = 59,
    WARNING_EDITOR_CANNOT_PLACE = 60,
    WARNING_EDITOR_NO_EARTHQUAKE_SCHEDULED = 61,
    WARNING_HERD_BREEDING_GROUNDS = 61,
    WARNING_HOUSE_TOO_FAR_FROM_ROAD = 62,
    WARNING_CITY_BOXED_IN = 63,
    WARNING_CITY_BOXED_IN_PEOPLE_WILL_PERISH = 64,
    WARNING_DATA_LIMIT_REACHED = 65,
    //
    WARNING_ROADBLOCKS_ROAD_NEEDED = 66,
    WARNING_FERRY_PLACE_OTHER_ONE = 67,
    WARNING_FERRY_INVALID_SPOT = 68,

    WARNING_TEMPLE_COMPLEX_MISSING = 73,
    WARNING_TEMPLE_UPGRADE_ONLY_ONE = 74,
    WARNING_TEMPLE_UPGRADE_PLACEMENT_NEED_TEMPLE = 75,

    WARNING_GROUNDWATER_NEEDED = 76,
    WARNING_BOOTH_ROAD_INTERSECTION_NEEDED = 77,
    WARNING_NEED_COMPLETED_TEMPLE = 78,
    WARNING_500_PAPYRUS_NEEDED = 79,
    WARNING_NEED_REEDS = 80,
    WARNING_NEED_REEDS_2 = 81,
    WARNING_NEED_STRAW = 82,
    WARNING_NEED_STRAW_2 = 83,
    WARNING_WARSHIP_FULL = 84,
    WARNING_100_GRANITE_OBELISK_NEEDED = 85,
    WARNING_200_GRANITE_OBELISK_NEEDED = 86,
    WARNING_SOME_MONUMENTS_NO_LONGER_AVAILABLE = 87,
    WARNING_OBELISK_ONLY_ONE = 88,
    WARNING_TAXES_PALACE_NEEDED = 89,
    WARNING_220_SANDSTONE_SUNTEMPLE_NEEDED = 90,
    WARNING_SUNTEMPLE_ONLY_ONE = 91,
    WARNING_TOO_FEW_JOBS = 92,
    WARNING_FOOD_LEVELS_LOW = 93,
    WARNING_EATING_MORE_THAN_PRODUCED = 94,

    WARNING_PALACE_ROBBED = 102,
    WARNING_MANSION_ROBBED = 103,
    WARNING_NO_TROOPS = 104,

    WARNING_FESTIVAL_ROAD_INTERSECTION_NEEDED = 215,
};

void city_warning_show(int type);
void city_warning_show_custom(const char *text);

int city_has_warnings(void);

const uint8_t* city_warning_get(int id);

void city_warning_clear_all(void);
void city_warning_clear_outdated(void);

void city_warning_show_console(uint8_t* warning_text);

#endif // CITY_WARNING_H

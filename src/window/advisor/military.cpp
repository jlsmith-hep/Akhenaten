#include "military.h"

#include "city/city.h"
#include "city/military.h"
#include "figure/formation_legion.h"
#include "graphics/image.h"
#include "graphics/graphics.h"
#include "graphics/elements/generic_button.h"
#include "graphics/elements/lang_text.h"
#include "graphics/elements/panel.h"
#include "graphics/elements/scrollbar.h"
#include "graphics/text.h"
#include "graphics/view/view.h"
#include "graphics/window.h"
#include "grid/grid.h"
#include "scenario/invasion.h"
#include "window/window_city.h"
#include "game/game.h"

#define ADVISOR_HEIGHT 26

ui::advisor_miliary_window g_advisor_military_window;

static void button_go_to_legion(int legion_id, int param2);
static void button_return_to_fort(int legion_id, int param2);
static void button_empire_service(int legion_id, int param2);
static void on_scroll();

static scrollbar_t g_advisor_mil_scrollbar = {{592, 70}, 272, on_scroll};

static generic_button fort_buttons[] = {
  {384, 83, 30, 30, button_go_to_legion, button_none, 1, 0},
  {464, 83, 30, 30, button_return_to_fort, button_none, 1, 0},
  {544, 83, 30, 30, button_empire_service, button_none, 1, 0},
  {384, 127, 30, 30, button_go_to_legion, button_none, 2, 0},
  {464, 127, 30, 30, button_return_to_fort, button_none, 2, 0},
  {544, 127, 30, 30, button_empire_service, button_none, 2, 0},
  {384, 171, 30, 30, button_go_to_legion, button_none, 3, 0},
  {464, 171, 30, 30, button_return_to_fort, button_none, 3, 0},
  {544, 171, 30, 30, button_empire_service, button_none, 3, 0},
  {384, 215, 30, 30, button_go_to_legion, button_none, 4, 0},
  {464, 215, 30, 30, button_return_to_fort, button_none, 4, 0},
  {544, 215, 30, 30, button_empire_service, button_none, 4, 0},
  {384, 259, 30, 30, button_go_to_legion, button_none, 5, 0},
  {464, 259, 30, 30, button_return_to_fort, button_none, 5, 0},
  {544, 259, 30, 30, button_empire_service, button_none, 5, 0},
  {384, 303, 30, 30, button_go_to_legion, button_none, 6, 0},
  {464, 303, 30, 30, button_return_to_fort, button_none, 6, 0},
  {544, 303, 30, 30, button_empire_service, button_none, 6, 0},
};

static int focus_button_id;
static int num_legions;

void ui::advisor_miliary_window::init() {
    num_legions = formation_get_num_forts();
    g_advisor_mil_scrollbar.init(0, num_legions - 6);
}

int ui::advisor_miliary_window::draw_background() {
    painter ctx = game.painter();
    outer_panel_draw(vec2i{0, 0}, 40, ADVISOR_HEIGHT);
    ImageDraw::img_generic(ctx, image_id_from_group(GROUP_ADVISOR_ICONS) + 1, vec2i{10, 10});
    lang_text_draw(51, 0, 60, 12, FONT_LARGE_BLACK_ON_LIGHT);

    lang_text_draw(51, 1, 374, 43, FONT_SMALL_PLAIN);
    lang_text_draw(51, 2, 374, 58, FONT_SMALL_PLAIN);
    lang_text_draw(51, 3, 454, 43, FONT_SMALL_PLAIN);
    lang_text_draw(51, 4, 454, 58, FONT_SMALL_PLAIN);
    lang_text_draw(51, 5, 534, 43, FONT_SMALL_PLAIN);
    lang_text_draw(51, 6, 534, 58, FONT_SMALL_PLAIN);
    lang_text_draw(138, 36, 274, 58, FONT_SMALL_PLAIN);

    int enemy_text_id;
    if (g_city.figures.enemies)
        enemy_text_id = 10;
    else if (g_city.figures.kingdome_soldiers)
        enemy_text_id = 11;
    else if (scenario_invasion_exists_upcoming())
        enemy_text_id = 9;
    else {
        enemy_text_id = 8;
    }
    int distant_battle_text_id;
    if (city_military_distant_battle_kingdome_army_is_traveling_back())
        distant_battle_text_id = 15;
    else if (city_military_distant_battle_kingdome_army_is_traveling_forth())
        distant_battle_text_id = 14;
    else if (city_military_months_until_distant_battle() > 0)
        distant_battle_text_id = 13;
    else {
        distant_battle_text_id = 12;
    }
    int bullet_x = 60;
    int text_x = 80;
    image_desc group_bullet{PACK_GENERAL, 158};
    if (num_legions <= 0) {
        ImageDraw::img_generic(ctx, image_group(group_bullet), vec2i{bullet_x, 359});
        lang_text_draw(51, enemy_text_id, text_x, 358, FONT_NORMAL_BLACK_ON_LIGHT);

        ImageDraw::img_generic(ctx, image_group(group_bullet), vec2i{bullet_x, 379});
        lang_text_draw(51, distant_battle_text_id, text_x, 378, FONT_NORMAL_BLACK_ON_LIGHT);
    } else {
        // has forts
        ImageDraw::img_generic(ctx, image_group(group_bullet), vec2i{bullet_x, 349});
        int width = lang_text_draw_amount(8, 46, g_city.military.total_soldiers, text_x, 348, FONT_NORMAL_BLACK_ON_LIGHT);
        width += lang_text_draw(51, 7, text_x + width, 348, FONT_NORMAL_BLACK_ON_LIGHT);
        lang_text_draw_amount(8, 48, g_city.military.total_batalions, text_x + width, 348, FONT_NORMAL_BLACK_ON_LIGHT);

        ImageDraw::img_generic(ctx, image_group(group_bullet), vec2i{bullet_x, 369});
        lang_text_draw(51, enemy_text_id, text_x, 368, FONT_NORMAL_BLACK_ON_LIGHT);

        ImageDraw::img_generic(ctx, image_group(group_bullet), vec2i{bullet_x, 389});
        lang_text_draw(51, distant_battle_text_id, text_x, 388, FONT_NORMAL_BLACK_ON_LIGHT);
    }

    inner_panel_draw(16, 70, 36, 17);
    if (num_legions <= 0) {
        lang_text_draw_multiline(51, 16, vec2i{64, 200}, 496, FONT_NORMAL_BLACK_ON_DARK);
        return ADVISOR_HEIGHT;
    }
    for (int i = 0; i < 6 && i < num_legions; i++) {
        const formation* m = formation_get(formation_for_legion(i + 1 + g_advisor_mil_scrollbar.scroll_position));
        button_border_draw(22, 77 + 44 * i, 560, 40, 0);
        ImageDraw::img_generic(ctx, image_id_from_group(GROUP_FIGURE_FORT_STANDARD_ICONS) + m->legion_id, vec2i{32, 82 + 44 * i});
        lang_text_draw(138, m->legion_id, 84, 83 + 44 * i, FONT_NORMAL_WHITE_ON_DARK);
        int width = text_draw_number(m->num_figures, '@', " ", 84, 100 + 44 * i, FONT_NORMAL_BLACK_ON_DARK);
        switch (m->figure_type) {
        case FIGURE_INFANTRY:
            lang_text_draw(138, 33, 84 + width, 100 + 44 * i, FONT_NORMAL_BLACK_ON_DARK);
            break;
        case FIGURE_FCHARIOTEER:
            lang_text_draw(138, 34, 84 + width, 100 + 44 * i, FONT_NORMAL_BLACK_ON_DARK);
            break;
        case FIGURE_ARCHER:
            lang_text_draw(138, 35, 84 + width, 100 + 44 * i, FONT_NORMAL_BLACK_ON_DARK);
            break;
        }
        lang_text_draw_centered(138, 37 + m->morale / 5, 224, 91 + 44 * i, 150, FONT_NORMAL_BLACK_ON_DARK);

        int image_id = image_id_from_group(GROUP_FORT_ICONS);
        button_border_draw(384, 83 + 44 * i, 30, 30, 0);
        ImageDraw::img_generic(ctx, image_id, vec2i{387, 86 + 44 * i});

        button_border_draw(464, 83 + 44 * i, 30, 30, 0);
        if (m->is_at_fort)
            ImageDraw::img_generic(ctx, image_id + 2, vec2i{467, 86 + 44 * i});
        else {
            ImageDraw::img_generic(ctx, image_id + 1, vec2i{467, 86 + 44 * i});
        }

        button_border_draw(544, 83 + 44 * i, 30, 30, 0);
        if (m->empire_service)
            ImageDraw::img_generic(ctx, image_id + 3, vec2i{547, 86 + 44 * i});
        else {
            ImageDraw::img_generic(ctx, image_id + 4, vec2i{547, 86 + 44 * i});
        }
    }

    return ADVISOR_HEIGHT;
}

void ui::advisor_miliary_window::draw_foreground() {
    scrollbar_draw(&g_advisor_mil_scrollbar);
    num_legions = formation_get_num_forts();
    for (int i = 0; i < 6 && i < num_legions; i++) {
        button_border_draw(384, 83 + 44 * i, 30, 30, focus_button_id == 3 * i + 1);
        button_border_draw(464, 83 + 44 * i, 30, 30, focus_button_id == 3 * i + 2);
        button_border_draw(544, 83 + 44 * i, 30, 30, focus_button_id == 3 * i + 3);
    }
}

int ui::advisor_miliary_window::handle_mouse(const mouse* m) {
    if (scrollbar_handle_mouse(&g_advisor_mil_scrollbar, m))
        return 1;

    return generic_buttons_handle_mouse(m, 0, 0, fort_buttons, 3 * num_legions, &focus_button_id);
}

static void button_go_to_legion(int legion_id, int param2) {
    const formation* m = formation_get(formation_for_legion(legion_id + g_advisor_mil_scrollbar.scroll_position));
    camera_go_to_mappoint(m->home);
    window_city_show();
}

static void button_return_to_fort(int legion_id, int param2) {
    formation* m = formation_get(formation_for_legion(legion_id + g_advisor_mil_scrollbar.scroll_position));
    if (!m->in_distant_battle) {
        formation_legion_return_home(m);
        window_invalidate();
    }
}

static void button_empire_service(int legion_id, int param2) {
    int formation_id = formation_for_legion(legion_id + g_advisor_mil_scrollbar.scroll_position);
    formation_toggle_empire_service(formation_id);
    formation_calculate_figures();
    window_invalidate();
}

static void on_scroll(void) {
    window_invalidate();
}

advisor_window* ui::advisor_miliary_window::instance() {
    return &g_advisor_military_window;
}

#pragma once

#include "button.h"
#include "input/mouse.h"

struct generic_button {
    short x;
    short y;
    short width;
    short height;
    void (*left_click_handler)(int param1, int param2);
    void (*right_click_handler)(int param1, int param2);
    int parameter1;
    int parameter2;
};

int generic_buttons_handle_mouse(const mouse* m, int x, int y, generic_button* buttons, int num_buttons, int* focus_button_id);
int generic_buttons_min_handle_mouse(const mouse* m, int x, int y, generic_button* buttons, int num_buttons, int* focus_button_id, int minimum_button);

inline int generic_buttons_handle_mouse(const mouse *m, vec2i pos, generic_button *buttons, int num_buttons, int *focus_button_id) {
    return generic_buttons_handle_mouse(m, pos.x, pos.y, buttons, num_buttons, focus_button_id);
}
#pragma once

#include "building/building.h"

class building_sandstone_quarry : public building_impl {
public:
    BUILDING_METAINFO(BUILDING_SANDSTONE_QUARRY, building_sandstone_quarry)

    building_sandstone_quarry(building &b) : building_impl(b) {}

    virtual void window_info_background(object_info &c) override;
    virtual void on_create(int orientration) override;
    virtual int animation_speed(int speed) const override { return 3; }
    virtual bool draw_ornaments_and_animations_height(painter &ctx, vec2i point, tile2i tile, color color_mask) override;
    virtual void update_count() const override;
};
#pragma once

#include "Helper.h"
#include <cstdint>
#include <raylib.h>
#include <string>
#include <cmath>

struct gui
{
    gui();
    uint32_t score;
    uint32_t kills;
    float level;
    float multiplier;

    const float multiplierCooldown = 30.f;
    const float scoreAndlevelCooldown = 1.0f;
    float scoreAndLevelFloor = 0.f;
    float multiplierFloor = 0.f;

    void Update();
    void Draw();
};
#pragma once

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <raylib.h>
#include <sstream>
#include <string>

// Static class containing helper function that are useful in all contexts.
class Helper
{
  public:
    static const int screenWidth = 600;
    static const int screenHeight = 850;
    static Vector2 LookAt(Vector2 from, Vector2 at);
    static Vector2 Normalize(Vector2 vector);
    static std::string FloatToString(float f, uint8_t precision = 2);

    // This is a static class. Do not instantiate.
    Helper() = delete;
};
#pragma once
#include <raylib.h>

// Static class containing helper function that are useful in all contexts.
class Helper
{
  public:
    static const int screenWidth = 600;
    static const int screenHeight = 850;
    static Vector2 LookAt(Vector2 from, Vector2 at);
    static Vector2 Normalize(Vector2 vector);

    // This is a static class. Do not instantiate.
    Helper() = delete;
};
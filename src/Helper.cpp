#include "Helper.h"
#include <cmath>

Vector2 Helper::LookAt(Vector2 from, Vector2 at)
{
    return Helper::Normalize({at.x - from.x, at.y - from.y});
}

Vector2 Helper::Normalize(Vector2 vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    return {vector.x / length, vector.y / length};
}
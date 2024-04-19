#pragma once

#include <raylib.h>

class Projectile
{
  public:
    Vector2 pos;
    Vector2 direction;
    float movementSpeed;
    float radius;
    Color color;

    Projectile(Vector2 pos, Vector2 direction, float movementSpeed, float radius, Color color);
    void Update();
    void Draw();
};
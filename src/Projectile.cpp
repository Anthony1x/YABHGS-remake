#include "Projectile.h"
#include <raylib.h>

Projectile::Projectile(Vector2 pos, Vector2 direction, float movementSpeed, float radius, Color color)
    : pos(pos), direction(direction), movementSpeed(movementSpeed), radius(radius), color(color)
{
}

void Projectile::Update()
{
    pos.x += direction.x * movementSpeed * GetFrameTime();
    pos.y += direction.y * movementSpeed * GetFrameTime();
}

void Projectile::Draw()
{
    DrawCircle((int)pos.x, (int)pos.y, radius, color);
}
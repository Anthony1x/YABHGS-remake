#include "Enemy.h"
#include "Helper.h"
#include "Projectile.h"
#include <raylib.h>

Enemy::Enemy(Vector2 pos, float radius, int hitPoints) : pos(pos), radius(radius), hitPoints(hitPoints)
{
}

void Enemy::Update(Vector2& playerPos)
{
    if (cooldown >= 0.f)
    {
        cooldown -= GetFrameTime();
    }

    if (cooldown <= 0.f)
    {
        auto direction = Helper::LookAt(pos, {playerPos.x, playerPos.y});

        projectiles.push_back(Projectile(pos, direction, 500, 5, RED));

        cooldown = shootCooldown;
    }

    // Update projectile position
    for (auto it = projectiles.begin(); it != projectiles.end(); /* no increment here */)
    {
        Projectile& projectile = *it;
        projectile.Update();

        // Remove projectile if out of bounds, else increment
        it = projectile.pos.y - projectile.radius < 0 ? projectiles.erase(it) : it + 1;
    }
}

void Enemy::Draw()
{
    DrawCircle(pos.x, pos.y, radius, GREEN);
}
#include "Enemy.h"

Enemy::Enemy(Vector2 pos, float radius, int hitPoints)
    : pos(pos), radius(radius), hitPoints(hitPoints)
{
    for (int i = 0; i < 4; i++)
    {
        if (GetRandomValue(0, 1) == 1)
        {
            break;
        }

        finalHeight += 50;
    }
}

void Enemy::Update(Player& player)
{
    if (pos.y <= finalHeight)
    {
        pos.y += 200.f * GetFrameTime();
        return;
    }

    if (cooldown >= 0.f)
    {
        cooldown -= GetFrameTime();
    }

    if (cooldown <= 0.f)
    {
        auto direction = Helper::LookAt(pos, {player.pos.x, player.pos.y});

        projectiles.push_back(Projectile(pos, direction, 500, 5, RED));

        cooldown = shootCooldown;
    }

    // Update projectile position
    for (auto it = projectiles.begin(); it != projectiles.end(); /* no increment here */)
    {
        Projectile& projectile = *it;

        if (CheckCollisionCircles(projectile.pos, projectile.radius, player.pos, player.radius))
        {
            it = projectiles.erase(it);
            break;
        }

        projectile.Update();

        // Remove projectile if out of bounds, else increment
        if (projectile.IsOutOfBounds())
        {
            it = projectiles.erase(it);
        }
        else
        {
            it = it + 1;
        }
    }
}

void Enemy::Draw()
{
    DrawCircle(pos.x, pos.y, radius, GREEN);
}

bool Enemy::Hurt()
{
    hitPoints -= 1;

    return hitPoints < 0;
}
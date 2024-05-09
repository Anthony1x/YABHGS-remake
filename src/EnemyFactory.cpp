#include "EnemyFactory.h"
#include "Helper.h"

std::optional<Enemy> EnemyFactory::CreateEnemy()
{
    if (cooldown >= 0.f)
    {
        cooldown -= GetFrameTime();
        return {};
    }

    if (cooldown <= 0.f)
    {
        cooldown = enemyCreationCooldown;

        // Possible fixme: Find out how good Raylibs RNG is compared to C++ native solutions.
        int rng = GetRandomValue(0, 10);

        if (rng > 5)
        {
            float enemyRadius = 20.f;
            float enemyPosX = GetRandomValue(enemyRadius, Helper::screenWidth - enemyRadius);

            return Enemy({enemyPosX, 100}, enemyRadius, 20);
        }
    }

    return {};
}
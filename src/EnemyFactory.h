#pragma once

#include "Enemy.h"
#include "Helper.h"
#include <optional>
#include <raylib.h>

class EnemyFactory
{
  public:
    // This is run every frame
    std::optional<Enemy> CreateEnemy();

  private:
    const float enemyCreationCooldown = 1.f;
    float cooldown = 0.f;
};
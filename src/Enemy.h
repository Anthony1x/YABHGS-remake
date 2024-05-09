#pragma once
#include "Projectile.h"
#include <vector>

class Enemy
{
  public:
    Enemy(Vector2 pos, float radius, int lifes);
    void Update(Vector2& playerPos);
    void Draw();
    Vector2 pos;
    float radius;
    int hitPoints;
    std::vector<Projectile> projectiles;

  private:
    const float shootCooldown = .5f;
    float cooldown = 0.f;
};
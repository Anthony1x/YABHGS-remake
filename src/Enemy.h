#pragma once

#include "Helper.h"
#include "Player.h"
#include "Projectile.h"
#include <raylib.h>
#include <vector>

class Enemy
{
  public:
    Enemy(Vector2 pos, float radius, int lifes);
    void Update(Player& player);
    void Draw();
    bool Hurt();
    Vector2 pos;
    float radius;
    int hitPoints;
    std::vector<Projectile> projectiles;

  private:
    float shootCooldown = .5f;
    float cooldown = 0.f;
    int finalHeight = 100;
};
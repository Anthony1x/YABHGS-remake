#pragma once

#include "Helper.h"
#include "Projectile.h"
#include <raylib.h>
#include <vector>

class Player
{
  public:
    Player(Vector2 pos, float radius, int lifes);
    Vector2 pos;
    float radius;
    int hitPoints;

    /*
     * FIXME: Cooldown is sorta framerate-dependent...
     * Very magic number. According to my calculations, this should actually be .02f
     * In the original code, shooting is polled every 2nd frame.
     * Since it ran at 100fps, that would mean you shoot at 50fps.
     * 1 / 50 = 0.02
     * But for some reason, when this is applied, less bullets are shot than in the original.
     * In the original, there can at most be 85 bullets on screen, given you shoot every 2nd frame.
     * But here, for some reason, it only goes up to 78 bullets.
     * This float is the closest I got it to 85 bullets.
     * Just don't think too much about it...
     */
    const float shootCooldown = .0188f;
    float cooldown = 0.f;
    std::vector<Projectile> projectiles;

    void Update();
    void Draw();
};
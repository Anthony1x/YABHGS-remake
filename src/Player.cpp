#include "Player.h"

Player::Player(Vector2 pos, float radius, int hitPoints) : pos(pos), radius(radius), hitPoints(hitPoints)
{
}

void Player::Update()
{
    if (cooldown >= 0.f)
    {
        cooldown -= GetFrameTime();
    }

    const float movementSpeed = 400 * GetFrameTime();
    const int powerSpeed = 600 * GetFrameTime();

    const int screenWidth = Helper::screenWidth;
    const int screenHeight = Helper::screenHeight;

    if (IsKeyDown(KeyboardKey(KEY_UP)) && pos.y - radius > 0)
    {
        pos.y -= movementSpeed;
    }

    if (IsKeyDown(KeyboardKey(KEY_DOWN)) && pos.y + radius < screenHeight)
    {
        pos.y += movementSpeed;
    }

    if (IsKeyDown(KeyboardKey(KEY_LEFT)) && pos.x - radius > 0)
    {
        pos.x -= movementSpeed;
    }

    if (IsKeyDown(KeyboardKey(KEY_RIGHT)) && pos.x + radius < screenWidth)
    {
        pos.x += movementSpeed;
    }

    if (IsKeyDown(KeyboardKey(KEY_Z)) && cooldown <= 0.f)
    {
        Projectile projectile = Projectile({pos.x, pos.y}, {0, -1}, 500, 5, RED);
        projectiles.push_back(projectile);

        cooldown = shootCooldown;
    }
}

void Player::Draw()
{
    DrawCircle((int)pos.x, (int)pos.y, radius, RED);
}

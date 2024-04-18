#include "Player.h"
#include "Helper.h"
#include <raylib.h>
#include "Projectile.h"

Player::Player(Vector2 pos, float radius, int lifes) : pos(pos), radius(radius), lifes(lifes)
{
}

void Player::Update()
{
    const float movementSpeed = 400 * GetFrameTime();
    const int powerSpeed = 600 * GetFrameTime();

    const int screenWidth = Helper::screenWidth;
    const int screenHeight = Helper::screenHeight;

    // TODO: Handle opposite key pressed (Up and Down, Left and Right)
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

    if (IsKeyDown(KeyboardKey(KEY_Y)))
    {
        // TODO: Create projectile, but how?
        // Two projectile arrays, one for the player and one for enemies?
        Projectile x = Projectile({20.f, 20.f}, {0.f, 0.f}, 10, 7, RED);
        x.Draw();
    }
}

void Player::Draw()
{
    DrawCircle((int)pos.x, (int)pos.y, radius, RED);
}
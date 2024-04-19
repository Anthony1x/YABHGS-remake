#include "Game.h"
#include "Helper.h"
#include "raylib.h"
#include <memory>

Game* Game::instance = nullptr;

Game::Game()
{
    const int screenWidth = Helper::screenWidth;
    const int screenHeight = Helper::screenHeight;

    InitWindow(screenWidth, screenHeight, "Raylib C++");

    int maxRefresh = GetMonitorRefreshRate(GetCurrentMonitor());

    SetTargetFPS(maxRefresh * 2);

    const int middleX = screenWidth / 2;
    const int middleY = screenHeight / 2;

    player = std::make_unique<Player>(Vector2{middleX, screenHeight - 27 - 50}, 27, 3);
}

Game* Game::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new Game();
    }

    return instance;
}

void Game::Update()
{
    player->Update();

    for (auto it = player->projectiles.begin(); it != player->projectiles.end(); /* no increment here */)
    {
        Projectile& projectile = *it;
        projectile.Update();

        // Remove projectile if out of bounds, else increment
        it = projectile.pos.y - projectile.radius < 0 ? player->projectiles.erase(it) : it + 1;
    }
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    player->Draw();

    for (Projectile projectile : player->projectiles)
    {
        projectile.Draw();
    }

    DrawFPS(20, 20);
    EndDrawing();
}

Game::~Game()
{
    delete instance;
}
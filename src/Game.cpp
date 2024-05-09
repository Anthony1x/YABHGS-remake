#include "Game.h"
#include "EnemyFactory.h"
#include "Helper.h"
#include "raylib.h"
#include <memory>

Game* Game::instance = nullptr;

Game::Game()
{
    const int screenWidth = Helper::screenWidth;
    const int screenHeight = Helper::screenHeight;

    InitWindow(screenWidth, screenHeight, "Raylib C++");

    const int maxRefresh = GetMonitorRefreshRate(GetCurrentMonitor());

    SetTargetFPS(maxRefresh * 2);

    const int middleX = screenWidth / 2;
    const int middleY = screenHeight / 2;

    player = std::make_unique<Player>(Vector2{middleX, screenHeight - 27 - 50}, 27, 3);

    enemyFactory = std::make_unique<EnemyFactory>();
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

    // Modern C++ is kinda awesome
    std::optional<Enemy> enemy = enemyFactory->CreateEnemy();

    if (enemy.has_value())
        enemies.push_back(enemy.value());

    for (auto& enemy : enemies)
        enemy.Update(player->pos);
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    player->Draw();

    for (Projectile& projectile : player->projectiles)
        projectile.Draw();

    for (Enemy& enemy : enemies)
    {
        enemy.Draw();

        for (Projectile& projectile : enemy.projectiles)
            projectile.Draw();
    }

    DrawFPS(20, 20);
    EndDrawing();
}

Game::~Game()
{
    delete instance;
}

#include "Game.h"
#include "Projectile.h"
#include "gui.h"

Game* Game::instance = nullptr;

Game::Game()
{
    const int screenWidth = Helper::screenWidth;
    const int screenHeight = Helper::screenHeight;

    InitWindow(screenWidth, screenHeight, "YABHGS Remake");

    const int maxRefresh = GetMonitorRefreshRate(GetCurrentMonitor());

    SetTargetFPS(360);

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
    // Update Player and Enemy positions first, so that collision calculation is up to date
    player->Update();

    for (Enemy& enemy : enemies)
    {
        enemy.Update(*player.get());
    }

    auto projectileIt = player->projectiles.begin();
    while (projectileIt != player->projectiles.end())
    {
        Projectile& projectile = *projectileIt;

        projectile.Update();

        bool projectileCollided = false;
        auto enemyIt = enemies.begin();
        while (enemyIt != enemies.end())
        {
            Enemy& enemy = *enemyIt;

            if (!CheckCollisionCircles(projectile.pos, projectile.radius, enemy.pos, enemy.radius))
            {
                ++enemyIt; // Move to next enemy if no collision
                continue;
            }

            projectileCollided = true;

            if (enemy.Hurt())
            {
                enemyIt = enemies.erase(enemyIt);

                gui.kills++;
                gui.score += 10;
            }
            else
            {
                ++enemyIt; // Move to next enemy otherwise
            }
        }

        // Check if projectile should be removed
        if (projectileCollided || projectile.IsOutOfBounds())
        {
            projectileIt = player->projectiles.erase(projectileIt);
        }
        else
        {
            ++projectileIt; // Move to next projectile
        }
    }

    // Modern C++ is kinda awesome
    std::optional<Enemy> enemy = enemyFactory->CreateEnemy();

    if (enemy.has_value())
    {
        enemies.push_back(enemy.value());
    }

    gui.Update();
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

    gui.Draw();
    EndDrawing();
}

Game::~Game()
{
    delete instance;
}

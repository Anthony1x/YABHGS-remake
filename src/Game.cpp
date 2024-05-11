#include "Game.h"

Game* Game::instance = nullptr;

Game::Game()
{
    const int screenWidth = Helper::screenWidth;
    const int screenHeight = Helper::screenHeight;

    InitWindow(screenWidth, screenHeight, "YABHGS Remake");

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
    // Update Player and Enemy positions first, so that collision calculation is up to date
    player->Update();

    for (Enemy& enemy : enemies)
    {
        enemy.Update(*player.get());
    }

    for (auto it = player->projectiles.begin(); it != player->projectiles.end();
         /* no increment here */)
    {
        Projectile& projectile = *it;

        projectile.Update();

        bool projectileCollided = false;

        for (auto it2 = enemies.begin(); it2 != enemies.end(); /* no increment here */)
        {
            Enemy& enemy = *it2;

            // Nothing to do if projectile didn't collide with the enemy.
            if (!CheckCollisionCircles(projectile.pos, projectile.radius, enemy.pos, enemy.radius))
            {
                ++it2;
                continue;
            }

            projectileCollided = true;

            if (enemy.Hurt())
            {
                it2 = enemies.erase(it2);
            }
            else
            {
                ++it2;
            }
        }

        // Remove projectile it collided or if out of bounds, else increment
        if (projectileCollided == true || projectile.IsOutOfBounds())
        {
            it = player->projectiles.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // Modern C++ is kinda awesome
    std::optional<Enemy> enemy = enemyFactory->CreateEnemy();

    if (enemy.has_value())
    {
        enemies.push_back(enemy.value());
    }
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

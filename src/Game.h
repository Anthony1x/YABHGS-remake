#pragma once

#include "Enemy.h"
#include "EnemyFactory.h"
#include "Helper.h"
#include "Player.h"
#include "raylib.h"
#include <memory>
#include <random>
#include <vector>

class Game
{
  public:
    // Access the single instance of the Game class
    static Game* GetInstance();

    void Update();
    void Draw();
    std::unique_ptr<Player> player;
    std::unique_ptr<EnemyFactory> enemyFactory;

    std::vector<Enemy> enemies;

  private:
    // Private constructor to prevent external creation
    Game();
    // Delete copy constructor
    Game(const Game&);
    // Delete assignment operator
    Game& operator=(const Game&);

    ~Game();

    static Game* instance;
};

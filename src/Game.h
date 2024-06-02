#pragma once

#include "Enemy.h"
#include "EnemyFactory.h"
#include "Helper.h"
#include "Player.h"
#include "gui.h"
#include "raylib.h"
#include <algorithm>
#include <cstdint>
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

    gui gui;

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

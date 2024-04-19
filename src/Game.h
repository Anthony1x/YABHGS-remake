#pragma once
#include "Player.h"
#include "raylib.h"
#include <memory>
#include <vector>
class Game
{
  public:
    // Access the single instance of the Game class
    static Game* GetInstance();

    void Update();
    void Draw();
    std::unique_ptr<Player> player;

  private:
    Game();                       // Private constructor to prevent external creation
    Game(const Game&);            // Delete copy constructor
    Game& operator=(const Game&); // Delete assignment operator

    ~Game();

    static Game* instance;
};

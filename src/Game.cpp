#include "Game.h"
#include "Helper.h"
#include "raylib.h"

Game* Game::instance = nullptr;

Game::Game()
{
    const int screenWidth = Helper::screenWidth;
    const int screenHeight = Helper::screenHeight;

    InitWindow(screenWidth, screenHeight, "Raylib C++");

    SetTargetFPS(30);

    const int middleX = screenWidth / 2;
    const int middleY = screenHeight / 2;

    player = new Player({middleX, screenHeight - 27 - 50}, 27, 3);
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
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    player->Draw();

    DrawFPS(20, 20);
    EndDrawing();
}

Game::~Game()
{
    delete instance;
}
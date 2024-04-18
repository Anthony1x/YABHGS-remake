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
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    const char* text = "Hello world!";
    int fontSize = 50;

    int textSize = MeasureText(text, fontSize);
    DrawText(text, GetRenderWidth() / 2 - (textSize / 2), GetRenderHeight() / 2, fontSize, WHITE);

    EndDrawing();
}

Game::~Game()
{
    delete instance;
}
#include "gui.h"
#include <cmath>
#include <string>

gui::gui()
{
    score = 0;
    kills = 0;
    level = 1.f;
    multiplier = 1.f;
}

void gui::Update()
{
    if (scoreAndLevelFloor >= 0.f)
    {
        scoreAndLevelFloor -= GetFrameTime();
    }

    if (scoreAndLevelFloor < 0.f)
    {
        level += 0.1f;
        score++;
        scoreAndLevelFloor = scoreAndlevelCooldown;
    }

    if (multiplierFloor >= 0.f)
    {
        multiplierFloor -= GetFrameTime();
    }

    if (multiplierFloor < 0.f)
    {
        multiplier *= 1.05;
        multiplierFloor = multiplierCooldown;
    }
}

void gui::Draw()
{
    std::string scoreText = "Score: " + std::to_string(score);
    std::string killsText = "Kills: " + std::to_string(kills);
    std::string levelText = "Level: " + Helper::FloatToString(level, 1);
    std::string multiText = "Multi: " + Helper::FloatToString(multiplier);

    float tempFinalScore = score * kills * multiplier;
    std::string tempFinalText = "Final Score: " + std::to_string(tempFinalScore);

    auto scoreTextLength = MeasureText(scoreText.c_str(), 20);
    auto scoreTextX = Helper::screenWidth - scoreTextLength - 20;

    auto levelTextLength = MeasureText(levelText.c_str(), 20);
    auto levelTextX = Helper::screenWidth - levelTextLength - 20;

    auto multiTextLength = MeasureText(multiText.c_str(), 20);
    auto multiTextX = Helper::screenWidth - multiTextLength - 20;

    auto tempTextLength = MeasureText(tempFinalText.c_str(), 20);
    auto tempTextX = Helper::screenWidth - tempTextLength - 20;

    DrawText(killsText.c_str(), 20, 40, 20, WHITE);

    DrawText(scoreText.c_str(), scoreTextX, 20, 20, WHITE);
    DrawText(multiText.c_str(), multiTextX, 40, 20, WHITE);
    DrawText(levelText.c_str(), levelTextX, 60, 20, WHITE);
    DrawText(tempFinalText.c_str(), tempTextX, 80, 20, WHITE);

    DrawFPS(20, 20);
}
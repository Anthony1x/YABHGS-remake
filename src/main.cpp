#include "Game.h"
#include "raylib.h"
#include <string>

int main(void)
{
    Game* game = Game::GetInstance();

    // all of this looks fucking horrible, just remove it after you confirmed it works
    auto cppVer = std::string("C++ Standard: ") + std::to_string(__cplusplus);
#if defined(__clang__)
    auto compilerVer = std::string("Clang Version: ") + std::to_string(__clang_major__) + '.' +
                       std::to_string(__clang_minor__) + '.' + std::to_string(__clang_patchlevel__);
#elif defined(__GNUC__) || defined(__GNUG__)
    auto compilerVer = std::string("GCC Version: ") + std::to_string(__GNUC__) + '.' + std::to_string(__GNUC_MINOR__) +
                       '.' + std::to_string(__GNUC_PATCHLEVEL__);
#endif

    while (!WindowShouldClose())
    {
        DrawText(cppVer.c_str(), 20, 20, 30, RAYWHITE);
        DrawText(compilerVer.c_str(), 20, 45, 30, RAYWHITE);
        game->Update();
        game->Draw();
    }

    CloseWindow();

    return 0;
}
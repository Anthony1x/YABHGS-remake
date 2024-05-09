#include "Game.h"
#include "raylib.h"

int main(void)
{
    Game* game = Game::GetInstance();

    /*
     * Ways to improve upon the original
     * 1. Code quality (duh)
     * 1.1 comment the fucking code jesus
     * 1.2 properly take advantage of OOP -> make it easy to extend functionality, like new enemy types
     * 2. Framerate independence
     * 3. Resolution scaling
     *
     * All in all, for now I only want to make quality of life additions.
     * Once I'm finished (really shouldn't take too long), I may create a new branch where I add lots of shit
     * This depends on my motivation and how well I reimplement the base.
     */

    while (!WindowShouldClose())
    {
        game->Update();
        game->Draw();
    }

    CloseWindow();

    return 0;
}

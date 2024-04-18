#include <raylib.h>

class Player
{
  public:
    Player(Vector2 pos, float radius, int lifes);
    Vector2 pos;
    float radius;
    int lifes;
    void Update();
    void Draw();
};
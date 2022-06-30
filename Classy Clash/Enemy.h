#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos,float moveSpeed, Texture2D idle_texture, Texture2D run_texture);
    void Tick(float deltaTime);
    
private:
   
};

#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::UndoMovement(){ worldPos = worldPosLastFrame; }

Rectangle BaseCharacter::GetCollisionRect()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
}

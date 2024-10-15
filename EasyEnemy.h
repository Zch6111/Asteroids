#ifndef EASYENEMY_H
#define EASYENEMY_H

#include "Enemy.h"

class EasyEnemy : public Enemy {
public:
    EasyEnemy();
    void updateAI(float deltaTime) override;
};

#endif
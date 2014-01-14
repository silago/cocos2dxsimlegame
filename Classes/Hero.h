#ifndef __HERO_H__
#define __HERO_H__

#include "cocos2d.h"
#include "AliveObject.h"
#include "Weapon.h"

class Hero : public AliveObject
{
public:
    Hero();
    void Init();
    void Shoot();
    cocos2d::CCSprite *sprite; 
    Weapon *weapon;
    
};

#endif // __HERO_H__

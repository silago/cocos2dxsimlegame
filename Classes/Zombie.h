#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include "cocos2d.h"
#include "AliveObject.h"


class Zombie : public AliveObject
{
public:
    Zombie();
    cocos2d::CCSprite *target;
    void SetTarget(cocos2d::CCSprite * tar);
    void Update();
    void Init();
	void Hunt();
	cocos2d::CCMoveBy * moving_action;
	bool ready;
    
};

#endif // __ZOMBIE_H__


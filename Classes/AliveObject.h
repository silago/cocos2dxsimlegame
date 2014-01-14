#ifndef __ALIVEOBJECT_H_
#define __ALIVEOBJECT_H_

#include "cocos2d.h"

class AliveObject : public cocos2d::CCSprite
{
public:

    AliveObject();
    
    void	Turn();
    void	Move();
    void	Die();
    int		health;
    double		speed;
    double		char_direction;
    double		char_rotation;
};

#endif // __ALIVEOBJECT_H_

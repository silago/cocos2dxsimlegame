#include "AliveObject.h"

USING_NS_CC;



AliveObject::AliveObject()
{
	this->health=100;
	this->speed = 10.1;
	this->char_direction = 0;
	this->char_rotation = 0;
}

void AliveObject::Move()
{
	 //position[0]+=self.speed*sin(radians(self.r))
	 double x;
	 double y;
	 x = this->speed*sin(this->char_direction);
	 y = this->speed*cos(this->char_direction);
	 
	 
	 		char buff [100];
			sprintf (buff, "%f", this->speed);
			CCLog(buff);
			  
	 this->stopAllActions();
	// CCRepeat::create(act1, 1)
     this->runAction(CCRepeatForever::create(CCMoveBy::create(0.1, ccp(x, y))));
		
}



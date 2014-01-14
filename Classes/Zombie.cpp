#include "Zombie.h"
#include <math.h>

USING_NS_CC;

Zombie::Zombie()
{
  
  this->initWithFile("incognito.png");
  this->moving_action = CCMoveBy::create(1, ccp(0, 0));
  this->runAction(this->moving_action);
  this->speed=1;
}

void Zombie::Init()
{
	this->schedule( schedule_selector(Zombie::Update) );    
}

void Zombie::Update()
{
	this->Hunt();

}

void Zombie::SetTarget(CCSprite * tar)
{
		this->target = tar;
	//	this->ready = false;
}


void Zombie::Hunt()
{	 CCLog("____");

		
	if (!this->moving_action->isDone())
	
	 {
	 //this->stopAllActions();
	 double direction = atan2(this->getPosition().x-this->target->getPosition().x,this->getPosition().y-this->target->getPosition().y);  		
	 direction = direction+3.14159265;	 
		
		
		
	 double x;
	 double y;
	 x = this->speed*sin(direction);
	 y = this->speed*cos(direction);
	 
	 this->moving_action = CCMoveBy::create(1, ccp(x, y));
			  
     this->runAction(this->moving_action);
	}
}





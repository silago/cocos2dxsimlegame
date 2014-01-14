#include "Weapon.h"

USING_NS_CC;

Weapon::Weapon()
{	
	this->weapon_rotation=0;
	this->distance = 100;
	this->speed = 1;
	//return 1;
}

CCSprite* Weapon::Shoot()
{	
	//CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	cocos2d::CCNode *layer = this->getParent()->getParent();
	CCSprite *bullet = CCSprite::create("bullet.png", CCRectMake(0, 0, 2, 2));
	bullet->setPosition( this->getParent()->getPosition());
	layer->addChild(bullet);


	 double x;
	 double y;
	 x = this->distance*sin(this->weapon_rotation);
	 y = this->distance*cos(this->weapon_rotation);
	 
	 
			  
	 //this->stopAllActions();
	 // CCRepeat::create(act1, 1)
     //this->runAction(CCRepeatForever::create(CCMoveBy::create(0.1, ccp(x, y))));


	 bullet->runAction(CCMoveBy::create(this->speed, ccp(x, y)));
	
	
	return bullet;
}

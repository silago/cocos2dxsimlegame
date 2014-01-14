#include "Hero.h"
#include "Weapon.h"
#include <math.h>

USING_NS_CC;

Hero::Hero()
{
  
  this->initWithFile("incognito.png");
  //this->sprite = sprite;
  this->speed = 10;
  this->weapon = new Weapon();
  this->addChild(this->weapon);
  this->weapon->setPosition(ccp(0,0));
  	//CCSprite *sprite = CCSprite::create("incognito.png");
	//	this->addChild(sprite);
  //this->addChild(this->weapon);
  
  
 // return this;
}

void Hero::Init()
{
	
}



void Hero::Shoot()
{	this->weapon->weapon_rotation=this->char_rotation;
	this->weapon->Shoot();
}






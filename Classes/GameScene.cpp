#include "GameScene.h"
#include "Hero.h"
#include <math.h>
#include <string>
#include <stdio.h>
#include "functions.cpp"
#include "Zombie.h"


USING_NS_CC;

CCScene* Game::scene()
{
    CCScene *scene = CCScene::create();
    Game *layer = Game::create();
    scene->addChild(layer);
    return scene;
}
bool Game::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCSprite* pSprite = CCSprite::create("dirt.jpg");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
    this->addChild(HUD::create());
    
   // Hero pHero = Hero();
     
  //   pHero.init();
   //  pHero.sprite = CCSprite::create("incognito.png");
   
	this->pHero =  new Hero();
	this->addChild(this->pHero,20,0);
	this->pHero->setPosition(ccp(200,200));
	//this->pHero->Init();
	
    //this->pHero->sprite->setPosition(ccp(200,200));
    
	//this->addChild(this->pHero->sprite,20,0);

	//pHero.sprite->registerTouchBeginObserver(this, callfuncO_selector(Game::touchBeginOnSprite));
	
	
	//pHero.Move();
	this->InitControles();
	this->setTouchEnabled(true);
	
	this->zombies = new CCArray;
	
	this->AddZombie();
	
	
    return true;
}

void Game::Update(float dt)
{
	
	CCObject* obj;
	CCARRAY_FOREACH(this->zombies,obj)
	{
	   Zombie * z = dynamic_cast<Zombie*>(obj);
	   z->Hunt();
	}

}


void Game::AddZombie()
{	
	
	int i;
	i = 0;
	for (i=0;i<10;i++)
	{Zombie * z =  new Zombie();
	z->setPosition(ccp(130+i*10,130+i*10));
	
	z->SetTarget(this->pHero);
	z->Init();
//	z->Hunt();
//	z->runAction(CCRepeat::create(CallFunc::create(0.1, ccp(x++, y)),1));
	
	
	
	this->addChild(z);
	this->zombies->addObject(z);	}
	//this->schedule( schedule_selector(Game::Update) );    
}


void Game::InitControles()
{
	 CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	 this->leftControlLocation = ccp(75,75);
	 this->rightControlLocation = ccp(visibleSize.width-75,75);
	 
	 
	 this->leftControlPoint = CCSprite::create("ControlPoint.png");
	 this->leftControlArea = CCSprite::create("ControlCircle.png");
	 this->rightControlPoint = CCSprite::create("ControlPoint.png");
	 this->rightControlArea = CCSprite::create("ControlCircle.png");
	 
	 this->leftControlPoint->setPosition(this->leftControlLocation);
	 this->leftControlArea->setPosition(this->leftControlLocation);
	 this->rightControlPoint->setPosition(this->rightControlLocation);
	 this->rightControlArea->setPosition(this->rightControlLocation);
	 
	 this->addChild(this->leftControlPoint,100);
	 this->addChild(this->leftControlArea,101);
	 this->addChild(this->rightControlPoint,100);
	 this->addChild(this->rightControlArea,100);
	 
	 
	 this->leftControlPointTouched=false;
	 this->rightControlPointTouched=false;
	
}

void Game::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{	
	int controlTouch;
	
	
	controlTouch = 0;
	
	this->leftControlPointTouched=false;
	this->rightControlPointTouched=false;

        CCTouch* touch = (CCTouch*)( pTouches->anyObject() );
       
        if (ccpDistance(this->leftControlPoint->getPosition(),touch->getLocation())<20)		controlTouch=1;
       
       
        if (ccpDistance(this->rightControlPoint->getPosition(),touch->getLocation())<20)	
			{
				controlTouch=2;
				///CCSprite *bullet = pHero->weapon->Shoot();
				this->addChild(pHero->weapon->Shoot(),200);
				//this->pHero->Shoot();
			}
    // }
    
    if (controlTouch==1)
    {	
		
		this->leftControlPointTouched=true;
	}
	
	else if (controlTouch==2)	this->rightControlPointTouched=true;

}

void Game::ccTouchesEnded	(CCSet * pTouches,CCEvent * pEvent ){
	this->rightControlPoint->setPosition(this->rightControlLocation);
	this->leftControlPoint->setPosition(this->leftControlLocation);
}


void Game::ccTouchesMoved(CCSet* pTouches, CCEvent* event)
{	
	 CCTouch* touch = (CCTouch*)( pTouches->anyObject() );
	 // left joystick
	 if (this->leftControlPointTouched==true){
		 double direction = atan2(leftControlLocation.x-touch->getLocation().x,leftControlLocation.y-touch->getLocation().y);  		
		 direction = direction+3.14159265;	 
		 if (ccpDistance(this->leftControlArea->getPosition(),touch->getLocation())<=20)	
			this->leftControlPoint->setPosition(touch->getLocation());
		 else{
			double x; x = 20*sin(direction);
			double y; y = 20*cos(direction);					 
				
			CCPoint leftControlPointPosition = ccp(this->leftControlLocation.x+x,this->leftControlLocation.y+y);
			this->leftControlPoint->setPosition(leftControlPointPosition);
		 }

  		 this->pHero->char_direction = direction;
		 this->pHero->Move();
	 }
	 
	 
	 
	 //right joystick
	 if (this->rightControlPointTouched==true){
		 double direction = atan2(rightControlLocation.x-touch->getLocation().x,rightControlLocation.y-touch->getLocation().y);  		
		 direction = direction+3.14159265;	 
		 if (ccpDistance(this->rightControlArea->getPosition(),touch->getLocation())<=20)	
			this->rightControlPoint->setPosition(touch->getLocation());
		 else{
			double x; x = 20*sin(direction);
			double y; y = 20*cos(direction);					 
				
			CCPoint rightControlPointPosition = ccp(this->rightControlLocation.x+x,this->rightControlLocation.y+y);
			this->rightControlPoint->setPosition(rightControlPointPosition);
		 }

  		 this->pHero->char_rotation = direction;
		 this->pHero->Shoot();
	 }
}





void Game::ccTouchEnded(CCTouch* touch, CCEvent* event)
{CCLog("1");
}
bool Game::ccTouchBegan(CCTouch* touch, CCEvent* event)
{	
	return 1;
}


bool HUD::init()
{	
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCLabelTTF *score = CCLabelTTF::create("0", "Helvetica", 12,  
                                      CCSizeMake(245, 32), kCCTextAlignmentLeft);
	score->setPosition(ccp(150, visibleSize.height-50));
	score->setColor(ccc3(0, 0, 0));
	this->addChild(score,10);
	
	if (score == 0)	return 1;
    return 1;
}



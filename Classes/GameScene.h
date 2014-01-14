#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"
#include "Hero.h"
//#include "Hero.cpp"

class Game : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    void InitControles();
    void Update(float dt);
    void AddZombie();
    static cocos2d::CCScene* scene();
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);	
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
	virtual void ccTouchesEnded	(cocos2d::CCSet * pTouches,cocos2d::CCEvent * pEvent ); 	
   
   
   
    Hero *pHero;
    //void menuCloseCallback(CCObject* pSender);
    
    cocos2d::CCSprite *leftControlPoint;
    cocos2d::CCSprite *leftControlArea;
    cocos2d::CCSprite *rightControlPoint;
    cocos2d::CCSprite *rightControlArea;
    cocos2d::CCPoint  leftControlLocation;
    cocos2d::CCPoint  rightControlLocation;
    
    cocos2d::CCArray *zombies; 
    
    bool  leftControlPointTouched;
    bool rightControlPointTouched;
    
    CREATE_FUNC(Game);
};


class HUD : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    //static cocos2d::CCScene* scene();
    //void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(HUD);
};


#endif // __GAMESCENE_H__


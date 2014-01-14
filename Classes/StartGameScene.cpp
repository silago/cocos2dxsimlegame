#include "StartGameScene.h"
#include "GameScene.h"

USING_NS_CC;

CCScene* StartGame::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    StartGame *layer = StartGame::create();

    // add layer as a child to scene
    scene->addChild(layer);
 
	
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartGame::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItem *pCloseItem = CCMenuItemFont::create( "CLOSE", this, menu_selector(StartGame::menuCloseCallback));
    CCMenuItem *pStartItem = CCMenuItemFont::create( "START", this, menu_selector(StartGame::menuStartCallback));
    CCMenuItem *pScoreItem = CCMenuItemFont::create( "SCORE", this, menu_selector(StartGame::menuCloseCallback));
    CCMenuItem *pHelpItem = CCMenuItemFont::create( "HELP", this, menu_selector(StartGame::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(visibleSize.width/2 +100, visibleSize.height/2-80));
	pStartItem->setPosition(ccp(visibleSize.width/2 +100, visibleSize.height/2+40));
	pScoreItem->setPosition(ccp(visibleSize.width/2 +100, visibleSize.height/2-40));
	pHelpItem->setPosition(ccp(visibleSize.width/2 +100, visibleSize.height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, pStartItem,pScoreItem,pHelpItem,  NULL);
    pMenu->setPosition(origin);
    this->addChild(pMenu, 2);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    //CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    //pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    //this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("StartScene.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}


void StartGame::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

void StartGame::menuStartCallback(CCObject* pSender)
{
CCScene *pScene = Game::scene();
CCDirector::sharedDirector()->replaceScene(pScene);
}

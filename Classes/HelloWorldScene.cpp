#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(HelloWorld::menuCloseCallback) );
	pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition( CCPointZero );
	this->addChild(pMenu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// position the label on the center of the screen
	pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	// add "HelloWorld" splash screen"
	CCSprite* pSprite = CCSprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );

	// add the sprite as a child to this layer
	//this->addChild(pSprite, 0);

	this->createScrolling();

	this->schedule(schedule_selector(HelloWorld::update));

	return true;
}

void HelloWorld::update(float dt) {
	//CCLOG("Game Loop ");
	this->moveBgRightToLeft();
}

void HelloWorld::moveBgRightToLeft(){

	visibleBG->setPosition(ccpAdd(visibleBG->getPosition(), ccp(-10, -5.625)));
	rightBG->setPosition(ccpAdd(rightBG->getPosition(), ccp(-10, -5.625)));
	uprightBG->setPosition(ccpAdd(uprightBG->getPosition(), ccp(-10, -5.625)));
	upleftBG->setPosition(ccpAdd(upleftBG->getPosition(), ccp(-10, -5.625)));


	if ((visibleBG->getPosition().x <= -1280) && (visibleBG->getPosition().y <= -720)){
		CCLOG("Change BG");
		CCSprite *bgaux = visibleBG;
		visibleBG = uprightBG;
		uprightBG = bgaux;
		rightBG->setPosition(ccp(1280,0));
		uprightBG->setPosition(ccp(1280,720));
		upleftBG->setPosition(ccp(0,720));
	}
}

void HelloWorld::createScrolling(){

	visibleBG = CCSprite::create("HelloWorld.png");
	visibleBG->setAnchorPoint(ccp(0, 0));
	visibleBG->setPosition(ccp(0, 0));
	this->addChild(visibleBG,0);

	rightBG = CCSprite::create("HelloWorld.png");
	rightBG->setAnchorPoint(ccp(0, 0));
	rightBG->setPosition(ccp(1280, 0));
	this->addChild(rightBG,0);

	uprightBG = CCSprite::create("HelloWorld.png");
	uprightBG->setAnchorPoint(ccp(0, 0));
	uprightBG->setPosition(ccp(1280, 720));
	this->addChild(uprightBG,0);

	upleftBG = CCSprite::create("HelloWorld.png");
	upleftBG->setAnchorPoint(ccp(0, 0));
	upleftBG->setPosition(ccp(0, 720));
	this->addChild(upleftBG,0);


}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

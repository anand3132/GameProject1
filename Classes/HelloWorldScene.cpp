#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

HelloWorld::HelloWorld() {
	mNinja = nullptr;
}

HelloWorld::~HelloWorld() {
	if (mNinja) {
		mNinja->release();
	}
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y +visibleSize.height-closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
	//auto JoyStickItem = cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/HD/lineLight-0.plist");
	//auto ui = cocos2d::Sprite::createWithSpriteFrame(spriteFrame);

	//auto JoyStickItem = MenuItemImage::create("lineLight00.png","lineLight02.png",
	//	CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	//JoyStickItem->setPosition(Vec2(origin.x  - JoyStickItem->getContentSize().width / 2,
	//	origin.y  - JoyStickItem->getContentSize().height / 2));

	//// create menu, it's an autorelease object
	//auto menu = Menu::create(JoyStickItem, NULL);
	//menu->setPosition(Vec2::ZERO);
	//this->addChild(menu, 1);
	/////////////////////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
  
	// atlas loading
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/HD/ninja-0.plist");
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/HD/ninja-1.plist");
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/HD/ninja-2.plist");
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/HD/ninja-3.plist");

	//auto spriteFrame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName("Attack__003.png");
	//auto ninja = cocos2d::Sprite::createWithSpriteFrame(spriteFrame);
	//ninja->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//ninja->setScale(0.5f);
	//addChild(ninja);

	//auto moveTo = MoveTo::create(2, Vec2(50, 10));
	//auto scaleTo = ScaleTo::create(2, 1.0f);
	//auto sq = Sequence::create(moveTo, scaleTo, nullptr);
	//ninja->runAction(moveTo);
	//ninja->runAction(scaleTo);
	
	// ninja->runAction(sq);

	mNinja = Ninja::createNinja();
	mNinja->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	mNinja->setScale(0.2f);
	mNinja->retain();	// We retain this so that we can remove this object from the scene with out getting destroyed.
	this->addChild(mNinja);

	//Keyboard events
	//----------------------------
	//Initializing and binding 
	/*auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(KeyboardTest::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(KeyboardTest::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);*/


   return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

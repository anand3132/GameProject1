#include "GameEngine.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene() {
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
	mBG = nullptr;
}

HelloWorld::~HelloWorld() {
	if (mNinja) {
		mNinja->release();
	}
}
// on "init" you need to initialize your instance
bool HelloWorld::init() {
    if (!Layer::init()) {
        return false;
    }
    
	loadSpriteSheets();
	initUI();
	loadBG();
	loadNinja();
	initKeyBoardEvents();

	return true;
}

void HelloWorld::loadBG() {
	auto spriteCache = cocos2d::SpriteFrameCache::getInstance();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//Add background
	mBG = Sprite::createWithSpriteFrame(spriteCache->getSpriteFrameByName("Background1.png"));
	// Calculate the ratio needed to scale the BG to full screen (height wise).
	float ratio = visibleSize.height / mBG->getContentSize().height;
	mBG->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	mBG->setPosition(Vec2::ZERO);
	mBG->setScale(ratio);
	addChild(mBG);
}

void HelloWorld::loadNinja() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//create ninja
	mNinja = Ninja::createNinja(0.2f, Vec2(visibleSize.width*0.1f, visibleSize.height*0.12f));
	mNinja->retain();	// We retain this so that we can remove this object from the scene with out getting destroyed.
	this->addChild(mNinja);

	// follow cam
	auto bgRect = Rect(Vec2::ZERO, mBG->getBoundingBox().size);
	auto screenSz = Director::getInstance()->getVisibleSize();
	this->runAction(Follow::createWithOffset(mNinja, screenSz.width*0.1f, 0, bgRect));
}

void HelloWorld::initUI() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// close button
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + visibleSize.height - closeItem->getContentSize().height / 2));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//game label
	auto label = Label::createWithTTF("Ninja", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);
}

void HelloWorld::loadSpriteSheets() {
	// atlas/Sprite plist loading
	auto spriteCache = cocos2d::SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("sprites/HD/ninja-0.plist");
	spriteCache->addSpriteFramesWithFile("sprites/HD/ninja-1.plist");
	spriteCache->addSpriteFramesWithFile("sprites/HD/ninja-2.plist");
	spriteCache->addSpriteFramesWithFile("sprites/HD/ninja-3.plist");
	spriteCache->addSpriteFramesWithFile("sprites/HD/BG-0.plist");
}

void HelloWorld::initKeyBoardEvents() {
	//Keyboard events
	mKeyPressed = false;
	auto eventListener = EventListenerKeyboard::create();

	eventListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event* event) {
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			if (!mKeyPressed) { mNinja->playRun(Ninja::LEFT); }
			mKeyPressed = true;
			break;

		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			if (!mKeyPressed) { mNinja->playRun(Ninja::RIGHT); }
			mKeyPressed = true;
			break;

		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			if (mKeyPressed) { mNinja->playCrawl(); }
			mKeyPressed = true;
			break;

		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			if (mKeyPressed) { mNinja->playCrawl(); }
			mKeyPressed = true;
			break;

		case EventKeyboard::KeyCode::KEY_SPACE:
			if (!mKeyPressed) { mNinja->playJump(); }
			mKeyPressed = true;
			break;

		case EventKeyboard::KeyCode::KEY_LEFT_CTRL:
		case EventKeyboard::KeyCode::KEY_RIGHT_CTRL:
			if (!mKeyPressed) { mNinja->playAttack(); }
			mKeyPressed = true;
			break;
		}
	};

	eventListener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event* event) {
		// Vec2 loc = event->getCurrentTarget()->getPosition();
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			if (mKeyPressed) { mNinja->playIdle(Ninja::NINJA_DIRECTION::LEFT); }
			mKeyPressed = false;
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			if (mKeyPressed) { mNinja->playIdle(Ninja::NINJA_DIRECTION::RIGHT); }
			mKeyPressed = false;
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			if (mKeyPressed) { mNinja->playIdle(Ninja::NINJA_DIRECTION::RIGHT); }
			mKeyPressed = false;
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			if (mKeyPressed) { mNinja->playIdle(Ninja::NINJA_DIRECTION::RIGHT); }
			mKeyPressed = false;
			break;
		case EventKeyboard::KeyCode::KEY_SPACE:
			if (mKeyPressed) { mNinja->playIdle(Ninja::NINJA_DIRECTION::LEFT); }
			mKeyPressed = false;
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_CTRL:
		case EventKeyboard::KeyCode::KEY_RIGHT_CTRL:
			if (mKeyPressed) { mNinja->playIdle(Ninja::NINJA_DIRECTION::LEFT); }
			mKeyPressed = false;
			break;
		}
	};
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

void HelloWorld::menuCloseCallback(Ref* pSender) {
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void HelloWorld::update(float delta) {
}

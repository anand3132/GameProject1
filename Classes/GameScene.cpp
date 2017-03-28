#include "GameInclude.h"
#include "json/document.h"
#include "json/writer.h"
#include "GameScene.h"
USING_NS_CC;

Scene* GameScene::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();    
    // 'layer' is an autorelease object
	auto gamescene = GameScene::create();
    // add layer as a child to scene
    scene->addChild(gamescene);
    // return the scene
    return scene;
}

GameScene::GameScene() {
	mNinja = nullptr;
	mBG = nullptr;
	mGamelayer = nullptr;
	mHUDLayer = nullptr;
}

GameScene::~GameScene() {
	if (mNinja) {
		mNinja->release();
	}
}
// on "init" you need to initialize your instance
bool GameScene::init() {
    if (!Layer::init()) {
        return false;
    }
	mGamelayer = Layer::create();
	mHUDLayer = Layer::create();
	addChild(mGamelayer);
	addChild(mHUDLayer);
	loadLevel();

	//loadHUD();
	//loadBG();
	//loadNinja();
	//setCamFollow(mNinja);
	initKeyBoardEvents();
	return true;
}
void GameScene::loadHUD()
{
	mHUD = HUD::createHUD();
	mHUDLayer->addChild(mHUD, 2);
}

void GameScene::loadBG() {
	auto spriteCache = cocos2d::SpriteFrameCache::getInstance();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//Add background
	spriteCache->addSpriteFramesWithFile("sprites/HD/BG-0.plist");
	mBG = Sprite::createWithSpriteFrame(spriteCache->getSpriteFrameByName("Background1.png"));
	// Calculate the ratio needed to scale the BG to full screen (height wise).
	float ratio = visibleSize.height / mBG->getContentSize().height;
	mBG->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	mBG->setPosition(Vec2::ZERO);
	mBG->setScale(ratio);
	mGamelayer->addChild(mBG);
}

void GameScene::loadNinja() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//create ninja
	mNinja = Ninja::createNinja(0.2f, Vec2(visibleSize.width*0.1f, visibleSize.height*0.12f));
	mNinja->retain();	// We retain this so that we can remove this object from the scene with out getting destroyed.
	mGamelayer->addChild(mNinja);
	
}
void GameScene::setCamFollow(Node* cNode) {
	auto screenSz = Director::getInstance()->getVisibleSize();
	// follow cam
	auto bgRect = Rect(Vec2::ZERO, mBG->getBoundingBox().size);
	mGamelayer->runAction(Follow::createWithOffset(cNode, screenSz.width*0.1f, 0, bgRect));
}
void GameScene::loadLevel() {
	auto spriteCache = cocos2d::SpriteFrameCache::getInstance();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//load Level Map
	auto *map = TMXTiledMap::create("Level1.tmx");
	float ratio = visibleSize.height / map->getContentSize().height;
	//map->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	//map->setPosition(Vec2::ZERO);
	//map->setScale(ratio);
	//map->setScale(0.08f);
	mGamelayer->addChild(map);
	
}

void GameScene::initKeyBoardEvents() {
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
			if (!mKeyPressed) { mNinja->playJump();
			mHUD->HUDMessege("space  pressed");
			}
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

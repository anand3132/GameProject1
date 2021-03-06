#include "GameInclude.h"
#include "MainMenu.h"
USING_NS_CC;
MainMenu::MainMenu()
{
	mSplash=nullptr;
	mPlayButton=nullptr;
}

MainMenu::~MainMenu()
{
}

Scene* MainMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenu::create();
	scene->addChild(layer);
	return scene;
}

bool MainMenu::init()
{

	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// close button
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",CC_CALLBACK_1(MainMenu::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
														origin.y + visibleSize.height - closeItem->getContentSize().height / 2));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//Add sprite plist
	auto spriteCache = cocos2d::SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("sprites/HD/UI-0.plist");
	mSplash = Sprite::createWithSpriteFrame(spriteCache->getSpriteFrameByName("Splash_screen.png"));

	mSplash->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	addChild(mSplash);

	//PlayButton
	auto uButton = ui::Button::create();
	uButton->setTouchEnabled(true);

	uButton->loadTextures("buttons/normal/play.png", "buttons/click/play.png", "buttons/hover/play.png", ui::TextureResType::PLIST);
	uButton->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2) + Point(0, -50));
	addChild(uButton);

	uButton->addTouchEventListener([this](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
		{
			cocos2d::log("Button pressed");
			Director::getInstance()->replaceScene(GameScene::createScene());
		}
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});

	//auto listener1 = EventListenerTouchOneByOne::create();

	//// trigger when you push down
	//listener1->onTouchBegan = [](Touch* touch, Event* event) {
	//// your code
	//return true; // if you are consuming it
	//};

	//// trigger when moving touch
	//listener1->onTouchMoved = [](Touch* touch, Event* event) {
	//	// your code
	//};

	//// trigger when you let up
	//listener1->onTouchEnded = [=](Touch* touch, Event* event) {
	//	// your code
	//};

	//// Add listener
	//this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
	////}


	return true;
}



void MainMenu::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
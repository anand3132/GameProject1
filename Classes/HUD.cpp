#include "GameInclude.h"
#include "HUD.h"
USING_NS_CC;

HUD::HUD()
{
}

HUD::~HUD()
{
}

HUD* HUD::createHUD()
{
	HUD *HUDLayer = new (std::nothrow) HUD();
	if (HUDLayer && HUDLayer->initHUD())
	{
		HUDLayer->autorelease();
		return HUDLayer;
	}
	CC_SAFE_DELETE(HUDLayer);
	return nullptr;
}

bool HUD::initHUD()
{
	if (!Layer::init())
	{
		return false;
	}
//	setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//game label
	auto label = Label::createWithTTF("NInja Kid", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	addChild(label, 1);

	//create close button
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(HUD::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + visibleSize.height - closeItem->getContentSize().height / 2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	
	return true;
}
bool HUD::HUDMessege(const std::string& _message)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF(_message, "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width *.2,
		(origin.y + visibleSize.height - label->getContentSize().height)*.8));
	this->addChild(label, 1);

	auto HUDdelayTime = DelayTime::create(.5f);
	auto HUDhideMsg = FadeOut::create(0.8f);
	label->runAction(Sequence::create(HUDdelayTime, HUDhideMsg, NULL));

	return true;
}

void HUD::menuCloseCallback(Ref* pSender) {
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}
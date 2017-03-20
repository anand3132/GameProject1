#pragma once

class MainMenu :public cocos2d::Layer
{
public:
	MainMenu();
	virtual ~MainMenu();

	static cocos2d::Scene* createScene();
	bool init() override;
	void menuCloseCallback(cocos2d::Ref* pSender);
//	void menuTouchEvent(Ref* pSender, ui::Widget::TouchEventType type);
	CREATE_FUNC(MainMenu);

protected:
private:
	cocos2d::Sprite* mSplash;
	cocos2d::Sprite* mPlayButton;
};
#pragma once

class HUD :public cocos2d::Layer
{
public:
	HUD();
	virtual ~HUD();

	static HUD* createHUD();
	bool initHUD();
	bool HUDMessege(const std::string& _message);
	void HUD::menuCloseCallback(Ref* pSender);
private:
	cocos2d::Label* _messageLabel;
	
};
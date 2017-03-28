#pragma once
#include "hud.h"

class GameScene : public cocos2d::Layer
{
public:
	GameScene();
	virtual ~GameScene();

	static cocos2d::Scene* createScene();
    bool init() override;
    
	void initKeyBoardEvents();
	void loadBG();
	void loadNinja();
	void setCamFollow(Node * cNode);
	void setCamFollow();
	void loadHUD();
	void loadLevel();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
	Ninja* mNinja;
	HUD*	mHUD;

	Layer* mGamelayer;
	Layer* mHUDLayer;

	cocos2d::Sprite* mBG;
	bool mKeyPressed;
	int mcurrentLevel;
	int mcurrentBackground;
	std::string spriteFrameFormat;

};

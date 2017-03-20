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
	void loadSpriteSheets();
	void loadBG();
	void loadNinja();
	void loadHUD();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
	void update(float delta);
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
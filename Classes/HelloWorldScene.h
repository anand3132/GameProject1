#pragma once

class HelloWorld : public cocos2d::Layer
{
public:
	HelloWorld();
	virtual ~HelloWorld();

	static cocos2d::Scene* createScene();
    bool init() override;
    
	void initUI();
	void initKeyBoardEvents();
	void loadSpriteSheets();
	void loadBG();
	void loadNinja();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	void update(float delta);
private:
	Ninja* mNinja;
	cocos2d::Sprite* mBG;
	bool mKeyPressed;
	int mcurrentLevel;
	int mcurrentBackground;
	std::string spriteFrameFormat;

};

#pragma once

class HelloWorld : public cocos2d::Layer
{
public:
	HelloWorld();
	virtual ~HelloWorld();

	static cocos2d::Scene* createScene();
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
	Ninja* mNinja;
	cocos2d::Sprite* mBG;
	bool mKeyPressed;
	int mcurrentLevel;
	int mcurrentBackground;
	std::string spriteFrameFormat;

};

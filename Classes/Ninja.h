#pragma once

#include <cocos2d.h>

namespace NinjaUtil 
{
	std::string formatString(const char* format, ...);
};

class Ninja : public cocos2d::Sprite
{
public:
	enum NINJA_STATE {
		IDLE,
		RUN,
		JUMP,
		JUMPATTACK,
		CRAWL,
		ATTACK,
		DIE
	};

	enum NINJA_DIRECTION {
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
    static Ninja* createNinja(float scale = 1.0f, cocos2d::Vec2 pos = cocos2d::Vec2::ZERO);

	Ninja();
	virtual ~Ninja();

    bool initNinja(float scale, cocos2d::Vec2 pos);
	void update(float delta);

	void playIdle(NINJA_DIRECTION dir);
	void playRun(NINJA_DIRECTION dir);
	void playAttack();
	void playCrawl();
	void playJump();
	void jumpAttack();
	void SetNinjaDirection(NINJA_DIRECTION dir);
	//NINJA_DIRECTION GetNinjaDirection();
protected:
	void OnStateChange(NINJA_STATE prevState, NINJA_STATE curState);
	void OnDirectionChange(NINJA_DIRECTION prevDir, NINJA_DIRECTION curDir);

private:
	void SetState(NINJA_STATE state);
	void setCurrentAnimationFrame(int frame);

	std::string spriteFrameFormat;
	int mFrameCount;
	int mCurrentFrame;
	float mElapsedSinceLastFrame;
	NINJA_STATE mState;
	NINJA_DIRECTION mDirection;

};
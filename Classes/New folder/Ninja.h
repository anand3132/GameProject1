#pragma once

#include "cocos2d.h"
#include "Ninja.h"
#include <stdarg.h>

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
		JuMP,
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
    static Ninja* createNinja();

	Ninja();
	virtual ~Ninja();

    bool initNinja();
	void update(float delta);

	void playIdle();
	void playAttack(NINJA_DIRECTION dir);
	void playRun(NINJA_DIRECTION dir);

	void SetNinjaDirection(NINJA_DIRECTION dir);

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
#pragma once

#include "cocos2d.h"
#include <stdarg.h>

namespace NinjaUtil {
	std::string formatString(const char* format, ...);
};

class Ninja : public cocos2d::Sprite
{
public:
    static Ninja* createNinja();

	Ninja();
	virtual ~Ninja();

    bool initNinja();
	void update(float delta);

	void playAttack();
	void playRun();

private:
	void setCurrentAnimationFrame(int frame);

	std::string spriteFrameFormat;
	int mFrameCount;
	int mCurrentFrame;
	float mElapsedSinceLastFrame;
};
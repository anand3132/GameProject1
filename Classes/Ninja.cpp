#include "Ninja.h"

#define FRAMETIME 0.1f

USING_NS_CC;

namespace NinjaUtil {
	std::string formatString(const char* format, ...) {
		char output[FILENAME_MAX];
		va_list v;
		va_start(v, format);
		vsprintf(output, format, v);
		va_end(v);
		return std::string(output);
	}
};

Ninja::Ninja() : 
	cocos2d::Sprite() {
	cocos2d::log("Ninja created");
}

Ninja::~Ninja() {
	cocos2d::log("Ninja destroyed");
}

Ninja* Ninja::createNinja() {
	Ninja *ninja = new (std::nothrow) Ninja();
	if (ninja && ninja->initNinja()) {
		ninja->autorelease();
		return ninja;
	}
	CC_SAFE_DELETE(ninja);
	return nullptr;
}

// on "init" you need to initialize your instance
bool Ninja::initNinja() {
	Sprite::init();

	//mCurrentFrame = 0;
	//mElapsedSinceLastFrame = 0.0f;
	//mFrameCount = 10;
	//this->spriteFrameFormat = spriteFrameFormat;

	//setCurrentAnimationFrame(0);

	playRun();

	scheduleUpdate();
    return true;
}

void  Ninja::setCurrentAnimationFrame(int frame) {
	if (frame >= mFrameCount) return;

	mCurrentFrame = frame;
	auto modifiedPath = NinjaUtil::formatString(spriteFrameFormat.c_str(), frame);
	auto spriteFrame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(modifiedPath);
	initWithSpriteFrame(spriteFrame);
}

void Ninja::update(float delta) {
	mElapsedSinceLastFrame += delta;

	if (mElapsedSinceLastFrame >= FRAMETIME) {
		mElapsedSinceLastFrame = 0.0f;
		mCurrentFrame = ((mCurrentFrame + 1) % mFrameCount);
		setCurrentAnimationFrame(mCurrentFrame);
	}
}

void Ninja::playAttack() {
	spriteFrameFormat = "Attack__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
}

void Ninja::playRun() {
	spriteFrameFormat = "Run__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
}


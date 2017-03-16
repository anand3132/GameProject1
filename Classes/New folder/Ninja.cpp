#include "Ninja.h"

#define FRAMETIME 0.1f

USING_NS_CC;

namespace NinjaUtil 
{
	std::string formatString(const char* format, ...)
	{
		char output[FILENAME_MAX];
		va_list v;
		va_start(v, format);
		vsprintf(output, format, v);
		va_end(v);
		return std::string(output);
	}
};

Ninja::Ninja() : cocos2d::Sprite()
{
	cocos2d::log("Ninja created");
}

Ninja::~Ninja()
{
	cocos2d::log("Ninja destroyed");
}

Ninja* Ninja::createNinja()
{
	Ninja *ninja = new (std::nothrow) Ninja();
	if (ninja && ninja->initNinja()) 
	{
		ninja->autorelease();
		return ninja;
	}
	CC_SAFE_DELETE(ninja);
	return nullptr;
}

// on "init" you need to initialize your instance
bool Ninja::initNinja() 
{
	Sprite::init();

	//mCurrentFrame = 0;
	//mElapsedSinceLastFrame = 0.0f;
	//mFrameCount = 10;
	//this->spriteFrameFormat = spriteFrameFormat;

	//setCurrentAnimationFrame(0);
	SetNinjaDirection(RIGHT);
	playIdle();

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

	auto loc = getPosition();
	switch (mState)
	{
	case Ninja::IDLE:
		break;
	case Ninja::RUN: {
		float speed = 70.0f * delta;
		if (mDirection == LEFT) {
			setPosition(loc.x -= (speed), loc.y);
		}
		else if (mDirection == RIGHT){
			setPosition(loc.x += (speed), loc.y);
		}
		break;
	}
	case Ninja::JuMP:
		
		break;
	case Ninja::CRAWL:
		break;
	case Ninja::ATTACK:
		break;
	case Ninja::DIE:
		break;
	default:
		break;
	}
}

void Ninja::playIdle() {
	spriteFrameFormat = "Idle__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
	SetState(IDLE);
}

void Ninja::playAttack(NINJA_DIRECTION dir) {
	spriteFrameFormat = "Attack__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
	SetState(ATTACK);
	SetNinjaDirection(dir);
}

void Ninja::playRun(NINJA_DIRECTION dir) {
	if (dir==NINJA_DIRECTION::LEFT)
		spriteFrameFormat = "RunL__%03d.png";
	else if (dir == NINJA_DIRECTION::RIGHT)
		spriteFrameFormat = "RunR__%03d.png";

	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
	SetState(RUN);
	SetNinjaDirection(dir);
}

void Ninja::SetState(NINJA_STATE state) {
	NINJA_STATE prevState = mState;
	mState = state;
	if (prevState != state) {
		OnStateChange(prevState, state);
	}
}

void Ninja::SetNinjaDirection(NINJA_DIRECTION dir) {
	NINJA_DIRECTION prevDir = mDirection;
	mDirection = dir;
	if (prevDir != dir) {
		OnDirectionChange(prevDir, dir);
	}
}

void Ninja::OnStateChange(NINJA_STATE prevState, NINJA_STATE curState) {

}

void Ninja::OnDirectionChange(NINJA_DIRECTION prevDir, NINJA_DIRECTION curDir) {

}
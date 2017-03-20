#include "GameInclude.h"
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

Ninja* Ninja::createNinja(float scale, cocos2d::Vec2 pos)
{
	Ninja *ninja = new (std::nothrow) Ninja();
	if (ninja && ninja->initNinja(scale, pos)) 
	{
		ninja->autorelease();
		return ninja;
	}
	CC_SAFE_DELETE(ninja);
	return nullptr;
}

// on "init" you need to initialize your instance
bool Ninja::initNinja(float scale, cocos2d::Vec2 pos)
{
	if (!Sprite::init())
	{
		return false;
	}

	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;

	//setCurrentAnimationFrame(0);
	setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	setNinjaDirection(RIGHT);
	playIdle(NINJA_DIRECTION::RIGHT);

	setScale(scale);
	setPosition(pos);

	scheduleUpdate();
    return true;
}

void  Ninja::setCurrentAnimationFrame(int frame) {
	if (frame >= mFrameCount) return;

	mCurrentFrame = frame;
	auto modifiedPath = NinjaUtil::formatString(spriteFrameFormat.c_str(), frame);
	auto spriteFrame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(modifiedPath);
	setSpriteFrame(spriteFrame);
}

void Ninja::update(float delta) {
	mElapsedSinceLastFrame += delta;
	auto loc = getPosition();

	if (mElapsedSinceLastFrame >= FRAMETIME) {
		mElapsedSinceLastFrame = 0.0f;
		mCurrentFrame = ((mCurrentFrame + 1) % mFrameCount);
		setCurrentAnimationFrame(mCurrentFrame);
	}

	switch (mState)	{
	case Ninja::IDLE: {
		if (mDirection == LEFT)
			setFlippedX(true);
		else if (mDirection == RIGHT)
			setFlippedX(false);
	break;
	}
	case Ninja::RUN: {
		float speed = 70.0f * delta;
		if (mDirection == LEFT) {
			setFlippedX(true);
			setPosition(loc.x -= (speed), loc.y);
		}
		else if (mDirection == RIGHT) {
			setFlippedX(false);
			setPosition(loc.x += (speed), loc.y);
		}
		break;
	}
	case Ninja::JUMP: {
 		float speed = 70.0f * delta;
		if (mDirection == LEFT) {
			setFlippedX(true);
			setPosition(loc.x -= (speed), loc.y);
		}
		else if (mDirection == RIGHT) {
			setFlippedX(false);
			setPosition(loc.x += (speed), loc.y);
		}
		break;
	}
	case Ninja::CRAWL: {
		float speed = 70.0f * delta;
		if (mDirection == UP) { 
			setPosition(loc.x, loc.y -= (speed)); 
		}
		else if (mDirection == DOWN) {
			setPosition(loc.x, loc.y += (speed)); 
		}
		break;
	}
	case Ninja::ATTACK: {
		if (mDirection == LEFT) {
			setFlippedX(true);
		}
		else if (mDirection == RIGHT) {
			setFlippedX(false);
		}
		break;
	}
	case Ninja::DIE: {
		break;
	}
	default:
		break;
	}//switch
}

void Ninja::playIdle(NINJA_DIRECTION dir) {
	spriteFrameFormat = "Idle__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
	SetState(IDLE);
}
void Ninja::playRun(NINJA_DIRECTION dir) {
	spriteFrameFormat = "Run__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
	SetState(RUN);
	setNinjaDirection(dir);
}
void Ninja::playAttack() {
	spriteFrameFormat = "Attack__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
	SetState(ATTACK);
}
void Ninja::playCrawl() {
	spriteFrameFormat = "CRAWL__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
	SetState(RUN);
}

void Ninja::playJump() {
	spriteFrameFormat = "Jump__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
	SetState(JUMP);
}

void Ninja::jumpAttack() {
	spriteFrameFormat = "JumpAttack__%03d.png";
	mFrameCount = 10;
	mCurrentFrame = 0;
	mElapsedSinceLastFrame = 0.0f;
	setCurrentAnimationFrame(mCurrentFrame);
	SetState(JUMPATTACK);
}

void Ninja::SetState(NINJA_STATE state) {
	NINJA_STATE prevState = mState;
	mState = state;
	if (prevState != state) {
		OnStateChange(prevState, state);
	}
}

void Ninja::setNinjaDirection(NINJA_DIRECTION dir) {
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
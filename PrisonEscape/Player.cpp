#include "Player.h"


Player::Player(b2Vec2 pos, b2Vec2 size, SDL_Renderer* renderer)
:Entity(pos, size, renderer)
{
}


Player::~Player(void)
{
}


void Player::Update()
{

	if (true == KeyboardManager::getKeys()->Key_Up)
	{
		mPos.y -= 0.1;
	}
	if (true == KeyboardManager::getKeys()->Key_Down)
	{
		mPos.y += 0.1;
	}
	if (true == KeyboardManager::getKeys()->Key_Left)
	{
		mPos.x -= 0.1;
	}
	if (true == KeyboardManager::getKeys()->Key_Right)
	{
		mPos.x += 0.1;
	}

}
#include "Enemy.h"


Enemy::Enemy(b2Vec2 pos, b2Vec2 size, SDL_Renderer* renderer) :Entity(pos, size, renderer)
{
	/*Text
	font = TTF_OpenFont("Fonts/myFont.ttf", 44);

	// Write text to surface
	text_color.r = 0;
	text_color.b = 0;
	text_color.g = 0;
	surfaceMessage = TTF_RenderText_Solid(font, "Score: ", text_color);
	Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	Message_rect; //create a rect
	Message_rect.x = 10;
	Message_rect.y = 10;
	Message_rect.w = 100;
	Message_rect.h = 100;*/
	attacks = std::map<string, int>();
	feildOfView = new Entity(b2Vec2(400, 400), b2Vec2(100, 100), renderer);
}


Enemy::~Enemy()
{
}

void Enemy::Damage(string attack)
{
	attacks[attack] = attacks[attack]++;
}

void Enemy::Update()
{
	if (false == playerDetected &&
	   (int)mPos.x != (int)originalPos.x &&
	   (int)mPos.y != (int)originalPos.y)
	{
		SetDirection(originalPos);
	}
	if (playerDetected || 
	   (!playerDetected && 
	   (int)mPos.x != (int)originalPos.x &&
	   (int)mPos.y != (int)originalPos.y))
	{
		mPos.x += direction.x / 100;
		mPos.y += direction.y / 100;
	}
	else if (!playerDetected && (int)mPos.x == (int)originalPos.x &&
		(int)mPos.y == (int)originalPos.y)
	{//
		
	}
	CheckViewPos();
}

void Enemy::CheckViewPos()
{
	feildOfView->mPos.y = (direction.y*100) + (mPos.y - (mSize.y * 0.5f));
	feildOfView->mPos.x = (direction.x*100) + (mPos.x - (mSize.x * 0.5f));
}

void Enemy::Draw()
{ 
	//SDL_Rect stretchRect;
	stretchRect->x = mPos.x;//mBody->GetPosition().x;
	stretchRect->y = mPos.y;//mBody->GetPosition().y;
	stretchRect->w = mSize.x;
	stretchRect->h = mSize.y;
	feildOfView->Draw();
	ResourceManager::GetInstance()->Draw(m_image,stretchRect);
	//SDL_RenderCopy(mRenderer, mSprite, NULL, stretchRect);
}
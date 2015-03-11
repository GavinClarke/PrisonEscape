#pragma once
#include <Entity.h>

class Player: public Entity
{
public:
	Player(b2Vec2 pos, b2Vec2 size, SDL_Renderer* renderer);
	~Player(void);
	void Update();
};


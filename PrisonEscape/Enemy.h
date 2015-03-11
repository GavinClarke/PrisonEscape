#pragma once
#include "Entity.h"
#include <map>
#include <string>

class Enemy : public Entity
{
public:
	
	std::map<string, int> attacks;

	Enemy(b2Vec2 pos, b2Vec2 size, SDL_Renderer* renderer);
	~Enemy();
	Entity * feildOfView;
	void Damage(string attack);
	void CheckViewPos();
	void Update();
	void Draw();
	
};


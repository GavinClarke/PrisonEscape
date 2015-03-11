#include <SDL_image.h>
#include <Box2D\Box2D.h>
#include <Enemy.h>
#include <Player.h>

#pragma once
class Game
{
private:
	SDL_Renderer* m_Renderer;
	b2World* m_World;	
	Player * player;/*delete this is for testing*/
	Entity * view;/*delete this is for testing*/
	Enemy * enemy;/*delete this is for testing*/
	Entity * hidingSpot;/*delete this is for testing*/
	bool pressed;
public:
	Game(SDL_Renderer* renderer, b2World* bworld);
	~Game(void);
	void update(double deltaTime);
};


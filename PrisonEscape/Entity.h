#pragma once

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdlib.h>     
#include <time.h>  
#include <KeyboardManager.h>
#include <iostream>
#include <vector>
#include <ResourceManager.h>

class Entity
{
private:	
	
	
public:
	b2Vec2 originalPos;
	bool playerDetected;
	b2Vec2 mPos;
	SDL_Rect * stretchRect;
	string m_image;
	int * m_speed;
	Entity(b2Vec2 pos, b2Vec2 size, SDL_Renderer* renderer);
	~Entity(void);
	//
	b2Vec2 mSize;
	SDL_Renderer* mRenderer;
	b2World* mWorld;
	b2Body* mBody;
	//SDL_Rect * viewRect;
	SDL_Texture* mTexture;
	b2Vec2 direction;

	bool Collision(Entity * ent);
	void Update();
	void SetDirection(b2Vec2 ent);
	void Draw();
	void Draw(int angle);
	b2Vec2 getSize();
};


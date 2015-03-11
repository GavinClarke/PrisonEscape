#pragma once
#include <Entity.h>

class ViewField:public Entity
{
public:
	ViewField(b2Vec2 pos, b2Vec2 size, SDL_Renderer* renderer);
	~ViewField(void);

};


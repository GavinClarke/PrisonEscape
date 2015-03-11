#include "Game.h"


Game::Game(SDL_Renderer* renderer,b2World* bworld) : m_Renderer(renderer), m_World(bworld)
{
	ResourceManager::GetInstance()->Init(m_Renderer);
	ResourceManager::GetInstance()->LoadAssets();
	player = new Player(b2Vec2(100, 100), b2Vec2(50, 50), m_Renderer);
	//view = new Entity(b2Vec2(400, 400), b2Vec2(100, 100), m_Renderer);
	enemy = new Enemy(b2Vec2(600, 400), b2Vec2(50, 50), m_Renderer);
	hidingSpot = new Entity(b2Vec2(600, 600), b2Vec2(50, 50), m_Renderer);
	pressed = false;
}


Game::~Game(void){}

void Game::update(double deltaTime){	
	float32 timeStep = deltaTime;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	
	m_World->Step(timeStep, velocityIterations, positionIterations);	

	SDL_RenderClear( m_Renderer );
	//draw stuff
	player->Update();
	
	/*if (true == view->Collision(player) ||true == enemy->playerDetected )
	{
		enemy->SetDirection(player->mPos);
		enemy->playerDetected = true;
	}*/
	if (true == hidingSpot->Collision(player))
	{
		enemy->playerDetected = false;
	}

	if (true == KeyboardManager::getKeys()->Key_A && false == pressed)
	{
		enemy->Damage("long");
		pressed = true;
	}
	else if (true == KeyboardManager::getKeys()->Key_S && false == pressed)
	{
		enemy->Damage("short");
		pressed = true;
	}
	else if (true == KeyboardManager::getKeys()->Key_D && false == pressed)
	{
		enemy->Damage("medium");
		pressed = true;
	}
	
	if (false == KeyboardManager::getKeys()->Key_A &&
		false == KeyboardManager::getKeys()->Key_S && 
		false == KeyboardManager::getKeys()->Key_D)
	{
		pressed = false;
	}

	enemy->Update();
	player->Draw();
	//view->Draw();
	enemy->Draw();
	hidingSpot->Draw();
	SDL_RenderPresent( m_Renderer );
}

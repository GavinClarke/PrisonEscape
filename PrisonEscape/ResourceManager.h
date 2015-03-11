#pragma once
#include <vector>
#include <map>
#include <SDL_image.h>
#include <string>

class ResourceManager
{
private:
	static ResourceManager * m_instance;//singleton instance for enemy manager 
	std::map<std::string, SDL_Texture*> m_textureMap;
	SDL_Renderer * m_Renderer;
public:

	static ResourceManager * GetInstance();
	ResourceManager(void);
	~ResourceManager(void);
	void Init(SDL_Renderer * p_Renderer);//initializes the sdl renderer so that the resource manager can draw the images.
	void LoadAssets();// this will load the assets required for the game.
	void Draw(std::string p_imageName, SDL_Rect * p_size);// this will draw the images using the name of the image.
};


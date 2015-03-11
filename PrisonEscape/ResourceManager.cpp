#include "ResourceManager.h"

ResourceManager * ResourceManager::m_instance = NULL;

ResourceManager::ResourceManager(void)
{
	m_textureMap = std::map<std::string, SDL_Texture*> ();
}


ResourceManager::~ResourceManager(void)
{
}

ResourceManager * ResourceManager::GetInstance()
{
	if(NULL == m_instance)
	{
		m_instance = new ResourceManager();
	}
	return m_instance;
}

void ResourceManager::Init(SDL_Renderer * p_Renderer)
{
	m_Renderer = p_Renderer;
}

void ResourceManager::LoadAssets()
{
	m_textureMap["block"] = SDL_CreateTextureFromSurface(m_Renderer, IMG_Load("images\\block.png"));
}

void ResourceManager::Draw(std::string p_imageName, SDL_Rect * p_size)
{
	

	SDL_RenderCopy ( m_Renderer, m_textureMap[p_imageName], NULL, p_size); 
}
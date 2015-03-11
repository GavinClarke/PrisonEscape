#include "EnemyManager.h"

EnemyManager * EnemyManager::m_instance = NULL;

EnemyManager::EnemyManager(void)
{

}

EnemyManager::~EnemyManager(void)
{
}

EnemyManager * EnemyManager::GetInstance()
{
	if(NULL == m_instance)
	{
		m_instance = new EnemyManager();
	}
	return m_instance;
}
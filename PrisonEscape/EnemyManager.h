#pragma once
#include <Enemy.h>

class EnemyManager
{
private:

	static EnemyManager * m_instance;//singleton instance for enemy manager 
	EnemyManager(void);
	vector <Enemy *> m_enemies;

public:

	static EnemyManager * GetInstance();
	void CreateEnemies();
	~EnemyManager(void);
};


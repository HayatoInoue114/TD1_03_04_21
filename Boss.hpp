#pragma once
#include "Entity.hpp"



class Boss : public Entity
{
public:
	Boss();
	using Entity::Entity;

	void BossDraw();

	void Reset();

	void Spawn();

	int interval = 30;

	void Despawn();

	void HitCore();     

	static void HitDamage();

	/*static void AttackSpawn();

	static void Attack();

	static void AttackReset();*/

	static Vector2 statePosition;
	static Vector2 endPosition;
	static Vector2 nowEndPosition;
	static Vector2 ballPosition;

	static bool attackFlag;
	static int count;
	static int hp;
	static int kEndPosition;
};

void EnemySpawn();


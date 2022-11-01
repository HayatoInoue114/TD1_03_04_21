#pragma once
#include "Entity.hpp"

#include "PolarCoordinates.hpp"

class Enemy : public Entity
{
public:
	Enemy();
	using Entity::Entity;

	void DrawEntity();

	void Reset();

	void Spawn();
	void Spawn(PolarCoordinates);

	int interval = 30;

	void Despawn();

	void HitCore();

	void Shake();
	void ShakeUpdate();

	PolarCoordinates ShakeData = {0,0};
};
const int EnemyMax = 100;

static Enemy enemy[EnemyMax] = {};
void EnemySpawn();


static int killScore;
static int killCount;

static int spawnFlame = 180;

static int onceKillCount = 1;

static int totalKill = 0;


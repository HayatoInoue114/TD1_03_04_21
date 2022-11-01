#include "Enemy.hpp"


#include "BaseData.hpp"
#include "Camera.hpp"

#include "Math.hpp"
#include "PolarCoordinates.hpp"
#include "Vector2.hpp"

#include "Map.hpp"

#include "Audio.hpp"

#include"Scene.hpp"

Enemy::Enemy() 
{

}

void Enemy::DrawEntity() {
	if (isAlive) {
		AnimationUpdate();
		DrawQuadFunction(position + PolarToVector2(ShakeData), {radius * 2,radius * 2}, srcX, srcY, srcW, srcH, textureHandle, Vector2ToPolar(velocity * -1).theta, color);
		//	Novice::DrawEllipse(position.x, ToWorld(position.y), radius, radius, 0.0f, RED, kFillModeWireFrame);
	}
}

void Enemy::Reset() {
	position = MiddleCentor;

//	resetCount++;

	isAlive = false;

	
	
	
}

void Enemy::Spawn() {

	textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/enemy1.png");
	srcH = 176;
	srcW = 176;

	needNextFlame = 0;
	maxFlame = 1;

    radius = 48;
	color = 0xFFFFFFFF;


	PolarCoordinates test;

	test.radius = GetRandom(MapRadius * 2,MapRadius * 2.5);

	test.theta = Degree2Radian(GetRandom(0, 360));

	Shake();

	position = PolarToVector2(test) + MapCentor;

	speed = 2;

	velocity = Nomalize((PolarToVector2(test) * -1)) * speed;

	isAlive = true;

	Novice::PlayAudio(SpawnSE, false, 0.1f);
}

void Enemy::Spawn(PolarCoordinates polar) {

	textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/enemy1.png");
	srcH = 176;
	srcW = 176;

	needNextFlame = 0;
	maxFlame = 1;

    radius = 48;
	color = 0xFFFFFFFF;

	Shake();

	position = PolarToVector2(polar) + MapCentor;

	speed = 2;

	velocity = Nomalize((PolarToVector2(polar) * -1)) * speed;

	isAlive = true;

	Novice::PlayAudio(SpawnSE, false, 0.1f);
}

void EnemySpawn() {
	for (int i = 0; i < EnemyMax; i++) {
		if (!enemy[i].isAlive) {
			enemy[i].Spawn();
			break;
		}
	}
}

void Enemy::Despawn() {

	if (isAlive) {
		
		HitCore();
	}
}

void Enemy::HitCore() {
	
	if (BallCollision(position, radius, MapCentor, 30)) {
		Camera::Shake({ 20,20 }, 30);

		Novice::PlayAudio(MapHitSE, false, 0.1f);
		
		Reset();
	}
}

void Enemy::Shake() {
	ShakeData.radius = 20;
}

void Enemy::ShakeUpdate() {
	if (ShakeData.radius > 0) {
		ShakeData.theta += Degree2Radian(75);
		ShakeData.radius -= 2;
	}
	else if (ShakeData.radius < 0) {
		ShakeData.radius = 0;
	}
}
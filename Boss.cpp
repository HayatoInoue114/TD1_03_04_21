#include"Boss.hpp"

#include "BaseData.hpp"
#include "Camera.hpp"

#include "Math.hpp"
#include "PolarCoordinates.hpp"
#include "Vector2.hpp"

#include "Map.hpp"

Boss::Boss() {

}

bool Boss::attackFlag = false;
Vector2 Boss::statePosition = {};
Vector2 Boss::endPosition = {};
Vector2 Boss::nowEndPosition = {};
Vector2 Boss::ballPosition = {};
int Boss::count = 0;
int Boss::hp = 30;
int Boss::kEndPosition = 0;


void Boss::BossDraw() {
//	DrawEntity();
	
	DrawQuadFunction((statePosition - endPosition) * 0.5 + endPosition + (statePosition - endPosition).Nomalize() * 564, {564 * 2,8 * 2}, 0, 0, 8, 564, Novice::LoadTexture("./Resources/Texture/Entity/Enemy/wire.png"), Vector2ToPolar(statePosition - endPosition).theta + Degree2Radian(0), 0xFFFFFFFF);
	DrawQuadFunction((statePosition - endPosition) * 0.5 + endPosition + (statePosition - endPosition).Nomalize() * -564, { 564 * 2,8 * 2 }, 0, 0, 8, 564, Novice::LoadTexture("./Resources/Texture/Entity/Enemy/wire.png"), Vector2ToPolar(statePosition - endPosition).theta + Degree2Radian(0), 0xFFFFFFFF);
	

}



void Boss::Reset() {
	position = MiddleCentor;
	radius = 256;

	textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/Arrow.png");
	srcH = 128;
	srcW = 128;
	needNextFlame = 30;
	maxFlame = 2;

	isAlive = false;
}

void Boss::Spawn() {

	textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/Arrow.png");
	srcH = 128;
	srcW = 128;

	needNextFlame = 180;
	maxFlame = 2;

	radius = 256;
	color = 0xFFFFFFFF;


	PolarCoordinates test;

	test.radius = GetRandom(MapRadius * 2, MapRadius * 2.5);

	test.theta = Degree2Radian(GetRandom(0, 360));

	position = statePosition;

	speed = 2;

	if (count > 60) {
		velocity = Nomalize((PolarToVector2(test) * -1)) * speed;

	}
	

	isAlive = true;
}



void Boss::Despawn() {

	
}

void Boss::HitCore() {
	if (BallCollision(position, radius, MapCentor, 30)) {
		Camera::Shake({ 20,20 }, 30);
		Reset();
	}
}


void Boss::HitDamage() {
	Boss::hp -= 1;
	Boss::attackFlag = false;
}


//void Boss::AttackSpawn() {
//	if (endPosition.y > 0) {
//		nowEndPosition.y -= 10;
//	}
//
//	statePosition.x = GetRandom(MiddleCentor.x - MapRadius, MiddleCentor.x + MapRadius);
//	statePosition.y = ScreenSize.y;
//
//	endPosition.x= GetRandom(MiddleCentor.x - MapRadius, MiddleCentor.x + MapRadius);
//	endPosition.y = statePosition.y + nowEndPosition.y;
//
//	if (flame % 120 == 0 && flame != 0 && !attackFlag) {
//		attackFlag = true;
//	}
//}
//
//void Boss::Attack() {
//	
//
//	Novice::DrawLine(statePosition.x, statePosition.y, endPosition.x, endPosition.y, 0xff00ffff);
//
//	count++;
//
//	            
//
//}
//
//void Boss::AttackReset() {
//	Camera::Shake({ 20,20 }, 10);
//
//	attackFlag = false;
//	statePosition = {};
//	endPosition = {};
//}
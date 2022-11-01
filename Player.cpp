#include "Player.hpp"

#include <Novice.h>

#include "BaseData.hpp"
#include "Controller.hpp"

#include "Map.hpp"
#include "Math.hpp"

#include "Entity.hpp"
#include "Bullet.hpp"
#include "Particle.hpp"

#include "Camera.hpp"
#include "Audio.hpp"

//#include"Boss.hpp"



void Player::DrawEntity() {
	AnimationUpdate();

	//	Novice::DrawLine(position.x, ToWorld(position.y), prePosition.x, ToWorld(prePosition.y), 0xFF0000FF);
	if (nowPolar.theta != prePolar.theta) {

		for (int i = (position - (PolarToVector2(nowPolar) + MapCentor)).Length() / ((float)152 / 3) + 1; i < (PolarToVector2(prePolar) - PolarToVector2(nowPolar)).Length() / ((float)152 / 3); i++) {
			DrawQuadFunction(PolarToVector2(nowPolar) + MapCentor + (PolarToVector2(prePolar) - PolarToVector2(nowPolar)).Nomalize() * 152 / 3 * (i), Vector2{ 152,152 } *0.47, 0, 0, 152, 152, PlayerGuide, Vector2ToPolar(prePosition - position).theta + Degree2Radian(180), ColorEasingMove(0xFFFFFFBB,0xFFFFFF33, easeInCirc((float)i / ((PolarToVector2(prePolar) - PolarToVector2(nowPolar)).Length() / ((float)152 / 3)))));
		}

		DrawQuadFunction(position, { radius * 2,radius * 2 }, srcX, srcY, srcW, srcH, textureHandle, Vector2ToPolar((PolarToVector2(nowPolar) - PolarToVector2(prePolar)) * -1).theta, color);
	//	DrawQuadFunction(prePosition, { radius * 2,radius * 2 }, srcX, srcY, srcW, srcH, textureHandle, Vector2ToPolar((PolarToVector2(nowPolar) - PolarToVector2(prePolar)) * -1).theta, (color & 0xFFFFFF00) + (color & 0xFF) / 2);

		/*
			DrawQuadFunction(PolarToVector2(nowPolar) + MapCentor + (PolarToVector2(prePolar) - PolarToVector2(nowPolar)).Nomalize() * 152 / 3 * 2, Vector2{ 152,152 } * 0.42, 0, 0, 152, 152, PlayerGuide, Vector2ToPolar(prePosition - position).theta + Degree2Radian(180), 0xFFFFFF88);

			DrawQuadFunction(PolarToVector2(nowPolar) + MapCentor + (PolarToVector2(prePolar) - PolarToVector2(nowPolar)).Nomalize() * 152, Vector2{ 152,152 } * 0.35, 0, 0, 152, 152, PlayerGuide, Vector2ToPolar(prePosition - position).theta + Degree2Radian(180), 0xFFFFFF66);

			DrawQuadFunction(PolarToVector2(nowPolar) + MapCentor + (PolarToVector2(prePolar) - PolarToVector2(nowPolar)).Nomalize() * 152 / 3 * 4, Vector2{ 152,152 } * 0.3, 0, 0, 152, 152, PlayerGuide, Vector2ToPolar(prePosition - position).theta + Degree2Radian(180), 0xFFFFFF33);
		*/
	}
	else {
		DrawQuadFunction(position, { radius * 2,radius * 2 }, srcX, srcY, srcW, srcH, textureHandle, nowPolar.theta + Degree2Radian(90) * reverse, color);
	}
}


Player::Player()
{

}


void Player::EntityUpdate() {
	if (!isInput) {

		position += velocity;

		if (
			(Length(PolarToVector2(nowPolar), PolarToVector2(prePolar)))
			<=
			(Length(position, MapCentor + PolarToVector2(nowPolar)))
			)
		{
			//	position = Nomalize(Vector2Difference(PolarToVector2(nowPolar), PolarToVector2(prePolar))) * Clamp((Vector2Difference(PolarToVector2(nowPolar), position)).Length(), 0, (Vector2Difference(PolarToVector2(nowPolar), PolarToVector2(prePolar))).Length());

			position = prePosition;

			if (velocity.Length() != 0) {

				/*reverse *= -1;*/

				BulletShooting();

				
				if (Length(PolarToVector2(nowPolar), PolarToVector2(prePolar)) > 152) {
					particleTest.Spawn(position, 15, 0xFF4444FF,7);
				}

			}

			velocity = ZeroVector2;
			nowPolar = Vector2ToPolar(position - MapCentor);
			nowPolar.radius = MapRadius;
			prePolar = nowPolar;
			prePosition = MapCentor + PolarToVector2(prePolar);
		}
	}
}


void Player::BulletShooting() {

	Novice::PlayAudio(BulletShootingSE, false, 0.025f);

	for (int i = 0; i < Bullet::BulletMaxCount; i++) {		//バレットスポーン関数
		if (!Bullet::bullet[i].isAlive) {
			Bullet::bullet[i].isAlive = true;
			Bullet::bullet[i].velocity = this->velocity;
			Bullet::bullet[i].position = this->position;

			Novice::PlayAudio(BulletShootingSE, false, 0.025f);

			break;
		}
	}

}

void Player::Reset(int count) {
	*this = Player(Novice::LoadTexture("./Resources/Texture/Entity/Player/Idle/love.png"), 152, 152, 0, 1);

	PlayerGuide = Novice::LoadTexture("./Resources/Texture/Entity/Player/Idle/Arrow.png");

	position = MiddleCentor;
	velocity.Reset();
	radius = 32;

	speed = 30;

	nowPolar.radius = MapRadius;
	switch (count) {
	case 0:
		nowPolar.theta = Degree2Radian(0);
		break;
	case 1:
		if (playerCount == 2) {
			nowPolar.theta = Degree2Radian(180);
		}
		else {
			nowPolar.theta = Degree2Radian(120);
		}
		break;
	case 2:
		nowPolar.theta = Degree2Radian(240);
		break;
	}
	prePolar = nowPolar;

	position = MapCentor + PolarToVector2(nowPolar);
	prePosition = position;
}

//void Player::BossAttackHit() {
//	if (Ellipse2LineLength(position, Boss::statePosition, Boss::endPosition) == radius) {
//		Boss::AttackReset();
//		Boss::hp -= 1;
//	}
//}


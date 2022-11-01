#include"Bullet.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include "Player.hpp"

#include"Enemy.hpp"

#include "Audio.hpp"


BulletClass::BulletClass()
{
}



Bullet::Bullet()
{
}

BulletClass Bullet::bullet[BulletMaxCount] = {  };

void Bullet::Reset(int index)
{
	bullet[index].isAlive = false;

}

void Bullet::DrawBullet() {
	for (int i = 0; i < BulletMaxCount; i++) {
		if (bullet[i].isAlive) {
			bullet[i].AnimationUpdate();
			bullet[i].DrawEntity();
		}
	}
}

void Bullet::OutScreen() {

	for (int i = 0; i < BulletMaxCount; i++) {
		if (bullet[i].position.x < 0 || bullet[i].position.x > ScreenSize.x) {
			bullet[i].isAlive = false;
		}

		if (bullet[i].position.y < 0 || bullet[i].position.y > ScreenSize.y) {
			bullet[i].isAlive = false;
		}

	}
}


void Bullet::BulletDelete() {
	OutScreen();
}

void Bullet::BulletUpdate() {
	for (int i = 0; i < BulletMaxCount; i++) {
		if (bullet[i].isAlive) {
			bullet[i].position += bullet[i].velocity;
		}
	}
}

void Bullet::BulletReset() {
	for (int i = 0; i < BulletMaxCount; i++) {
		bullet[i].radius = 32;
		bullet[i].acceleration.Reset();
		bullet[i].color = 0xffffffff;
		bullet[i].position.Reset();
		bullet[i].velocity.Reset();
		bullet[i].srcX = 0;
		bullet[i].srcY = 0;



		bullet[i].textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Player/Idle/Bullet.png");
		bullet[i].srcH = 152;
		bullet[i].srcW = 152;
		bullet[i].needNextFlame = 0;
		bullet[i].maxFlame = 1;

		
	}
}
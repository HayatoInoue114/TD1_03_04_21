#include "Camera.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include "Vector2.hpp"
#include "Math.hpp"

#include "Easing.hpp"


Camera::Camera() {
}

Vector2 Camera::scroll = ZeroVector2;
Vector2 Camera::scrollReference = ZeroVector2;

Vector2 Camera::shakeRadius = ZeroVector2;
unsigned int Camera::shakeFlame = 0;
unsigned int Camera::maxShakeFlame = 0;

void Camera::Reset() {
	PositionReset();
	EffectReset();
}

void Camera::PositionReset() {
	
	Camera::scroll = ZeroVector2;
	Camera::scrollReference = ZeroVector2;
}

void Camera::EffectReset() {

	Camera::shakeRadius = ZeroVector2;
	Camera::shakeFlame = 0;
	Camera::maxShakeFlame = 0;
}
void Camera::Shake(Vector2 radius, unsigned int flame) {
	maxShakeFlame = flame;
	shakeFlame = 0;
	shakeRadius = radius;
//	scroll = scrollReference + Vector2{(float)(shakeRadius.x * cos(Degree2Radian(shakeFlame * 75))),(float)(shakeRadius.y * sin(Degree2Radian(shakeFlame * 75))) };
}

void Camera::Update() {
	scroll = scrollReference;

//	ScreenSize

	if (maxShakeFlame != 0) {
		if (maxShakeFlame > shakeFlame) {
			shakeFlame++;
			scroll = Vector2{
			(float)(shakeRadius.x * cos(Degree2Radian(shakeFlame * 75)) * (1 - (float)(shakeFlame) / maxShakeFlame)),
			(float)(shakeRadius.y * sin(Degree2Radian(shakeFlame * 75)) * (1 - (float)(shakeFlame) / maxShakeFlame))
			};
		}
		else {
			Reset();
		}
		
	}
}
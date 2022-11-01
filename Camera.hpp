#pragma once

#include "Vector2.hpp"


class Camera
{
public:
	Camera();

	static Vector2 scrollReference; // スクロール値
	static Vector2 scroll;			// 処理後スクロール値

	static void Reset();
	static void PositionReset();
	static void EffectReset();

	static void Shake(Vector2 radius, unsigned int flame);

	static void Update();

private:

	static Vector2 shakeRadius;
	static unsigned int maxShakeFlame;
	static unsigned int shakeFlame;

};

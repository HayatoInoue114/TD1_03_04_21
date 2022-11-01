#include "Resource.hpp"

#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "BaseData.hpp"
#include "Math.hpp"
#include "Vector2.hpp"
#include "Matrix2x2.hpp"

#include "Camera.hpp"

#include "SpriteClass.hpp"


float ToWorld(float y) {
	return (-(y)+WorldPos);
};

Vector2 ToWorld(Vector2 position) {
	return { position.x,(-(position.y) + WorldPos) };
};

void DrawQuadFunction(Vector2 centor, Vector2 size, int srcX, int srcY, int srcW, int srcH, unsigned int textureHandle, unsigned int color) {
	Novice::DrawQuad((centor.x - Camera::scroll.x) - ((size.x) / 2), ToWorld((centor.y - Camera::scroll.y) + ((size.y) / 2)), (centor.x - Camera::scroll.x) + ((size.x) / 2), ToWorld((centor.y - Camera::scroll.y) + ((size.y) / 2)), (centor.x - Camera::scroll.x) - ((size.x) / 2), ToWorld((centor.y - Camera::scroll.y) - ((size.y) / 2)), (centor.x - Camera::scroll.x) + ((size.x) / 2), ToWorld((centor.y - Camera::scroll.y) - ((size.y) / 2)), srcX, srcY, srcW, srcH, textureHandle, color);
};

void DrawQuadFunction(Vector2 centor, Vector2 size, int srcX, int srcY, int srcW, int srcH, unsigned int textureHandle, float angle, unsigned int color) {
	Vector2 LeftTop = Vector2{ -size.x / 2, size.y / 2 }.Rotate(angle);
	Vector2 LeftDown = Vector2{ size.x / 2, size.y / 2 }.Rotate(angle);
	Vector2 RightTop = Vector2{ -size.x / 2, -size.y / 2 }.Rotate(angle);
	Vector2 RightDown = Vector2{ size.x / 2, -size.y / 2 }.Rotate(angle);
	Novice::DrawQuad((centor.x - Camera::scroll.x) + LeftTop.x, ToWorld((centor.y - Camera::scroll.y) + LeftTop.y), (centor.x - Camera::scroll.x) + RightTop.x, ToWorld((centor.y - Camera::scroll.y) + RightTop.y), (centor.x - Camera::scroll.x) + LeftDown.x, ToWorld((centor.y - Camera::scroll.y) + LeftDown.y), (centor.x - Camera::scroll.x) + RightDown.x, ToWorld((centor.y - Camera::scroll.y) + RightDown.y), srcX, srcY, srcW, srcH, textureHandle, color);
};
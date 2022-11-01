#pragma	once
#include "entity.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include "Resource.hpp"
#include "SpriteClass.hpp"

#include "Math.hpp"


Entity::Entity() : prePosition(ZeroVector2), facing(ZeroVector2), speed(0.0f), isAlive(false)
{

}

void Entity::DrawEntity() {
	if (isAlive) {
		AnimationUpdate();
		DrawQuadFunction(position, { radius * 2,radius * 2 }, srcX, srcY, srcW, srcH, textureHandle, Vector2ToPolar(velocity * -1).theta, color);
		//	Novice::DrawEllipse(position.x, ToWorld(position.y), radius, radius, 0.0f, RED, kFillModeWireFrame);
	}
}




void Entity::EntityMoveUpdate() {
	if (isAlive) {
		prePosition = position;

	//	norm = Length(ZeroVector2, velocity);

		if (velocity.Length() != 0) {
			velocity = velocity.Nomalize() * speed;
			facing = velocity;
			facing.x = Clamp(facing.x, -1, 1);
			facing.y = Clamp(facing.y, -1, 1);
		}

		position += velocity;
	}
};

void Entity::KeepInScreen() {
	position.x = Clamp(position.x, 0 + radius, 1280 - radius);
	position.y = Clamp(position.y, 0 + radius, 720 - radius);
}
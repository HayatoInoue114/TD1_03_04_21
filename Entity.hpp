#pragma once
#include "BaseData.hpp"
#include "SpriteClass.hpp"


class Entity: public Ball, public SpriteClass
{
public:
	Entity();
	Entity(unsigned int textureHandle, int srcW, int srcH, unsigned int needNextFlame, unsigned int maxFlame) : SpriteClass(textureHandle, srcW, srcH, needNextFlame, maxFlame), prePosition(ZeroVector2), facing(ZeroVector2), speed(0) {};
//	~Entity();

	void DrawEntity();
	void EntityMoveUpdate();

	void KeepInScreen();

public:
	Vector2 prePosition;
	Vector2 facing;
	float speed;

	bool isAlive;
};
#pragma once

#include "Vector2.hpp"

#define functionEasing(start , end, easingVolume, easingType)  easingMove(start, end, easingType(easingVolume))
#define easePlane(number) number

float EasingMove(float start, float end, float easingVolume);

Vector2 EasingMove(const Vector2 &start, const Vector2 &end, const float &easingVolume);


int IntEasingMove(long int start, long int end, float easingVolume);

unsigned int ColorEasingMove(unsigned int statColor, unsigned int endColor, float easingVolume);


float easeLinear(float number);
float easeOutBack(float x);
float easeInBack(float x);
float easeOutCirc(float x);
float easeInCirc(float x);
float easeInSine(float x);
float easeOutSine(float x);
float easeInExpo(float x);
float easeOutExpo(float x);

#include"Math.hpp"

#define _USE_MATH_DEFINES
#include<math.h>

#include"Vector2.hpp"
#include "PolarCoordinates.hpp"


float DotProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB) {
	Vector2 a = { ((endA.x) - (startA.x)),((endA.y) - (startA.y))};
	Vector2 b = { ((endB.x) - (startB.x)),((endB.y) - (startB.y))};

	return a.x * b.x + a.y * b.y;
}

float DotProduct(Vector2 VectorA, Vector2 VectorB) {

	return VectorA.x * VectorB.x + VectorA.y * VectorB.y;
}


float CrossProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB) {
	Vector2 a = { ((endA.x) - (startA.x)),((endA.y) - (startA.y)) };
	Vector2 b = { ((endB.x) - (startB.x)),((endB.y) - (startB.y)) };

	return a.x * b.y - a.y * b.x;
}
float CrossProduct(Vector2 VectorA, Vector2 VectorB) {
	return VectorA.x * VectorB.y - VectorA.y * VectorB.x;
}


float Radian2Degree(float radian) {
	return (radian) * 180 / M_PI;
}

float Degree2Radian(float degree) {
	return (degree)*M_PI / 180;
}


Vector2 PolarToVector2(PolarCoordinates Polar) {
	return Vector2{ ((float)cos(Polar.theta) * Polar.radius), ((float)sin(Polar.theta) * Polar.radius) };
}

PolarCoordinates Vector2ToPolar(Vector2 Vector) {
	if (Vector.Length() != 0) {
		return { Vector.Length(), (float)(atan2(Vector.y,Vector.x)) };
	}
	else {
		return { 0,0 };
	}
}


Matrix2x2 MakeRotateMatrix(const float &theta) {
	return Matrix2x2(cos(theta), sin(theta), -sin(theta), cos(theta));
}


int Sum(int value) {
	if (value == 0) {
		return 0;
	}
	else {
		return value + Sum(value - 1);
	}
}
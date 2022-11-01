#include "Vector2.hpp"

#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Matrix2x2.hpp"
#include"Math.hpp"

void Vector2::Reset() {
	*this = ZeroVector2;
}

Vector2 Vector2::Rotate(const float &theta) const {
	return *this * MakeRotateMatrix(theta);
}

float Vector2::Length() const {
	return sqrt(pow(x, 2) + pow(y, 2));
}

Vector2 Vector2::Nomalize() const {
	if (this->Length() != 0) {
		return { (x / this->Length()),(y / this->Length()) };
	}
	else {
		return ZeroVector2;
	}
}

void Vector2::Vector2Printf(int x, int y) const {
	Novice::ScreenPrintf(x, y, "%12.2f", this->x);
	Novice::ScreenPrintf(x, y + TextHeight, "%12.2f", this->y);
}

Vector2 Vector2::operator+(const Vector2& Second) const {
	return { (this->x) + (Second.x), (this->y) + (Second.y) };
}

Vector2 Vector2::operator-(const Vector2& Second) const {
	return { (this->x) - (Second.x), (this->y) - (Second.y) };
}

void Vector2::operator +=(const Vector2& Second) {
	this->x += Second.x;
	this->y += Second.y;
}

void Vector2::operator -=(const Vector2& Second) {
	this->x -= Second.x;
	this->y -= Second.y;
}

Vector2 Vector2::operator*(const float& Second) const {
	return { (this->x) * (Second), (this->y) * (Second) };
}

Vector2 Vector2::operator/(const float& Second) const {
	return { (this->x) / (Second), (this->y) / (Second) };
}

void Vector2::operator *=(const float& Second) {
	this->x *= Second;
	this->y *= Second;
}


void Vector2::operator /=(const float& Second) {
	this->x /= Second;
	this->y /= Second;
}

Vector2 Vector2::operator*(const Matrix2x2& Second) const{
	const Vector2 b[2]{ {Second.m[0][0],Second.m[1][0]},{Second.m[0][1],Second.m[1][1]} };
	return Vector2{
		DotProduct(*this, b[0]),
		DotProduct(*this, b[1])
	};
}

void Vector2::operator*=(const Matrix2x2& Second) {
	const Vector2 b[2]{ {Second.m[0][0],Second.m[1][0]},{Second.m[0][1],Second.m[1][1]} };
	*this = {
		DotProduct(*this, b[0]),
		DotProduct(*this, b[1])
	};
}


Vector2::Vector2() : x(0), y(0)
{
}


Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

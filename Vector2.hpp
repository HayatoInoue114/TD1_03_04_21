#pragma once

#include "Matrix2x2.hpp"

class Vector2
{
public:
	Vector2();
	Vector2(float x,float y);

	float x;
	float y;

	void Vector2Printf(int x, int y) const;

	Vector2 Rotate(const float &theta) const;

	void Reset();

	float Length() const;
	Vector2 Nomalize() const;

	Vector2 operator+(const Vector2& Second) const;
	Vector2 operator-(const Vector2& Second) const;
	

	void operator +=(const Vector2& Second);
	void operator -=(const Vector2& Second);



	Vector2 operator*(const float& Second) const;
	Vector2 operator/(const float& Second) const;

	void operator *=(const float& Second);
	void operator /=(const float& Second);


	Vector2 operator*(const Matrix2x2& Second) const;

	void operator*=(const Matrix2x2& Second) ;


private:

};

/// <summary>
	/// int型の二次元ベクトル
	/// </summary>
	/// <param name="x">横</param>
	/// <param name="y">縦</param>
typedef struct IntVector2 {
	int x;
	int y;
};

const IntVector2 ScreenSize{
	1920,
	1080
};





/// ゼロベクトル
const Vector2 ZeroVector2 = { 0,0 };




/// UIなどの基準値となる座標
const Vector2 MiddleLeftOver = { (float)(-ScreenSize.x / 2), (float)(ScreenSize.y / 2) };
const Vector2 TopLeftOver = { (float)(-ScreenSize.x / 2), (float)(ScreenSize.y) };
const Vector2 DownLeftOver = { (float)(-ScreenSize.x / 2), 0 };

const Vector2 MiddleLeft = { 0, (float)(ScreenSize.y / 2) };
const Vector2 TopLeft = { 0, (float)(ScreenSize.y) };
const Vector2 DownLeft = { 0, 0 };

const Vector2 MiddleCentor = { (float)(ScreenSize.x / 2), (float)(ScreenSize.y / 2) };
const Vector2 TopCentor = { (float)(ScreenSize.x / 2), (float)(ScreenSize.y) };
const Vector2 DownCentor = { (float)(ScreenSize.x / 2), 0 };

const Vector2 MiddleRight = { (float)(ScreenSize.x) , (float)(ScreenSize.y / 2) };
const Vector2 TopRight = { (float)(ScreenSize.x) , (float)(ScreenSize.y) };
const Vector2 DownRight = { (float)(ScreenSize.x) , 0 };

const Vector2 MiddleRightOver = { (float)(ScreenSize.x * 1.5) , (float)(ScreenSize.y / 2) };
const Vector2 TopRightOver = { (float)(ScreenSize.x * 1.5) , (float)(ScreenSize.y) };
const Vector2 DownRightOver = { (float)(ScreenSize.x * 1.5) , 0 };

const Vector2 TopOverCentor = { (float)(ScreenSize.x * 0.5) , (float)(-ScreenSize.y / 2) };
const Vector2 DownOverCentor = { (float)(ScreenSize.x * 0.5) , (float)(ScreenSize.y * 1.5) };


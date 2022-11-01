#pragma once

#include <Novice.h>
#include"Vector2.hpp"

#include "Resource.hpp"


/// (0 <= x <= 10)のような形のマクロ関数
#define isInner(leftNumber,leftOperator,number,rightOperator,rightNumber) (((leftNumber)leftOperator(number)) && ((number)rightOperator(rightNumber)))



/// キーボードの(key)がトリガーされたか
#define isKeyTrigger(key) (keys[key] && !preKeys[key])

/// キーボードの(key)が離されたか
#define isKeyRelease(key) (!keys[key] && preKeys[key])

/// キーボードの(key)が押されているか
#define isKeyPress(key) (keys[key])

// キー入力結果を受け取る箱
static char keys[256] = { 0 };
static char preKeys[256] = { 0 };

// マウス座標を受け取るIntベクトル構造体
static IntVector2 mouse = { 0 }, preMouse = mouse;



// 定数宣言


/// MenuUIの最大項目数
const int SetMaxMenuItem = 16;


// 変数宣言

static int flame = 0;



/// <summary>
	/// Lineクラス
	/// </summary>
	/// <param name="start">始点位置ベクトル</param>
	/// <param name="end">終点位置ベクトル</param>
	/// <param name="norm">ノルム</param>
	/// <param name="color">色 0xRRGGBBAA</param>
class Line
{
public:
	Vector2 start;
	Vector2 end;
	float norm;
	unsigned int color;

	void DrawLine();
};


/// <summary>
	/// Ballクラス
	/// </summary>
	/// <param name="position">位置ベクトル</param>
	/// <param name="velocity">移動速度ベクトル</param>
	/// <param name="acceleration">加速度ベクトル</param>
	/// <param name="radius">半径</param>
	/// <param name="norm">ノルム</param>
	/// <param name="mass">重量</param>
	/// <param name="color">色 0xRRGGBBAA</param>
class Ball
{
public:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	float radius;
	float norm;
	float mass;
	unsigned int color = 0xFFFFFFFF;
};

/// <summary>
	/// Boxクラス
	/// </summary>
	/// <param name="position">位置ベクトル</param>
	/// <param name="velocity">移動速度ベクトル</param>
	/// <param name="acceleration">加速度ベクトル</param>
	/// <param name="radius">半径</param>
	/// <param name="norm">ノルム</param>
	/// <param name="mass">重量</param>
	/// <param name="color">色 0xRRGGBBAA</param>
class Box
{
public:
	Vector2 position = ZeroVector2;
	Vector2 velocity = ZeroVector2;
	Vector2 acceleration = ZeroVector2;
	Vector2 radius = ZeroVector2;
	float norm = 0;
	float mass = 0;
	unsigned int color = 0;
};

/// <summary>
/// 乱数生成関数
/// </summary>
/// <param name="min">下限</param>
/// <param name="max">上限</param>
/// <returns>乱数</returns>
int GetRandom(int min, int max);


/// <summary>
/// 位置ベクトルAからBへの長さを出す関数
/// </summary>
/// <param name="start">始点位置ベクトル</param>
/// <param name="end">終点位置ベクトル</param>
/// <returns>AからBへの長さ</returns>
float Length(Vector2 start, Vector2 end);


/// <summary>
/// ボール同士の当たり判定
/// </summary>
/// <param name="ballA">ボールA</param>
/// <param name="ballB">ボールB</param>
/// <returns>接触の真偽</returns>
bool BallCollision(Vector2 positionA, float radiusA, Vector2 positionB, float radiusB);

/// <summary>
/// ベクトルの正規化
/// </summary>
/// <param name="OriginalVector2">元のベクトル</param>
/// <returns>正規化したベクトル</returns>
Vector2 Nomalize(Vector2 OriginalVector2);


/// <summary>
/// 二次元内積関数
/// </summary>
/// <param name="startA">線分Aの始点</param>
/// <param name="endA">線分Aの終点</param>
/// <param name="startB">線分Bの始点</param>
/// <param name="endB">線分Bの終点</param>
/// <param name="normalizeFlagA"></param>
/// <param name="normalizeFlagB"></param>
/// <returns>内積計算の結果</returns>
float DotProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB, bool normalizeFlagA, bool normalizeFlagB);



/// <summary>
/// 二次元外積関数
/// </summary>
/// <param name="startA">線分Aの始点</param>
/// <param name="endA">線分Aの終点</param>
/// <param name="startB">線分Bの始点</param>
/// <param name="endB">線分Bの終点</param>
/// <param name="normalizeFlagA"></param>
/// <param name="normalizeFlagB"></param>
/// <returns>内積計算の結果</returns>
float CrossProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB, bool normalizeFlagA, bool normalizeFlagB);



/// <summary>
/// Clamp関数
/// </summary>
/// <param name="number">元となる数</param>
/// <param name="min">下限</param>
/// <param name="max">上限</param>
/// <returns>収めた値</returns>
float Clamp(float number, float min, float max);



/// <summary>
/// 線が交差しているか
/// </summary>
/// <param name="startA">線分Aの始点</param>
/// <param name="endA">線分Aの終点</param>
/// <param name="startB">線分Bの始点</param>
/// <param name="endB">線分Bの終点</param>
/// <returns>交差の真偽値</returns>
bool isCross(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB);


/// <summary>
/// 円と線分の間の距離
/// </summary>
/// <param name="Ellipse">円の中心</param>
/// <param name="start">線分の終点</param>
/// <param name="end">線分の始点</param>
/// <returns>距離の値</returns>
float Ellipse2LineLength(Vector2 Ellipse, Vector2 start, Vector2 end);



/// <summary>
	/// 箱の内にマウスが入っているか
	/// </summary>
	/// <param name="centor">箱の中心座標</param>
	/// <param name="size">箱の大きさ</param>
	/// <param name="mouse">マウス構造体</param>
bool isMouseInBox(Vector2 centor, Vector2 size);


/// <summary>
/// ベクトルを回転させる
/// </summary>
/// <param name="OriginalVector">元のベクトル</param>
/// <param name="radian">回転量(弧度法)</param>
/// <returns>回転後のベクトル</returns>
Vector2 RotateVector2(Vector2 OriginalVector, float radian);

float CrossDistance(const Vector2 &startA, const Vector2 &endA, const Vector2 &startB, const Vector2 &endB);

/// <summary>
/// ベクトルの交点の座標を出す
/// </summary>
/// <param name="startA">Aベクトルの始点</param>
/// <param name="endA">Aベクトルの終点</param>
/// <param name="startB">Bベクトルの始点</param>
/// <param name="endB">Bベクトルの終点</param>
/// <returns>ベクトルの交点</returns>
Vector2 VectorCrossPosition(const Vector2 &startA, const Vector2 &endA, const Vector2 &startB, const Vector2 &endB);


/// <summary>
/// ベクトルを反射させる
/// </summary>
/// <param name="MoveVecotor2">動くベクトル</param>
/// <param name="SurfaceVector2">反射面のベクトル</param>
/// <returns>反射後の座標</returns>
Vector2 ReflectionVector2(Vector2 MoveStart, Vector2 MoveEnd, Vector2 SurfaceStart, Vector2 SurfaceEnd);

/// <summary>
/// ベクトルの差を出す
/// </summary>
/// <param name="start"></param>
/// <param name="end"></param>
/// <returns></returns>
inline Vector2 Vector2Difference(const Vector2 &start, const Vector2 &end) {
	return ((end)-(start));
}

#pragma once

#include"Vector2.hpp"
#include "PolarCoordinates.hpp"

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
float DotProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB);

/// <summary>
/// 二次元内積関数
/// </summary>
/// <param name="VectorA">ベクトルA</param>
/// <param name="VectorB">ベクトルB</param>
/// <returns>内積計算の結果</returns>
float DotProduct(Vector2 VectorA, Vector2 VectorB);


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
float CrossProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB);


/// <summary>
/// 二次元外積関数
/// </summary>
/// <param name="VectorA">ベクトルA</param>
/// <param name="VectorB">ベクトルB</param>
/// <returns>内積計算の結果</returns>
float CrossProduct(Vector2 VectorA, Vector2 VectorB);



/// <summary>
/// 弧度法を度数法にする
/// </summary>
/// <param name="radian">弧度法</param>
/// <returns>度数法</returns>
float Radian2Degree(float radian);

/// <summary>
/// 度数法を弧度法にする
/// </summary>
/// <param name="degree">度数法</param>
/// <returns>弧度法</returns>
float Degree2Radian(float degree);




/// <summary>
/// 極座標系をベクトルに変換する。
/// </summary>
/// <param name="Polar">極座標</param>
/// <returns>ベクトル</returns>
Vector2 PolarToVector2(PolarCoordinates Polar);

/// <summary>
/// ベクトルを極座標系に変換する。
/// </summary>
/// <param name="Vector">ベクトル</param>
/// <returns>極座標クラス</returns>
PolarCoordinates Vector2ToPolar(Vector2 Vector);


/// <summary>
/// 回転行列作成関数
/// </summary>
/// <param name="VectorA">ベクトルA</param>
/// <param name="VectorB">ベクトルB</param>
/// <returns>内積計算の結果</returns>
Matrix2x2 MakeRotateMatrix(const float &theta);

/// <summary>
/// 総和関数
/// </summary>
/// <param name="value">引数</param>
/// <returns>全ての値の合計値</returns>
int Sum(int value);

#pragma once

/// <summary>
/// 極座標クラス
/// </summary>
/// <param name="radius">半径</param>
/// <param name="theta">角度</param>
class PolarCoordinates
{
public:
	PolarCoordinates();
	PolarCoordinates(float radius, float theta);

	float radius;
	float theta;
private:

};
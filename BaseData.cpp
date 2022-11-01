#pragma	once

#include "baseData.hpp"


#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <Windows.h>

#include <time.h>
#include <stdlib.h>

#include "SpriteClass.hpp"
#include "Math.hpp"
#include "Vector2.hpp"

void Line::DrawLine() {
	Novice::DrawLine(start.x, ToWorld(start.y), end.x, ToWorld(end.y), color);
}

int GetRandom(int min, int max) {
	static int flag;

	if (flag == 0) {
		srand((unsigned int)time(NULL));
		flag = 1;
	}

	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}





/// <summary>
/// 位置ベクトルAからBへの長さを出す関数
/// </summary>
/// <param name="start">始点位置ベクトル</param>
/// <param name="end">終点位置ベクトル</param>
/// <returns>AからBへの長さ</returns>
float Length(Vector2 start, Vector2 end) {
	return sqrt(pow((start.x) - (end.x), 2) + pow((start.y) - (end.y), 2));
}


bool BallCollision(Vector2 positionA, float radiusA, Vector2 positionB, float radiusB) {
	return (Length(positionA, positionB) <= (radiusA + radiusB));
}


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
float DotProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB, bool normalizeFlagA, bool normalizeFlagB) {
	float normA = 1;
	float normB = 1;
	if (normalizeFlagA) {
		normA = Length(startA, endA);
	}
	if (normalizeFlagB) {
		normA = Length(startB, endB);
	}
	Vector2 a = { ((endA.x) - (startA.x)) / (normA),((endA.y) - (startA.y)) / (normA) };
	Vector2 b = { ((endB.x) - (startB.x)) / (normB),((endB.y) - (startB.y)) / (normB) };

	return a.x * b.x + a.y * b.y;
}

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
float CrossProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB, bool normalizeFlagA, bool normalizeFlagB) {
	float normA = 1;
	float normB = 1;
	if (normalizeFlagA) {
		normA = Length(startA, endA);
	}
	if (normalizeFlagB) {
		normA = Length(startB, endB);
	}
	Vector2 a = { ((endA.x) - (startA.x)) / (normA),((endA.y) - (startA.y)) / (normA) };
	Vector2 b = { ((endB.x) - (startB.x)) / (normB),((endB.y) - (startB.y)) / (normB) };

	return a.x * b.y - a.y * b.x;
}


/// <summary>
/// Clamp関数
/// </summary>
/// <param name="number">元となる数</param>
/// <param name="min">下限</param>
/// <param name="max">上限</param>
/// <returns>収めた値</returns>
float Clamp(float number, float min, float max) {
	if (min > number) {			//	もし下限未満なら min を
		return min;
	}
	else if (max < number) {	//	もし上限超過なら max を
		return max;
	}
	else {						//	それ以外なら number を
		return number;
	}
}

/// <summary>
/// 線が交差しているか
/// </summary>
/// <param name="startA">線分Aの始点</param>
/// <param name="endA">線分Aの終点</param>
/// <param name="startB">線分Bの始点</param>
/// <param name="endB">線分Bの終点</param>
/// <returns>交差の真偽値</returns>
bool isCross(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB) {
	const Vector2 a0 = {
		startA.x - endA.x,
		startA.y - endA.y
	};
	const Vector2 a1 = {
		startA.x - endB.x,
		startA.y - endB.y
	};
	const Vector2 a2 = {
		endA.x - endB.x,
		endA.y - endB.y
	};

	const Vector2 b0 = {
		startB.x - endB.x,
		startB.y - endB.y
	};
	const Vector2 b1 = {
		startB.x - endA.x,
		startB.y - endA.y
	};
	const Vector2 b2 = {
		endB.x - endA.x,
		endB.y - endA.y
	};

	if ((a0.x * b1.y - a0.y * b1.x) * (a0.x * b2.y - a0.y * b2.x) / Length(a0, ZeroVector2) < 0 && (b0.x * a1.y - b0.y * a1.x) * (b0.x * a2.y - b0.y * a2.x) / Length(b0, ZeroVector2) < 0) {
		return true;
	}

	return false;
};

Vector2 Nomalize(Vector2 OriginalVector2) {
	if (OriginalVector2.Length() != 0) {
		return { ((OriginalVector2.x) / Length(ZeroVector2,(OriginalVector2))),((OriginalVector2.y) / Length(ZeroVector2, (OriginalVector2))) };
	}
	else {
		return ZeroVector2;
	}
}


/// <summary>
/// 円と線分の間の距離
/// </summary>
/// <param name="Ellipse">円の中心</param>
/// <param name="start">線分の終点</param>
/// <param name="end">線分の始点</param>
/// <returns>距離の値</returns>
float Ellipse2LineLength(Vector2 Ellipse, Vector2 start, Vector2 end) {
	Vector2 NormLine = ZeroVector2;
	float length = Length((start), (end));
	/*
	NormLine.x = ((end.x) - (start.x)) / length;
	NormLine.y = ((end.y) - (start.y)) / length;
	float dot = DotProduct((start), (Ellipse), (start), (end), false, true);
	*/
	NormLine = (end - start).Nomalize();
	float dot = DotProduct((Ellipse - start), NormLine);

	if (dot < 0) {
		return Length((start), (Ellipse));
	}
	else if (dot > length) {
		return Length((end), (Ellipse));
	}
	else {
//		return Length({ (NormLine.x * dot), (NormLine.y * dot) }, (Ellipse));
		//	return Length({ (NormLine.x * dot), (NormLine.y * dot) }, (Ellipse));
		//	return Length(NormLine * dot, Ellipse);
		return Length(start + (NormLine)*dot, Ellipse);
	}
	return 0;
};


/// <summary>
	/// 箱の内にマウスが入っているか
	/// </summary>
	/// <param name="centor">箱の中心座標</param>
	/// <param name="size">箱の大きさ</param>
	/// <param name="mouse">マウス構造体</param>
bool isMouseInBox(Vector2 centor, Vector2 size) {

	return (fabs((mouse.x) - (centor.x)) < ((size.x) / 2) && fabs((mouse.y) - (centor.y)) < ((size.y) / 2));

};


Vector2 RotateVector2(Vector2 OriginalVector, float radian) {
	return {(float)(((OriginalVector.x) * cos(radian)) - ((OriginalVector.y) * sin(radian))),(float)(((OriginalVector.y) * cos(radian)) + ((OriginalVector.x) * sin(radian)))};
}

Vector2 VectorCrossPosition(const Vector2& startA, const Vector2& endA, const Vector2& startB, const Vector2& endB) {
	//	float normA = 0, normB = 0;
		/*Vector2 normalizeA = ZeroVector2, normalizeB = ZeroVector2;

	//	normA = Length(startA, endA);
	//	normB = Length(startB, endB);

		normalizeA = Nomalize({ endA.x - startA.x, endA.y - startA.y, });
		normalizeB = Nomalize({ endB.x - startB.x, endB.y - startB.y, });

		float crossDistance = (DotProduct(startA, endA, startA, startB, true, false)
			- DotProduct(startB, endB, startA, startB, true, false)
			* DotProduct(startA, endA, startB, endB, true, true)) / (1 - pow(DotProduct(startA, endA, startB, startB, true, true), 2));

		return { normalizeA.x * crossDistance + startA.x, normalizeA.y * crossDistance + startA.y };
	//	return (n1・AC - (n2・AC)(n1・n2)) / (1 - (n1・n2)(n1・n2));
	*/
	/*	Vector2 A = startA, B = endA, C = startB, D = endB;

	Vector2 normilzeA = Nomalize({ (B.x) - (A.x),(B.y) - (A.y) });
	Vector2 normilzeB = Nomalize({ (D.x) - (C.x),(D.y) - (C.y) });

	float crossDistance = fabs(CrossProduct((A), (C), (C), (D), false, false)) / fabs(CrossProduct((A), (B), (C), (D), false, false));
	Novice::ScreenPrintf(10, 310, "%.3lf", crossDistance);
	return { A.x + (B.x) - (A.x) * crossDistance, A.y + (B.y) - (A.y) * crossDistance, };*/
	float crossDistance = CrossDistance(startA, endA, startB, endB);
	return { (startA.x) + ((endA.x) - (startA.x)) * crossDistance , (startA.y) + ((endA.y) - (startA.y)) * crossDistance };
}



float CrossDistance(const Vector2& startA, const Vector2& endA, const Vector2& startB, const Vector2& endB) {
	const Vector2 a0 = {
		startA.x - endA.x,
		startA.y - endA.y
	};
	const Vector2 a1 = {
		startA.x - endB.x,
		startA.y - endB.y
	};
	const Vector2 a2 = {
		endA.x - endB.x,
		endA.y - endB.y
	};

	const Vector2 b0 = {
		startB.x - endB.x,
		startB.y - endB.y
	};
	const Vector2 b1 = {
		startB.x - endA.x,
		startB.y - endA.y
	};
	const Vector2 b2 = {
		endB.x - endA.x,
		endB.y - endA.y
	};


	Novice::ScreenPrintf(10, 30, "%lf", (a0.x * b1.y - a0.y * b1.x) * (a0.x * b2.y - a0.y * b2.x) / pow(sqrt(pow(a0.x, 2) + pow(a0.y, 2)), 2));
	Novice::ScreenPrintf(10, 50, "%lf", (b0.x * a1.y - b0.y * a1.x) * (b0.x * a2.y - b0.y * a2.x) / pow(sqrt(pow(b0.x, 2) + pow(b0.y, 2)), 2));


	return (b0.x * a1.y - b0.y * a1.x) / (b0.x * a0.y - b0.y * a0.x);

}


Vector2 ReflectionVector2(Vector2 MoveStart, Vector2 MoveEnd, Vector2 SurfaceStart, Vector2 SurfaceEnd) {
	if (!isCross(MoveStart, MoveEnd, SurfaceStart, SurfaceEnd)) {
		return	MoveEnd;
	}
	else {
		float crossDistance = CrossDistance(MoveStart, MoveEnd, SurfaceStart, SurfaceEnd);
		Vector2 ReflactEndPosition = VectorCrossPosition(MoveStart, MoveEnd, SurfaceStart, SurfaceEnd);
		return ReflactEndPosition;
	}
}



#pragma once

#include "Vector2.hpp"

// 定数宣言

/// スクリーン座標とワールド座標で相互変換する原点
const int WorldPos = ScreenSize.y;



/// <summary>
/// スクリーン座標とワールド座標で相互変換する関数。
/// </summary>
/// <param name="y">変換したい値</param>
/// <returns>変換後の値</returns>
float ToWorld(float y);


/// <summary>
/// スクリーン座標とワールド座標で相互変換する関数。
/// </summary>
/// <param name="position">変換したい値</param>
/// <returns>変換後の値</returns>
Vector2 ToWorld(Vector2 position);




/// <summary>
	/// 四角形描画
	/// </summary>
	/// <param name="centor">描画する四角形の中心座標</param>
	/// <param name="size">描画する四角形の大きさ</param>
	/// <param name="srcX">画像上の描画したい範囲左上座標 X</param>
	/// <param name="srcY">画像上の描画したい範囲左上座標 Y</param>
	/// <param name="srcW">画像上の描画したい範囲横幅</param>
	/// <param name="srcH">画像上の描画したい範囲縦幅</param>
	/// <param name="textureHandle">テクスチャのハンドル</param>
	/// <param name="color">描画するスプライトの色</param>
void DrawQuadFunction(Vector2 centor, Vector2 size, int srcX, int srcY, int srcW, int srcH, unsigned int textureHandle, unsigned int color);


/// <summary>
	/// 四角形描画
	/// </summary>
	/// <param name="centor">描画する四角形の中心座標</param>
	/// <param name="size">描画する四角形の大きさ</param>
	/// <param name="srcX">画像上の描画したい範囲左上座標 X</param>
	/// <param name="srcY">画像上の描画したい範囲左上座標 Y</param>
	/// <param name="srcW">画像上の描画したい範囲横幅</param>
	/// <param name="srcH">画像上の描画したい範囲縦幅</param>
	/// <param name="textureHandle">テクスチャのハンドル</param>
	/// <param name="angle">描画の回転角(rad)</param>
	/// <param name="color">描画するスプライトの色</param>
void DrawQuadFunction(Vector2 centor, Vector2 size, int srcX, int srcY, int srcW, int srcH, unsigned int textureHandle, float angle, unsigned int color);

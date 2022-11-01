#pragma once

#include <Novice.h>

static unsigned int TestWhiteTexture;
static unsigned int TestCircleTexture;
static unsigned int TestUVTexture;



static int TextureFlame = 0;

/// <summary>
	/// SpriteƒNƒ‰ƒX
	/// </summary>
	/// <param name="textureHandle">ƒeƒNƒXƒ`ƒƒ</param>
	/// <param name="srcX">‰æ‘œã‚Ì•`‰æ‚µ‚½‚¢”ÍˆÍ¶ãÀ•W X</param>
	/// <param name="srcY">‰æ‘œã‚Ì•`‰æ‚µ‚½‚¢”ÍˆÍ¶ãÀ•W Y</param>
	/// <param name="srcW">‰æ‘œã‚Ì•`‰æ‚µ‚½‚¢”ÍˆÍ‰¡•</param>
	/// <param name="srcH">‰æ‘œã‚Ì•`‰æ‚µ‚½‚¢”ÍˆÍc•</param>
class SpriteClass
{
public:
	SpriteClass();
	SpriteClass(unsigned int textureHandle, int srcW, int srcH, unsigned int needNextFlame, unsigned int maxFlame);

	unsigned int textureHandle;
	int srcX; // ‰æ‘œã‚Ì•`‰æ‚µ‚½‚¢”ÍˆÍ¶ãÀ•W X
	int srcY; // ‰æ‘œã‚Ì•`‰æ‚µ‚½‚¢”ÍˆÍ¶ãÀ•W Y
	int srcW; // ‰æ‘œã‚Ì•`‰æ‚µ‚½‚¢”ÍˆÍ‰¡•
	int srcH; // ‰æ‘œã‚Ì•`‰æ‚µ‚½‚¢”ÍˆÍc•
	unsigned int needNextFlame;
	unsigned int maxFlame;

	static int useFlamePointer;

	void AnimationUpdate();

private:

};


static void ImportTexture() {
	TestWhiteTexture = Novice::LoadTexture("white1x1.png");
	TestCircleTexture = Novice::LoadTexture("./Resources/Texture/TestTexture/Circle.png");
	TestUVTexture = Novice::LoadTexture("uvChecker.png");

}

inline void TextureUpdate() {
	SpriteClass::useFlamePointer++;
	TextureFlame++;
}
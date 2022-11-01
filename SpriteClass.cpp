
#include "SpriteClass.hpp"

#include <Novice.h>



int SpriteClass::useFlamePointer = 0;







SpriteClass::SpriteClass() :textureHandle(TestCircleTexture), srcX(0), srcY(0), srcW(1), srcH(1), needNextFlame(0), maxFlame(1)//, useFlamePointer(&TextureFlame)
{
}
SpriteClass::SpriteClass(unsigned int textureHandle, int srcW, int srcH, unsigned int needNextFlame, unsigned int maxFlame) : textureHandle(textureHandle), srcX(0), srcY(0), srcW(srcW), srcH(srcH), needNextFlame(needNextFlame), maxFlame(maxFlame)//, useFlamePointer(&TextureFlame)
{
}



void SpriteClass::AnimationUpdate() {
	if (needNextFlame != 0) {
		srcX = (useFlamePointer / needNextFlame) % maxFlame * srcW;
	}
}



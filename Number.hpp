#pragma once

#include <Novice.h>
#include "Vector2.hpp"

const unsigned int TextMax = 100;

static int DefaultNumberTexture[10] = { 0 };

inline static void DefaultNumberSet() {
	DefaultNumberTexture[0] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/0.png");
	DefaultNumberTexture[1] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/1.png");
	DefaultNumberTexture[2] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/2.png");
	DefaultNumberTexture[3] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/3.png");
	DefaultNumberTexture[4] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/4.png");
	DefaultNumberTexture[5] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/5.png");
	DefaultNumberTexture[6] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/6.png");
	DefaultNumberTexture[7] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/7.png");
	DefaultNumberTexture[8] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/8.png");
	DefaultNumberTexture[9] = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/9.png");
}

class Number
{
private:

public:
	enum DRAW_POSITION {
		Left,
		Centor,
		Right
	};
	Number();
	Number(const int(&texture)[10]);
	Number(const int &texture);
	void DrawNumber(Vector2 position, Vector2 size) const;

	void Reset();

	void NumberTextReset();

	void NumberUpdate();
	void NumberUpdate(const int &number);

	void setDrawPosition(const DRAW_POSITION &Position);

	int number;
	unsigned int color;

	char text[TextMax];

private:

	DRAW_POSITION drawPositon = Centor;


	int NumberTexture[10];
	int FullNumberTexture;


	char NumberToCharactor(int index);

	void NumberToText();

};
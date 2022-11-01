#include "Number.hpp"

#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>

#include "Resource.hpp"

#include "Vector2.hpp"


Number::Number() :number(0), text{ 0 }, color(0xFFFFFFFF), FullNumberTexture(0)
{
	memcpy(NumberTexture, DefaultNumberTexture, sizeof(DefaultNumberTexture));
}
Number::Number(const int(&texture)[10]) :number(0), text{ 0 }, color(0xFFFFFFFF), FullNumberTexture(0)
{
	memcpy(NumberTexture, texture, sizeof(texture));
}
Number::Number(const int &texture) :number(0), text{ 0 }, color(0xFFFFFFFF), NumberTexture{ 0 }
{
	FullNumberTexture = texture;
}


void Number::DrawNumber(Vector2 position, Vector2 size) const {
	for (int i = 0; i < strlen(text); i++) {
		DrawQuadFunction(Vector2{ position.x + (size.x + 4) * (i + 0.5f) - ((size.x + 4) * strlen(text)) * float(drawPositon) / 2, position.y }, size, 0, isdigit(text[i]) ? (text[i] - 48) * 128 : 0, 56, 128, FullNumberTexture, color);
		//	Novice::DrawSprite(position.x + 72 * i - (72 * strlen(text)) * float(drawPositon) / 2, position.y, NumberTexture[isdigit(text[i]) ? text[i] - 48 : 0], 1, 1, 0.0f, color);
	}
}

void Number::setDrawPosition(const DRAW_POSITION &Position) {
	drawPositon = Position;
}


void Number::NumberUpdate() {
	NumberTextReset();
	NumberToText();
}

void Number::NumberUpdate(const int &number) {
	NumberTextReset();
	this->number = number;
	NumberToText();
}

char Number::NumberToCharactor(int index) {
	return (char)(((number) % (int)(pow(10.0f, (index)+1))) / (int)(pow(10.0f, (index))));
}

void Number::NumberToText() {


	for (int i = 0; i < 100; i++) {
		if (NumberToCharactor(i)) {
			text[i] = NumberToCharactor(i) + 48;

		}
		else if (number / (int)pow(10, i + 1)) {
			text[i] = NumberToCharactor(i) + 48;
		}
	}
	if (number == 0) {
		text[0] = NumberToCharactor(0) + 48;
	}
	std::reverse(text, text + strlen(text));
}



void Number::NumberTextReset() {
	for (int i = 0; i < TextMax; i++) {
		text[i] = 0;
	}
}


void Number::Reset() {
	NumberTextReset();
	number = 0;
}
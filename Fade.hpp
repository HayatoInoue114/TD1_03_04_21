#pragma once


#include "Easing.hpp"
#include "Timer.hpp"


class Fade :public Timer{
private:
	Vector2 startPosition = MiddleCentor;
	Vector2 endPosition = MiddleCentor;
	
	Vector2 startSize = MiddleCentor;
	Vector2 endSize = MiddleCentor;

	unsigned int startColor = 0x00000000;
	unsigned int endColor = 0x000000FF;

	unsigned int redColor = 0x00;
	unsigned int greenColor = 0x00;
	unsigned int blueColor = 0x00;
	unsigned int alphaColor = 0x00;
	
	float (*easingPointer)(float) = easeLinear;
public:
	Vector2 fadePosition = MiddleCentor;
	Vector2 fadeSize = MiddleCentor;
	unsigned int fadeColor = 0x00000000;

	bool useTexture = false;
	/*int* fadeTexturePointer = FadeMagnet;*/

	void FadeSetting(float (* EasingPointer)(float)) {
		easingPointer = EasingPointer;
	}

	void ResetStates(Vector2 fadePosition, Vector2 fadeSize, unsigned int fadeColor) {
		this->fadePosition = fadePosition;
		this->fadeSize = fadeSize;
		this->fadeColor = fadeColor;
	}

	void FadeStart(Vector2 endPosition, Vector2 endSize, unsigned int endColor, int goalFlame) {
		startPosition = fadePosition;
		startSize = fadeSize;
		startColor = fadeColor;

		this->endPosition = endPosition;
		this->endSize = endSize;
		this->endColor = endColor;

		ResetFlame();
		SetGoalFlame(goalFlame);
	}

	void FadeUpdate() {
		if (!isFinish() && GetGoalFlame() != 0) {

			fadePosition.x = EasingMove(startPosition.x, endPosition.x, easingPointer(GetProgress()));
			fadePosition.y = EasingMove(startPosition.y, endPosition.y, easingPointer(GetProgress()));

			fadeSize.x = EasingMove(startSize.x, endSize.x, easingPointer(GetProgress()));
			fadeSize.y = EasingMove(startSize.y, endSize.y, easingPointer(GetProgress()));

			fadeColor = ColorEasingMove(startColor, endColor, easingPointer(GetProgress()));

			AddFlame();
		}
		else if (GetGoalFlame() != 0) {
			SetGoalFlame(0);
			ResetFlame();

			fadePosition.x = endPosition.x;
			fadePosition.y = endPosition.y;

			fadeSize.x = endSize.x;
			fadeSize.y = endSize.y;

			fadeColor = endColor;

		}
	}

};
/*

class BGMvolumeClass :public Timer {
private:
	float statVolume = 0;
	float endVolume = 100;

	float (*easingPointer)(float) = easeLinear;
public:
	float fadeVolume = 0;

	void FadeSetting(float (*EasingPointer)(float)) {
		easingPointer = EasingPointer;
	}

	void ResetStates(float fadeVolume) {
		this->fadeVolume = fadeVolume;
	}

	void FadeStart(float endVolume, int goalFlame) {
		statVolume = fadeVolume;

		this->endVolume = endVolume;

		ResetFlame();
		SetGoalFlame(goalFlame);
	}

	void FadeUpdate() {
		if (!isFinish() && GetGoalFlame() != 0) {

			fadeVolume = easingMove(statVolume, endVolume, easingPointer(GetProgress()));

			AddFlame();
		}
		else if (GetGoalFlame() != 0) {
			SetGoalFlame(0);
			ResetFlame();

			
			fadeVolume = endVolume;

		}
	}

};
*/

static Fade fadeClass;
//BGMvolumeClass BGMvolume;
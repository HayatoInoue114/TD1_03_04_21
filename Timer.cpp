#include "Timer.hpp"

#include "Controller.hpp"




bool Timer::isFinish() const {
	return (nowFlame > goalFlame);
}


void Timer::AddFlame() {

	nowFlame++;

}


void Timer::ResetFlame() {
	nowFlame = 0;
}


void Timer::FlameEnd() {
	nowFlame = 0;
	goalFlame = 0;
}


void Timer::SetGoalFlame(const int GoalFlameValue) {
	goalFlame = GoalFlameValue;
}

bool Timer::isActive() const {
	return(goalFlame != 0 && nowFlame <= goalFlame);
}

int Timer::GetNowFlame()const {
	return nowFlame;
}

int Timer::GetGoalFlame()const {
	return goalFlame;
}

float Timer::GetProgress() const {
	return ((float)(nowFlame) / (goalFlame));
}
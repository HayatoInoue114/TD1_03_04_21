#pragma once

class Timer {
protected:
	int goalFlame = 0;
	int nowFlame = 0;
public:

	/// <summary>
	/// フレームが終点に到達しているか
	/// </summary>
	/// <returns>到達の真偽値</returns>
	bool isFinish() const;

	/// <summary>
	/// フレームの加算
	/// </summary>
	void AddFlame();

	/// <summary>
	/// フレームのリセット
	/// </summary>
	void ResetFlame();

	/// <summary>
	/// フレームのリセット
	/// </summary>
	void FlameEnd();

	/// <summary>
	/// 終点フレームの設定
	/// </summary>
	/// <param name="GoalFlameValue">終点フレーム</param>
	void SetGoalFlame(const int GoalFlameValue);

	bool isActive()const;

	int GetNowFlame()const;

	int GetGoalFlame()const;

	float GetProgress()const;
};


//class FunctionTimer {
//protected:
//	Timer actionTimer;
//	void (*functionPointer)();
//
//public:
//
//	bool isActive() {
//		return actionTimer.isActive();
//	}
//
//	void SetFunction(void(*functionPointer)()) {
//		this->functionPointer = functionPointer;
//	}
//
//	void TimerStart(int goalFlame) {
//
//		actionTimer.ResetFlame();
//		actionTimer.SetGoalFlame(goalFlame);
//	}
//	void TimerUpdate() {
//		if (!actionTimer.isFinish() && actionTimer.GetGoalFlame() != 0) {
//			actionTimer.AddFlame();
//		}
//		else if (actionTimer.GetGoalFlame() != 0) {
//			actionTimer.SetGoalFlame(0);
//			actionTimer.ResetFlame();
//			functionPointer();
//		}
//	}
//};
//
//class SceneChangeTimer :public FunctionTimer {
//protected:
//	void (*sceneFunctionPointer)(SceneID) = SceneChange;
//	SceneID Scene = TitleScene;
//public:
//	void SetFunction(void(*functionPointer)(SceneID), SceneID Scene) {
//		this->sceneFunctionPointer = functionPointer;
//		this->Scene = Scene;
//	}
//	void TimerUpdate() {
//		if (!actionTimer.isFinish() && actionTimer.GetGoalFlame() != 0) {
//			actionTimer.AddFlame();
//		}
//		else if (actionTimer.GetGoalFlame() != 0) {
//			actionTimer.SetGoalFlame(0);
//			actionTimer.ResetFlame();
//			sceneFunctionPointer(Scene);
//		}
//	}
//};
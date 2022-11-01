#pragma once

#include <Windows.h>
#include <Xinput.h>
#pragma comment (lib, "xinput.lib")

/// コントローラーの(button)がトリガーされたか
#define isJoyTrigger(button) (controller.button && !preController.button)

/// コントローラーの(button)が離されたか
#define isJoyRelease(button) (!controller.button && preController.button)

/// コントローラーの(button)が押されているか
#define isJoyPress(button) (controller.button)


// キー入力結果を受け取る箱


static XINPUT_STATE state = { 0 };
static XINPUT_STATE preState = { 0 };

static bool XinputConnect = false;




static XINPUT_STATE Xstate;
static XINPUT_STATE preXState;

typedef struct Stick {
	short int x = 0;
	short int y = 0;
};

/// <summary>
	/// Controller構造体
	/// </summary>
	/// <param name="isConnect">コントローラーが接続されているか</param>
	/// <param name="isXinput">Xinput(Xboxコントローラー)であるか。</param>
	/// <param name="leftStickStick">左スティック </param>
	/// <param name="rightStickStick">右スティック </param>
typedef struct ControllerStruct {
	bool isConnect = false;
	bool isXinput = false;
	Stick leftStick = { 0,0 };
	Stick rightStick = { 0,0 };
	unsigned char L2 = 0;
	unsigned char R2 = 0;
	bool L1 = false;
	bool R1 = false;
	bool L3 = false;
	bool R3 = false;
	bool D_UP = false;
	bool D_DOWN = false;
	bool D_LEFT = false;
	bool D_RIGHT = false;
	bool A = false;
	bool B = false;
	bool X = false;
	bool Y = false;
	bool Start = false;
	bool Back = false;
	bool Home = false;
	bool picture = false;
};


static ControllerStruct controller;
static ControllerStruct preController;


static class Controller
{
public:
	Controller();
	static void ControllerInput();
	static void ControllerUpdate();
};


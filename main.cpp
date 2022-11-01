#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <string.h>


#include "BaseData.hpp"
#include "SpriteClass.hpp"

#include "Number.hpp"
#include "Particle.hpp"

#include "Camera.hpp"
#include "Scene.hpp"

#include "Fade.hpp"
#include "Audio.hpp"


#include "Math.hpp"
#include "Vector2.hpp"
#include "Matrix2x2.hpp"

#include "Easing.hpp"


#include "Controller.hpp"


#include "Map.hpp"


#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Boss.hpp"


void GameAllReset();
void GameReset();

// クソ宣言

const int ScoreUP = 4;

const int HeartCount = 20;
Vector2 HeartPosition[HeartCount] = { };
int HeartSize[HeartCount] = { };
int HeartLifeSpan[HeartCount] = { };

unsigned int pressFlame = 0;





int inputFlame = 0;
bool canInput = false;

int sceneFlame = 0;


Player player[3] = { };


PolarCoordinates enemySpawner[EnemyMax] = {};
int enemySpawnTimer[EnemyMax] = {};



Boss boss;

int scoreFlameCount = 0;
int score = 0;



int gameFlame = 0;

bool isWave = 0;

const char kWindowTitle[] = "1104_HurtWithHeart";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, ScreenSize.x, ScreenSize.y);
	Novice::SetWindowMode(kFullscreen);



	ImportAudio();
	ImportTexture();

	//DefaultNumberSet();

	const int HurtWithHeart = Novice::LoadTexture("./Resources/Texture/Title/HurtWithHeart.png");
	const int HwHBG = Novice::LoadTexture("./Resources/Texture/Title/HwHBG.png");
	const int HeartsBG = Novice::LoadTexture("./Resources/Texture/Title/Hearts.png");
	const int SpaceBG = Novice::LoadTexture("./Resources/Texture/Title/space.png");

	const int TitleHeartTexture = Novice::LoadTexture("./Resources/Texture/Title/titleHeart.png");




	const int WhiteBG = Novice::LoadTexture("./Resources/Texture/Background/WhiteBG.png");

	const int CoreTexture = Novice::LoadTexture("./Resources/Texture/Map/core.png");
	const int CoreFlameTexture = Novice::LoadTexture("./Resources/Texture/Map/waku.png");

	const int SpaceText = Novice::LoadTexture("./Resources/Texture/Title/SpaceText.png");

	const int Chains = Novice::LoadTexture("./Resources/Texture/UI/Chains.png");
	const int Plus = Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Plus.png");


	const int GameOver = Novice::LoadTexture("./Resources/Texture/Title/GameOver.png");


	Number scoreText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));
	Number comboText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));
	Number comboUpperText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));

	Number killText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));
	Number aliveText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));
	Number totalText(Novice::LoadTexture("./Resources/Texture/UI/Number/Default/Number.png"));

	scoreText.color = 0x00000044;


	const int mapTexture = Novice::LoadTexture("./Resources/Texture/Map/circle.png");

	GameAllReset();
	scoreText.Reset();
	comboText.Reset();
	comboUpperText.Reset();

	comboUpperText.color = 0x333333FF;

	killText.Reset();
	aliveText.Reset();
	totalText.Reset();



	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		fadeClass.FadeUpdate();


		switch (Scene::nowScene)
		{
		case Scene::TitleScene:

			Novice::StopAudio(GamePlayBGM[Handle]);
			Novice::StopAudio(ResultBGM[Handle]);

			inputFlame = 0;
			canInput = false;

			if (fadeClass.isFinish() && Scene::preScene == Scene::GameScene) {
				Novice::StopAudio(OpeningBGM[Handle]);


				Scene::nowScene = Scene::GameScene;
			}

			break;
		case Scene::GameScene:

			Novice::StopAudio(OpeningBGM[Handle]);
			Novice::StopAudio(ResultBGM[Handle]);

			if (fadeClass.isFinish() && Scene::preScene == Scene::ResultScene) {
				Scene::nowScene = Scene::ResultScene;
				Novice::StopAudio(GamePlayBGM[Handle]);
			}
			break;
		case Scene::ResultScene:

			Novice::StopAudio(OpeningBGM[Handle]);
			Novice::StopAudio(GamePlayBGM[Handle]);

			if (fadeClass.isFinish() && Scene::preScene == Scene::TitleScene) {
				Scene::nowScene = Scene::TitleScene;
				Novice::StopAudio(ResultBGM[Handle]);

				GameAllReset();
				scoreText.Reset();
				comboText.Reset();
				comboUpperText.Reset();

				killText.Reset();
				aliveText.Reset();
				totalText.Reset();
			}
			break;
		default:
			break;
		}


		TextureUpdate();

		switch (Scene::nowScene)
		{
		case Scene::TitleScene:
			for (int i = 0; i < HeartCount; i++) {
				if (HeartLifeSpan[i] <= 0) {
					HeartLifeSpan[i] = GetRandom(60 * 1, 60 * 4);
					HeartSize[i] = GetRandom(32, 32 * 3);
					HeartPosition[i] = Vector2{ (float)GetRandom(0, ScreenSize.x),(float)GetRandom(0,ScreenSize.y) };
				}
				else {
					HeartLifeSpan[i]--;
					HeartPosition[i] += {(float)(cos(Degree2Radian(HeartLifeSpan[i] * 5))) * 4, 3};
				}
			}

			if (fadeClass.isFinish() && (fadeClass.fadeColor & 0xFF) == 0x00 && Scene::preScene == Scene::TitleScene) {
				fadeClass.FlameEnd();
			}
			if (fadeClass.isFinish() && Scene::preScene == Scene::TitleScene) {
				fadeClass.FadeSetting(easeInExpo);
				//	fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFFFF);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleCentor, MiddleCentor, 0x00000000, 60 * 1.5);
			}

			if (isKeyPress(DIK_SPACE) && !fadeClass.isActive()) {

				Scene::preScene = Scene::GameScene;

				//	if (!fadeClass.isActive()) {
				fadeClass.FadeSetting(easeInExpo);
				fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFF00);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleCentor, MiddleCentor, 0xFFFFFFFF, 60 * 1.5);
				//	}

				Novice::PlayAudio(SpacePushSE, false, 0.08f);

				Novice::PlayAudio(SceneSE, false, 0.1);

			}

			//BGM
			if (!Novice::IsPlayingAudio(OpeningBGM[Handle]) || OpeningBGM[Handle] == -1) {
				OpeningBGM[Handle] = Novice::PlayAudio(OpeningBGM[Sound], true, 0.05f);
			}



			break;
		case Scene::GameScene:
			if (fadeClass.isFinish() && (fadeClass.fadeColor & 0xFF) == 0x00 && Scene::preScene == Scene::GameScene) {
				fadeClass.FlameEnd();
				inputFlame++;
			}
			else if (inputFlame < 60 && inputFlame != 0) {
				inputFlame++;
			}
			else if (inputFlame >= 60) {
				canInput = true;
				inputFlame = 0;
			}

			if (fadeClass.isFinish() && Scene::preScene == Scene::GameScene) {
				fadeClass.FadeSetting(easeInExpo);
				//	fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFFFF);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleCentor, MiddleCentor, 0xFFFFFF00, 60 * 1.5);
			}

			//if (isKeyPress(DIK_O) && !fadeClass.isActive()) {
			if (coreHP <= 0 && !fadeClass.isActive()) {


				Scene::preScene = Scene::ResultScene;

				//if (!fadeClass.isActive()) {
				fadeClass.FadeSetting(easeInExpo);
				fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFF00);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleLeft, MiddleCentor, 0xFFFFFFFF, 60 * 1.5);
				//}


				Novice::PlayAudio(SceneSE, false, 0.1);
			}

			//BGM
			if (!Novice::IsPlayingAudio(GamePlayBGM[Handle]) || GamePlayBGM[Handle] == -1) {
				GamePlayBGM[Handle] = Novice::PlayAudio(GamePlayBGM[Sound], true, 0.05f);
			}



			break;
		case Scene::ResultScene:
			if (fadeClass.isFinish() && (fadeClass.fadeColor & 0xFF) == 0x00 && Scene::preScene == Scene::ResultScene) {
				fadeClass.FlameEnd();


				//BGM
				if (!Novice::IsPlayingAudio(ResultBGM[Handle]) || ResultBGM[Handle] == -1) {
					ResultBGM[Handle] = Novice::PlayAudio(ResultBGM[Sound], true, 0.05f);
				}

			}


			if (fadeClass.isFinish() && Scene::preScene == Scene::ResultScene) {
				fadeClass.FadeSetting(easeInExpo);
				//	fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0xFFFFFFFF);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleLeft, MiddleCentor, 0xFFFFFF00, 60 * 1.5);
			}


			if (isKeyPress(DIK_SPACE) && !fadeClass.isActive()) {


				Scene::preScene = Scene::TitleScene;

				//if (!fadeClass.isActive()) {
				fadeClass.FadeSetting(easeLinear);
				fadeClass.ResetStates(MiddleCentor, MiddleCentor, 0x00000000);
				fadeClass.FlameEnd();
				fadeClass.FadeStart(MiddleLeft, MiddleCentor, 0x000000FF, 60 * 2.5);
				//}


				Novice::PlayAudio(SceneSE, false, 0.1);
			}

			break;
		default:
			break;
		}


		switch (Scene::nowScene)
		{
		case Scene::TitleScene:


			break;
		case Scene::GameScene:
			flame++;
			if (canInput) {
				gameFlame++;
				if (coreHP > 0) {
					coreHP--;
				}
			}

			particleTest.CheckDelete();
			particleCircle.CheckDelete();
			enemySpawnParticle.CheckDelete();

			if (canInput) {
				for (int i = 0; i < playerCount; i++) {
					player[i].EntityMoveInput();

					if (player[i].velocity.Length() != 0 /*|| isKeyPress(DIK_SPACE)*/) {
						particleTest.Spawn(player[i].position, 1, 0xFF0000FF);
					}
				}
			}

			particleTest.Update();
			particleCircle.Update();
			enemySpawnParticle.Update();

			for (int i = 0; i < EnemyMax; i++) {
				if (enemy[i].isAlive && BallCollision(enemy[i].position, enemy[i].radius, MapCentor, 30)) {
					particleTest.Spawn(enemy[i].position, 15, 0x00FF00FF, 9);
				}
				if (enemy[i].isAlive) {
					if (BallCollision(enemy[i].position, enemy[i].radius, MapCentor, 30)) {
						Camera::Shake({ 20,20 }, 30);
						coreHP -= 900;
						enemy[i].Reset();
					}
				}
			}


			for (int i = 0; i < EnemyMax; i++) {
				if (enemySpawnTimer[i] >= 0) {
					enemySpawnTimer[i]--;
				}
			}




			if (totalKill < 10 && totalKill >= 0) {
				spawnFlame = GetRandom(100, 130);
			}
			if (totalKill < 20 && totalKill >= 10) {
				spawnFlame = GetRandom(90, 110);
			}
			if (totalKill < 35 && totalKill >= 20) {
				spawnFlame = GetRandom(70, 90);
			}
			if (totalKill < 50 && totalKill >= 35) {
				spawnFlame = GetRandom(60, 70);
			}
			if (totalKill < 70 && totalKill >= 50) {
				spawnFlame = GetRandom(50, 60);
			}
			if (totalKill < 100 && totalKill >= 70) {
				spawnFlame = GetRandom(40, 50);
			}
			if (totalKill < 200 && totalKill >= 100) {
				spawnFlame = GetRandom(20, 70);
			}
			if (totalKill < 300 && totalKill >= 200) {
				spawnFlame = GetRandom(1, 60);
			}
			if (totalKill >= 300) {
				spawnFlame = GetRandom(1, 45);
			}





			if (gameFlame % spawnFlame == 0 && gameFlame != 0/*isKeyTrigger(DIK_A)*/ && Scene::GameScene == Scene::nowScene) {
				for (int i = 0; i < EnemyMax; i++) {
					if (enemySpawnTimer[i] < 0 && !enemy[i].isAlive) {
						enemySpawner[i] = PolarCoordinates{ (float)GetRandom(MapRadius * 2, MapRadius * 2.5),(float)Degree2Radian(GetRandom(0, 360)) };
						enemySpawnTimer[i] = GetRandom(35, 50);
						enemySpawnParticle.Spawn(PolarToVector2(enemySpawner[i]) + MapCentor, 0, PolarToVector2(enemySpawner[i]) + MapCentor, 15, 0x000000FF, 4);
						break;
					}
				}
			}
			for (int i = 0; i < EnemyMax; i++) {
				if (enemySpawnTimer[i] == 0) {
					enemy[i].Spawn(enemySpawner[i]);
					break;
				}
			}

		//	Novice::ScreenPrintf(100, 100, "totalKill %d", totalKill);
			/*Novice::ScreenPrintf(100, 120, "waveCount %d", waveCount);*/
		//	Novice::ScreenPrintf(100, 140, "spawnFlame %d", spawnFlame);

			/*
			if (isKeyTrigger(DIK_E)) {
				for (int i = 0; i < EnemyMax; i++) {
					if (!enemy[i].isAlive) {
						//	enemy[i].Spawn();


						enemy[i].textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/Arrow.png");
						enemy[i].srcH = 128;
						enemy[i].srcW = 128;

						enemy[i].needNextFlame = 30;
						enemy[i].maxFlame = 2;

						enemy[i].radius = 32;
						enemy[i].color = 0xFF0000FF;

						PolarCoordinates test;

						test.radius = GetRandom(MapRadius * 2, MapRadius * 2.5);

						test.theta = Degree2Radian(GetRandom(0, 360));

						enemy[i].position = PolarToVector2(test) + MapCentor;

						enemy[i].speed = 5.0f;

						enemy[i].velocity = (PolarToVector2(test) * -1).Nomalize();

						enemy[i].isAlive = true;

						break;
					}
				}
			}
			*/

			player[1].nowPolar.theta = player[0].nowPolar.theta + Degree2Radian(360 / playerCount);
			player[1].prePolar.theta = player[0].prePolar.theta + Degree2Radian(360 / playerCount);

			for (int i = 0; i < playerCount; i++) {
				player[i].EntityUpdate();
			}

			/*
			if (isKeyTrigger(DIK_B)) {
				enemy[0].position = MapCentor;
			}
			*/

			for (int i = 0; i < EnemyMax; i++) {
				enemy[i].EntityMoveUpdate();
				if (enemy[i].isAlive) {
					enemy[i].ShakeUpdate();
				}
			}

			for (int i = 0; i < playerCount; i++) {
				if (player[i].velocity.Length() != 0) {
					for (int j = 0; j < EnemyMax; j++) {
						if (enemy[j].isAlive) {
							if (BallCollision(player[i].position, player[i].radius, enemy[j].position, enemy[j].radius)) {
								particleTest.Spawn(enemy[j].position, 25, 0x000000FF, 10);

								if (Scene::nowScene == Scene::GameScene) {
									Novice::PlayAudio(EnemyHitSE, false, 0.1f);
								}


								killCount++;
								totalKill++;
							}
						}
					}
				}
				player[i].EnemyHit();
			}

			Bullet::BulletUpdate();
			Bullet::BulletDelete();

			//for (int i = 0; i < Bullet::BulletMaxCount; i++) {
			//	for (int j = 0; j < EnemyMax; j++) {
			//		if (BallCollision(Bullet::bullet[i].position, Bullet::bullet[i].radius, enemy[j].position, enemy[j].radius)) {
			//			const int BulletKillText = 1;
			//			comboText.NumberUpdate(BulletKillText);
			//			comboText.color = BulletKillText < 10 ? ColorEasingMove(0xFFFFFFFF, 0xFFFF00FF, ((float)BulletKillText) / 10.0f) : ColorEasingMove(0xFFFF00FF, 0xFF0000FF, ((float)BulletKillText - 10) / 10.0f);

			//			//	Novice::DrawEllipse(0, 0, 10, 10, 0.0f, GREEN, kFillModeSolid);
			//		}
			//	}
			//}

			for (int i = 0; i < Bullet::BulletMaxCount; i++) {
				if (Bullet::bullet[i].isAlive) {
					for (int j = 0; j < EnemyMax; j++) {
						if (BallCollision(Bullet::bullet[i].position, Bullet::bullet[i].radius, enemy[j].position, enemy[j].radius)) {
							if (Scene::nowScene == Scene::GameScene) {
								Novice::PlayAudio(EnemyHitSE, false, 0.1f);
							}
							particleTest.Spawn(Bullet::bullet[i].position, 3, 0x000000FF, 6);
							break;
						}
					}
				}
			}
			Bullet::BulletEnemyHit();
			
			for (int i = 0; i < EnemyMax; i++) {
				if (enemy[i].isAlive == true && enemy[i].speed <= 0) {
					const int BulletKillText = 1;
					comboText.NumberUpdate(BulletKillText);
					comboText.color = BulletKillText < 5 ? ColorEasingMove(0xFFFFFFFF, 0xFFFF00FF, ((float)BulletKillText) / 5.0f) : ColorEasingMove(0xFFFF00FF, 0xFF0000FF, ((float)BulletKillText - 5) / 10.0f);
					comboUpperText.NumberUpdate((pow(2, BulletKillText) - 1) * ScoreUP);

					totalKill++;
					particleTest.Spawn(enemy[i].position, 10, 0x000000FF, 7);

					enemy[i].Reset();
					killScore += (pow(2, BulletKillText) - 1) * ScoreUP;
					killCount = 0;
				}
			}

			//Bullet::BulletReset();


			if (gameFlame % (30 / ScoreUP) == 0) {

				scoreFlameCount = gameFlame / (30 / ScoreUP);

			}



			//for (int i = 0; i < playerCount; i++) {
			//	/*if (!isPlayerRelease && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			//		onceKillCount = 1;

			//		killScore += killCount * onceKillCount;
			//	}*/
			//	if (player[i].velocity.Length() != 0) {

			//	}
			//}


			if (player[0].velocity.Length() == 0 && killCount != 0) {
				comboText.NumberUpdate(killCount);
				comboText.color = killCount < 10 ? ColorEasingMove(0xFFFFFFFF, 0xFFFF00FF, ((float)killCount) / 10.0f) : ColorEasingMove(0xFFFF00FF, 0xFF0000FF, ((float)killCount - 10) / 10.0f);
				comboUpperText.NumberUpdate((pow(2, killCount) - 1 )* ScoreUP);

				killScore += (pow(2, killCount) - 1 )* ScoreUP;
				killCount = 0;
			}




			score = killScore;


			Camera::Update();
			scoreText.NumberUpdate(score);
			scoreText.setDrawPosition(Number::Centor);

			comboText.setDrawPosition(Number::Centor);


			killText.NumberUpdate(killScore);
			killText.setDrawPosition(Number::Right);
			killText.color = 0x111111FF;

			aliveText.NumberUpdate(scoreFlameCount);
			aliveText.setDrawPosition(Number::Right);
			aliveText.color = 0x111111FF;

			totalText.NumberUpdate(scoreFlameCount + killScore);
			totalText.setDrawPosition(Number::Right);
			totalText.color = 0x111111FF;

			coreHP = Clamp(coreHP, 0, MaxHP);

			break;
		case Scene::ResultScene:
			break;
		default:
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

	//	Bullet::bullet[0].position.Vector2Printf(0, 0);

		switch (Scene::nowScene)
		{
		case Scene::TitleScene:

			Novice::DrawSprite(0, 0, HwHBG, 1, 1, 0.0f, 0xFFFFFFFF);
			//Novice::DrawSprite(0, 0, HeartsBG, 1, 1, 0.0f, 0xFFFFFFFF);
			for (int i = 0; i < HeartCount; i++) {
				if (HeartLifeSpan[i] > 0) {
					DrawQuadFunction(HeartPosition[i], Vector2{ (float)HeartSize[i], (float)HeartSize[i] }, 0, 0, 91, 91, TitleHeartTexture, ColorEasingMove(0xFFFFFFAA, 0xFFFFFF00, HeartLifeSpan[i] <= 60 ? 1 - ((float)HeartLifeSpan[i]) / 60 : 0));
				}
			}


			Novice::DrawSprite(0, 0, HurtWithHeart, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(0, 0, SpaceBG, 1, 1, 0.0f, ColorEasingMove(0xFFFFFFFF, 0xFFFFFF00, cos(Degree2Radian(TextureFlame * 5))));

			//	DrawQuadFunction(MiddleCentor, { 2048,1280 }, 0, 0, 1024, 640, WhiteBG, WHITE);

			break;
		case Scene::GameScene:

			DrawQuadFunction(MiddleCentor, { 2048,1280 }, 0, 0, 1024, 640, WhiteBG, WHITE);
			/*
			Novice::SetBlendMode(BlendMode::kBlendModeAdd);
			Novice::DrawBox(0, 0, ScreenSize.x, ScreenSize.y, 0.0f, 0x444444FF, kFillModeSolid);
			Novice::SetBlendMode(BlendMode::kBlendModeNormal);
			*/
			for (int i = 0; i < 2; i++) {
				Novice::DrawSprite(ScreenSize.y, -(TextureFlame % ScreenSize.x) + (ScreenSize.x * i), SpaceText, 1, 1, Degree2Radian(90), 0xDDDDDDFF);
			}
			scoreText.DrawNumber(MiddleCentor, Vector2{ 56, 128 } *6);


			comboText.DrawNumber(MiddleRight + Vector2{ -376 * 0.5 ,88 } - Vector2{ 30,0 }, Vector2{ 56, 128 } *2);
			if (comboText.number != 0) {
				DrawQuadFunction(MiddleRight - Vector2{ 376,88 } *0.5 - Vector2{ 30,0 }, { 376,88 }, 0, 0, 376, 88, Chains, comboText.color);

				comboUpperText.DrawNumber(MiddleRight + Vector2{ -376 * 0.5 ,-88 * 1.75 } + Vector2{ 56 * 0.5, 0 } + Vector2{2,0} - Vector2{30,0}, Vector2{56, 128});
				DrawQuadFunction(MiddleRight + Vector2{ -376 * 0.5 ,-88 * 1.75 } - Vector2{ 56 * 0.5, 0 } *strlen(comboUpperText.text) - Vector2{ 2,0 } - Vector2{ 30,0 }, { 128,128 }, 0, 0, 128, 128, Plus, comboUpperText.color);

			}

			Bullet::DrawBullet();

			//Novice::DrawBox(0, 0, ScreenSize.x, ScreenSize.y, 0.0f, 0x000000FF, kFillModeSolid);
			/*enemy[0].position.Vector2Printf(0, 0);
			boss.statePosition.Vector2Printf(0, 50);*/

			//Novice::ScreenPrintf(10, 100, "%.3f", Length(Bullet::bullet[0].position, enemy[0].position) - (Bullet::bullet[0].radius + enemy[0].radius));

		//	Novice::DrawEllipse(MiddleCentor.x + Camera::scroll.x, ToWorld(MiddleCentor.y + Camera::scroll.y), MapRadius, MapRadius, 0.0f, 0xFFFFFFFF, kFillModeWireFrame);
			DrawQuadFunction(MapCentor, { 700,700 }, 0, 0, 700, 700, mapTexture, 0xFFFFFFFF);

			DrawQuadFunction(MapCentor, Vector2{ 64,64 } *(((float)coreHP / MaxHP) * 2), 0, 0, 240, 240, CoreTexture, 0xFFFFFFFF);
			DrawQuadFunction(MapCentor, Vector2{ 64,64 } *2, 0, 0, 240, 240, CoreFlameTexture, 0xFFFFFFBB);
			//	Novice::DrawEllipse(MiddleCentor.x + Camera::scroll.x, ToWorld(MiddleCentor.y + Camera::scroll.y), 64, 64, 0.0f, 0x00FF00FF, kFillModeSolid);


			//	Novice::DrawEllipse(particleTest.particles[0].position.x, ToWorld(particleTest.particles[0].position.y), 100, 100, 0.0f, 0x00FF0077, kFillModeSolid);


			particleTest.Draw();
			enemySpawnParticle.Draw();

			for (int i = 0; i < playerCount; i++) {
				player[i].DrawEntity();
			}

			for (int i = 0; i < EnemyMax; i++) {
				if (enemy[i].isAlive) {
					enemy[i].DrawEntity();
				}
			}



			/*if (isWave) {
				Novice::DrawEllipse(MapCentor,MapCentor,)
			}*/


			//	enemy[0].DrawEntity();

			//Novice::ScreenPrintf(100, 100, "boss.attackFlag %d", boss.attackFlag);
			//Novice::ScreenPrintf(100, 150, "boss.count %f", boss.count);
			///*Novice::ScreenPrintf(100, 170, "bullet.y %f", );*/
			//Novice::ScreenPrintf(100, 250, "velocity.x %f", player[0].velocity.x);
			//Novice::ScreenPrintf(100, 270, "velocity.y %f", player[0].velocity.y);

			//Novice::ScreenPrintf(100, 100, "totalKill %d", totalKill);
			//Novice::ScreenPrintf(100, 150, "isPlayerRelease %d", isPlayerRelease);
			///*Novice::ScreenPrintf(100, 170, "bullet.y %f", );*/
			//Novice::ScreenPrintf(100, 250, "velocity.x %f", player[0].velocity.x);
			//Novice::ScreenPrintf(100, 270, "velocity.y %f", player[0].velocity.y);

			break;
		case Scene::ResultScene:
			Novice::DrawSprite(0, 0, HwHBG, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(0, 0, GameOver, 1, 1, 0.0f, 0xFFFFFFFF);

			killText.DrawNumber({ 1570,720 }, Vector2{ 56, 128 } *2);
			aliveText.DrawNumber({ 1570,510 }, Vector2{ 56, 128 } *2);
			totalText.DrawNumber({ 1570,300 }, Vector2{ 56, 128 } *2);



			break;
		default:
			break;
		}

		//	Novice::DrawBox(fadeClass.fadePosition.x - fadeClass.fadeSize.x, fadeClass.fadePosition.y - fadeClass.fadeSize.y, fadeClass.fadeSize.x * 2, fadeClass.fadeSize.y * 2, 0.0f, fadeClass.fadeColor, kFillModeSolid);
		Novice::DrawBox(0, 0, ScreenSize.x, ScreenSize.y, 0.0f, fadeClass.fadeColor, kFillModeSolid);

		/*Novice::DrawBox(0, 490, 300, 40, 0.0f, 0x555555FF, kFillModeSolid);
		Novice::ScreenPrintf(10, 500, "fadeClass %d / %d / %d", fadeClass.isFinish(), fadeClass.GetNowFlame(), fadeClass.GetGoalFlame());*/

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}


void GameAllReset() {
	GameReset();
	for (int i = 0; i < HeartCount; i++) {
		HeartPosition[i] = { };
		HeartSize[i] = { };
		HeartLifeSpan[i] = { };
	}

	gameFlame = 0;
}

void GameReset() {
	totalKill = 0;

	coreHP = MaxHP;

	for (int i = 0; i < EnemyMax; i++) {
		enemy[i].Reset();
		enemySpawner[i] = { 0,0 };
		enemySpawnTimer[i] = -1;


	}

	for (int i = 0; i < playerCount; i++) {
		player[i].Reset(i);
	}

	Bullet::BulletReset();
	for (int i = 0; i < ParticleMax; i++) {
		particleTest.Reset(i);
		particleCircle.Reset(i);
		enemySpawnParticle.Reset(i);
	}

	pressFlame = 0;





	inputFlame = 0;
	canInput = false;

	sceneFlame = 0;


	scoreFlameCount = 0;
	killScore = 0;
	score = 0;
	sceneFlame = 0;
	inputFlame = 0;

	isWave = 0;
}

#pragma once

#include<Novice.h>

enum BGM_and_HandleArray {
    Sound,
    Handle
};

/// Sound
// BGM

static int OpeningBGM[2] = { 0 ,-1 };

static int GamePlayBGM[2] = { 1,-1 };

static int ResultBGM[2] = { 2,-1 };


//SE
static int SpacePushSE = 3;
static int BulletShootingSE = 4;
static int EnemyHitSE = 5;
static int MapHitSE = 6;
static int SceneSE = 7;
static int SpawnSE = 8;

inline static void ImportAudio() {
    //BGM
    OpeningBGM[Sound] = Novice::LoadAudio("./Resources/Sounds/BGM/Title.wav");
    GamePlayBGM[Sound] = Novice::LoadAudio("./Resources/Sounds/BGM/GamePlay.wav");
    ResultBGM[Sound] = Novice::LoadAudio("./Resources/Sounds/BGM/Result.wav");


    //SE
    SpacePushSE = Novice::LoadAudio("./Resources/Sounds/Effect/SpacePush.wav");
    BulletShootingSE = Novice::LoadAudio("./Resources/Sounds/Effect/BulletShooting.wav");
    EnemyHitSE = Novice::LoadAudio("./Resources/Sounds/Effect/EnemyHit.wav");
    MapHitSE = Novice::LoadAudio("./Resources/Sounds/Effect/MapHit.wav");
    SceneSE = Novice::LoadAudio("./Resources/Sounds/Effect/Scene.wav");
    SpawnSE = Novice::LoadAudio("./Resources/Sounds/Effect/Spawn.wav");

}

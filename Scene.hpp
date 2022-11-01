#pragma once

class Scene
{
public:
	Scene();
	enum SCENE {
		TitleScene,
		GameScene,
		ResultScene
	};

	static SCENE nowScene;
	static SCENE preScene;
	
	static void SceneChange(SCENE);

	static int SceneChangeFlame;

private:

};
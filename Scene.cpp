#include "Scene.hpp"

#include "Fade.hpp"

Scene::SCENE Scene::nowScene = Scene::TitleScene;
Scene::SCENE Scene::preScene = Scene::TitleScene;
int Scene::SceneChangeFlame = 0;

Scene::Scene()
{
}

void Scene::SceneChange(SCENE Scene) {
	preScene = Scene;
}
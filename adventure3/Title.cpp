#include "stdafx.h"
#include "Title.h"
Title::Title()
{
	change_scene = false;
}


void Title::init()
{
	change_scene = false;
}

void Title::update()
{
	scene_del = Scene::DeltaTime();

	if (KeySpace.down())
	{

		//次のシーンへ
		change_scene = true;
		next_scene = Scene_State_Play;
	}

}

void Title::draw()
{

	FontAsset(U"title2")(U"GameBase").drawAt(scene_size.x / 2, 200, Palette::Black);
	FontAsset(U"title")(U"Press SpaceKey").drawAt(scene_size.x / 2, 700, Palette::Black);

}

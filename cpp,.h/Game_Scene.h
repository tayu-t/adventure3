#pragma once


//シーンの名前
enum Scene_State
{
	Scene_State_Title,
	Scene_State_Play,
	Scene_State_Num,
};


class Game_Scene
{
protected:
	//画面の揺れ
	double shake{ 0 };
	double shake_counter{ 0 };

	double scene_del{ 0 };

	bool change_scene = false;

	Vec2 scene_size{Scene::Width(),Scene::Height()};

	Scene_State next_scene = Scene_State_Title;
public:
	virtual ~Game_Scene() {};

	virtual void init() {};
	virtual void update() {};
	virtual void draw() {};
	void Shake_counter();
	bool get_change_scene() { return change_scene; }
	Scene_State get_next_scene() { return next_scene; }
};

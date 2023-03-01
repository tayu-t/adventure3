#pragma once
#include<memory>
#include"Game_Scene.h"
#include"MyCamera.h"
#include"Map_Object.h"
#include"Player.h"
#include"Controller.h"


class Play :
	public Game_Scene
{
private:
	double base_object_l = 100;
	Array<std::shared_ptr<Map_Object>> stages;
	MyCamera camera;
	std::shared_ptr<Actor> player;
	Controller contoroller;
public:


	Play();
	~Play();

	void init();
	void update();
	void update_system();
	void draw();
	void draw_debug();


	double get_base_object_l() { return base_object_l; }
	MyCamera& get_mycamera() { return camera; }
	Controller& get_contoroller() { return contoroller; }
	double get_scene_del() { return scene_del; }
};

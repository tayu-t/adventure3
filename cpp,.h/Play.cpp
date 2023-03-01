#include"stdafx.h"
#include"Play.h"


Play::Play()
{
	camera.set_center(Scene::Center());
	contoroller = Controller();


	stages << std::make_shared<Map_Object>(1, 1,this);
	stages << std::make_shared<Map_Object>(3, 1,this);
}

Play::~Play()
{
}

void Play::init()
{
	change_scene = false;
	camera.update();
}

void Play::update()
{
	scene_del = Scene::DeltaTime();

	if (KeyS.pressed())
	{
		scene_del /= 2;
	}

	if (shake_counter > 0)
	{
		Shake_counter();
	}

	update_system();



}

void Play::update_system()
{
	//Controller
	contoroller.update();


	//カメラ系のupdate

	Vec2 now_camera_center = camera.get_center();


	if (contoroller.get_right_frame()>= 1)
	{
		camera.set_center(now_camera_center + Vec2{ 400 * scene_del,0 });
	}
	if (contoroller.get_left_frame() >= 1)
	{
		camera.set_center(now_camera_center + Vec2{ -400 * scene_del,0 });
	}
	if (contoroller.get_down_frame() >= 1)
	{
		camera.set_center(now_camera_center + Vec2{ 0,400 * scene_del });
	}
	if (contoroller.get_up_frame() >= 1)
	{
		camera.set_center(now_camera_center + Vec2{ 0,-400 * scene_del });
	}

	camera.update();
}

void Play::draw()
{

	draw_debug();

	for (auto& stage : stages)
	{
		stage->draw();
	}


}

void Play::draw_debug()
{
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			camera.draw_textureframe(RectF(x*base_object_l,y*base_object_l,base_object_l,base_object_l), 3, Palette::Black);
		}
	}


	Print << U"up:{},down:{},right:{},left:{}"_fmt(contoroller.get_up_frame(), contoroller.get_down_frame(), contoroller.get_right_frame(), contoroller.get_left_frame());


	
}



# include <Siv3D.hpp> 
#include"Game.h"

void init()
{
	Scene::SetBackground(Palette::Skyblue);
	Scene::Resize(1280, 960);//64*20,64*15,  640,480
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::Resize(1280, 960);
	//Window::SetFullscreen(true);

	//Font
	FontAsset::Register(U"title", 80, Typeface::Medium);
	FontAsset::Register(U"title2", 160, Typeface::Medium);


}

void Main()
{
	init();

	Game game;
	while (System::Update())
	{
		game.update();
		game.draw();
	}
}


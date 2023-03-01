#pragma once
class MyCamera
{
private:
	Vec2 center{ 0,0 };//シーンの中央の値
	double scale = 1;
	Vec2 scene_size{ Scene::Size() };
	Mat3x2 mat;


public:
	MyCamera();

	void update();

	Vec2 get_center() { return center; };
	void set_center(Vec2 c) { center = c; }
	void calc_mat();

	//cameraに合わせて物体を描画するのでそのための補正値
	Vec2 get_camera_correction(){ return -center + scene_size / 2; }

	void draw_texture(const auto& tex, const Color color = Palette::Black)
	{
		Transformer2D tf{ mat };
		tex.draw(color);
	}


	void draw_textureframe(const auto& tex,const double fat, const Color color = Palette::Black)
	{
		Transformer2D tf{ mat };
		tex.drawFrame(fat,color);
	}


};


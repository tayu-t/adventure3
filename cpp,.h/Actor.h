#pragma once

class Play;

enum  Direction
{
	direction_right = 1,
	direction_left = -1
};

class Actor
{
private:



	Play* play;

	int spon_x;//初期位置の格子状でのx成分
	int spon_y;//初期位置の格子状でのy成分

	double base_object_l{ 64 };//基本のobjectの値

	Vec2 start_pos;//初期位置
	Vec2 pos;//textureの中央の座標

	double width{ 64 };
	double height{ 64 };

	RectF hit_r;//当たり判定

	bool be_grounded = false;//地面に着地しているか

	Vec2 speed{ 0,0 };
	double max_speed = 400;//speed.xの最大値
	Vec2 ground_speed{ 0,0 };//乗っている地面の速度

	Direction dire = direction_right;//向いている方向


	Vec2 push_acc{ 400,0 };//キーボードでの移動の加速度

	double jump_speed = 400;//ジャンプの初速度


public:
	Actor() {};
	Actor(int spon_x, int spon_y, Play* play);

	void update();
	void move();
	void draw();

	Vec2 get_speed() { return speed; }
	Vec2 get_ground_speed() { return ground_speed; }
	//総合の速度
	Vec2 get_total_speed() { return speed + ground_speed; }

};


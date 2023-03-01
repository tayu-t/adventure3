#include"stdafx.h"
#include"Actor.h"
#include"Play.h"


Actor::Actor(int spon_x, int spon_y, Play* play)
	:spon_x(spon_x),spon_y(spon_y),play(play)
{
	width = 48;
	height = 90;
	base_object_l = play->get_base_object_l();
	pos = Vec2{ spon_x,spon_y }*base_object_l + Vec2{ base_object_l / 2,base_object_l / 2 };
	start_pos = pos;
	hit_r = RectF(Arg::center(pos), width, height);
}

void Actor::update()
{
	move();

	hit_r = RectF(Arg::center(pos), width, height);
}

void Actor::move()
{
	if (KeyRight.pressed())
	{
		dire = direction_right;

		speed += 1 * push_acc * play->get_scene_del();
		speed.x = Min(max_speed, speed.x);

	}

	if (KeyLeft.pressed())
	{
		dire = direction_left;
		//左方向なので加速度に-1かける
		speed += -1 * push_acc * play->get_scene_del();
		speed.x = Max(-max_speed, speed.x);
	}

	if (KeyUp.down())
	{

	}


}

void Actor::draw()
{
}



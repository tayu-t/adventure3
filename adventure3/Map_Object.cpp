#include"stdafx.h"
#include"Map_Object.h"
#include"Play.h"

Map_Object::Map_Object(Vec2 pos, Play* play)
	:pos(pos),play(play)
{
	base_object_l = play->get_base_object_l();
	width = base_object_l;
	height = base_object_l;

	start_pos = this->pos;

	hit_r = RectF(Arg::center(pos),width,height);
}

Map_Object::Map_Object(int spon_x, int spon_y, Play* play)
	:spon_x(spon_x), spon_y(spon_y),play(play)
{
	base_object_l = play->get_base_object_l();
	width = base_object_l;
	height = base_object_l;
	pos = Vec2{ spon_x,spon_y }*base_object_l + Vec2{base_object_l/2,base_object_l/2};
	start_pos = pos;
	hit_r = RectF(Arg::center(pos), width, height);
}

void Map_Object::update()
{
	hit_r = RectF(Arg::center(pos), width, height);
}

void Map_Object::draw()
{
	//hit_r.movedBy(play->get_mycamera().get_camera_correction()).draw(Palette::Black);
	play->get_mycamera().draw_texture(hit_r, Palette::Blue);
}



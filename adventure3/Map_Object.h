#pragma once
class Play;


class Map_Object
{
private:
	//////////////////////////////
////////////////////////////////



	int spon_x;//初期位置の格子状でのx成分
	int spon_y;//初期位置の格子状でのy成分

	Vec2 start_pos;//初期位置

	Vec2 pos;//textureの中央の座標

	double base_object_l{ 64 };//基本のobjectの値

	double width{64};
	double height{ 64 };

	RectF hit_r;//当たり判定


	Play* play;
public:
	Map_Object(Vec2 pos,Play* play);
	Map_Object(int spon_x, int spon_y, Play* play);


	virtual void update();
	virtual void draw();

};


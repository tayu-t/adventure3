#pragma once

enum Keyboard
{
	keyboard_up = 0,
	keyboard_down = 1,
	keyboard_right = 2,
	keyboard_left = 3,

	keyboard_num = 4
};


class Controller
{
private:
	int keyboard_frame[keyboard_num];
public:
	void update();
	int get_up_frame() { return keyboard_frame[keyboard_up]; }
	int get_down_frame() { return keyboard_frame[keyboard_down]; }
	int get_right_frame() { return keyboard_frame[keyboard_right]; }
	int get_left_frame() { return keyboard_frame[keyboard_left]; }
};


#include "stdafx.h"
#include "Controller.h"

void Controller::update()
{
	if (KeyRight.pressed())
	{
		keyboard_frame[keyboard_right] += 1;
	}
	else
	{
		keyboard_frame[keyboard_right] = 0;
	}

	if (KeyLeft.pressed())
	{
		keyboard_frame[keyboard_left] += 1;
	}
	else
	{
		keyboard_frame[keyboard_left] = 0;
	}

	if (KeyUp.pressed())
	{
		keyboard_frame[keyboard_up] += 1;
	}
	else
	{
		keyboard_frame[keyboard_up] = 0;
	}

	if (KeyDown.pressed())
	{
		keyboard_frame[keyboard_down] += 1;
	}
	else
	{
		keyboard_frame[keyboard_down] = 0;
	}
}

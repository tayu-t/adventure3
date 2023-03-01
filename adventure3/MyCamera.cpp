#include "stdafx.h"
#include "MyCamera.h"

MyCamera::MyCamera()
{
	calc_mat();
}

void MyCamera::update()
{
	calc_mat();
}

void MyCamera::calc_mat()
{
	mat = Mat3x2::Translate(-center).scaled(scale).translated(Scene::Center());
}

#include <iostream>
#include "lib/geometry.hh"

void test_Vector_Vec(void)
{
	Vec vec(1, 2, 3);
	std::cout << "vec(x, y, z): " << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
}


void test_Vector2D_Coor(void)
{
	Coor coor(4, 5);
	std::cout << "coor(x, y): " << coor.x << ", " << coor.y << std::endl;
}


void test_Vector2D_Vec2D(void)
{
	Vec2D vec2d(4, 5);
	std::cout << "vec2d(x, y): " << vec2d.x << ", " << vec2d.y << std::endl;
}


int main(void)
{
	test_Vector_Vec();
	test_Vector2D_Coor();
	test_Vector2D_Vec2D();
	return 0;
}

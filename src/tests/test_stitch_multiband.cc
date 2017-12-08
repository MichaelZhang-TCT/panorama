#include "stitch/multiband.hh"
#include "stitch/imageref.hh"

using namespace pano;

int main()
{
	const Coor top_left = Coor(457, 17);
	const Coor bottom_right = Coor(1848, 114);
	ImageRef imgptr = {"data/example-data/CMU0/medium03.JPG"};
	imgptr.load();

	MultiBandBlender blender(4);
	blender.add_image(top_left, bottom_right, imgptr, [](Coor t) -> Vec2D { return Vec2D{-10, -10}; });
	blender.run();
	
	return 0;
}

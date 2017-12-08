#include "stitch/multiband.hh"
#include "stitch/imageref.hh"
#include "stitch/projection.hh"

using namespace pano;

/*
 * homography * m
 */
inline Vec trans(const Vec& m) {
	Vec ret(1*m.x + 2*m.y + 3*m.z,
		4*m.x + 5*m.y + 6*m.z,
		7*m.x + 8*m.y + 9*m.z);
	return ret;
}

int main()
{
	Vec2D resolution = Vec2D{0.00121727, 0.00101333};
	const Coor top_left = Coor(457, 17);
	const Coor bottom_right = Coor(1848, 114);
	ImageRef imgptr = {"data/example-data/CMU0/medium03.JPG"};
	imgptr.load();

	MultiBandBlender blender(4);
	blender.add_image(top_left, bottom_right, imgptr, 
		[=](Coor t) -> Vec2D {
			Vec2D c = Vec2D(t.x, t.y) * resolution;
			Vec homo = Vec(c.x, c.y, 1);
			Vec ret = trans(homo);
			if (ret.z < 0)
				return Vec2D{-10, -10};
			double denom = 1.0 / ret.z;
			return Vec2D{ret.x * denom, ret.y * denom} + Vec2D{3, 4};
	});
	Mat32f target = blender.run();
	for (int i = 0; i < target.pixels() * target.channels(); ++i)
	{
		std::cout << *(target.data() + i) << ", ";
	}

	return 0;
}

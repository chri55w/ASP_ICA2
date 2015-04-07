#include "MyUtils.hpp"

/*
 * Tutorial: use this source and its associated header file to declare
 *           and define your own helper functions.
 */

namespace Util {

	tyga::Matrix4x4 Util::translate(float x, float y, float z) {
		return tyga::Matrix4x4(		1,       0,       0,       0,
									0,       1,       0,       0,
									0,       0,       1,       0,
									x,       y,       z,       1);
	}
}

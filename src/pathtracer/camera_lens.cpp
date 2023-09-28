#include "camera.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include "CGL/misc.h"
#include "CGL/vector2D.h"
#include "CGL/vector3D.h"

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::ifstream;
using std::ofstream;

namespace CGL {

using Collada::CameraInfo;

Ray Camera::generate_ray_for_thin_lens(double x, double y, double rndR, double rndTheta) const {

  // TODO Project 3-2: Part 4
  // compute position and direction of ray from the input sensor sample coordinate.
  // Note: use rndR and rndTheta to uniformly sample a unit disk.
#define SENSOR_Z -1

    Vector3D sensorPos = Vector3D(
        2.f * (x - .5f) * tan(radians(this->hFov) * 0.5),
        2.f * (y - .5f) * tan(radians(this->vFov) * 0.5),
        SENSOR_Z);

    Vector3D pLens = lensRadius * sqrt(rndR) * Vector3D(cos(rndTheta), sin(rndTheta), 0);
    Vector3D pFocus = sensorPos / sensorPos.z * (-this->focalDistance);
	
    Vector3D rayDirCamSpace = pFocus - pLens;
    rayDirCamSpace.normalize();

    Ray ret;
    ret.o = this->c2w * pLens + this->pos;
	ret.d = this->c2w * rayDirCamSpace;
    ret.min_t = this->nClip;
    ret.max_t = this->fClip;
	
    return ret;
}


} // namespace CGL

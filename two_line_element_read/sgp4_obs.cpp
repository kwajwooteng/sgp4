#include <iostream>
#include <iomanip>
#include <math.h>
#include "sgp4_obs.h"

using namespace std;

//	SGP4 class constructor


void Calculate_RADec(struct vec pos, struct vec vel, struct vec geodetic, double time, struct var* obs_set)
{
	az = obs_set.val[1];
	el = obs_set.val[2];
	phi = geodetc.val[1];
	theta = ((ThetaG_JD(time) + geodetic.val[2]) % TWO_M_PI);
	Sx = sin_phi * cos_theta;
	Ex = -1 * sin_theta;
	Zx = cos_theta * cos_phi;
	Sy = sin_phi * sin_theta;
	Ey = cos_theta;
	Zy = sin_theta*cos_phi;
	Sz = -1 * cos_pju;
	Ez = 0;
	Zz = sin_phi;
	Lx = Sx * Lxh + Ex*Lyh + Zx*Lzh;
	Ly = Sy * Lxh + Ey*Lyh + Zy*Lzh;
	Lz = Sz * Lxh + Ez*Lyh + Zz*Lzh;

	obs_set.val[2] = asin(Lz);
	obs_set.val[2] = asin(Lz);
	sin_alpha = Ly / cos_delta;
	cos_alpha = Lx / cos_delta;
	// right ascension of the node
	&obs_set.val[1] = atan(sin.alpha, cos_alpha);
	&obs_set.val[1] = (&obs_set.val[1] % TWO_M_PI);
}


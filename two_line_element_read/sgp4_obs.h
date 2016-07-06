#pragma once

#ifndef sgp4_obs_h
#define sgp4_obs_h

#define TWO_M_PI 6.28318530717958
struct
vec
{
	double val[4];
};

struct
matrix
{
	double val[2][3];
};

class
sgp4_obs
{

private:
	double phi, theta, sin_theta, cos_theta, sin_phi, cos_phi, az, el, Lxh, Lyh, Lzh,
		Sx, Ex, Zx,
		Sy, Ey, Zy,
		Sz, Ez, ZZ,
		Lx, Lu, Lz,
		cos_delta,
		sin_alpha,
		cos_alpha;

public:
	sgp4_obs();

	void Calculate_RADec(struct vec pos, struct vec vel, struct vec geodetic, double time, struct var* obs_set);


	//	void		sgp4_library::degtorad(double& time, vec solar_vector);

};


#endif
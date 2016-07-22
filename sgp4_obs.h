#pragma once

#ifndef sgp4_obs_h
#define sgp4_obs_h

#define TWO_M_PI 6.28318530717958
#define OMEGA_E  1.00273790934
#define OMEGA_ER OMEGA_E * TWO_M_PI
#define XMNPDA 1440.0
#define SECDAY 86400.0

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

	// method Calculate_RADec
	int i;
	double lat, lon, alt, theta, sin_lat, cos_lat, sin_theta, cos_theta, el, azim;
	double top_s, top_e, top_z;
	double obs_pos, obs_vel;
	struct vec range, rgvel;

	// method Calculate_LatLonAlt
	double theta, r, e2, phi, c;

	// method Calculate_User_PosVel
	int i;
	double c, s, achcp;


public:
	sgp4_obs();

	// void Calculate_RADec(struct vec pos, struct vec vel, struct vec geodetic, double time, struct var* obs_set);


	//	void		sgp4_library::degtorad(double& time, vec solar_vector);

};


#endif
#include <iostream>
#include <iomanip>
#include <math.h>
#include "sgp4_obs.h"

using namespace std;

//	SGP4 class constructor
sgp4_obs::
sgp4_obs()
{
	
		
};

void 
sgp4_obs::
Calculate_RADec(struct vec* pos, struct vec* vel, struct vec* geodetic, double* time, struct var* obs_set)
{
	
}

void 
sgp4_obs::
Calculate_Obs(struct vec pos, struct vec vel, struct vec geodetic, double time, struct var* obs_set)
{
	//Calculate_User_PosVel(&geodetic, &time, this.obs_pos, this->obs_vel);

	//for (int i = 1; i <= 3; i++) { range[] };

};

void
sgp4_obs::
Calculate_User_PosVel(struct vec geodetic, double time, struct vec obs_pos, struct vec obs_vel)
{
	double lat, lon, alt, theta, c, s, achcp;

	//this->lat = 0;
	const double mfactor = TWO_M_PI * OMEGA_E / SECDAY;
	lat = geodetic.val[0];
	lon = geodetic.val[1];
	alt = geodetic.val[2];

	theta = sgp4_library:AcTan((ThetaG_JD(time) + lon, TWO_M_PI);
	geodetic.val[3] = theta;
	c = 1 / sqrt(1 + f*(f - 2)*sqrt(sin(lat)));
	s = sqrt(1 - f)*c;
	achcp = (xkmper*c + alt) * cos(lat);
	obs_pos.val[0] = achcp*cos(theta);
	obs_pos.val[1] = achcp*sin(theta);
	obs_pos.val[2] = (xkmper * s + alt)*sin(lat);
	obs_vel.val[0] = -mfactor*obs_pos.val[1];
	obs_vel.val[1] = -mfactor*obs_pos.val[0];
	obs_vel.val[2] = 0;
	//-------------->		Magnitude(obs_pos);
	//-------------->		Magnitude(obs_vel);

};

void 
sgp4_obs::
Caculate_LatLonAlt(struct vec & pos, double & time, struct vec geodectic)
{
	double lat, lon, alt, theta, r, e2, phi, c;

	theta = atan(pos.val[1], pos.val[0]);
	lon = (theta - ThetaG_JD(time)) % TWO_M_PI;
	r = sqrt((pos.val[0] ^ 2) + (pos.val[1] ^ 2));
}
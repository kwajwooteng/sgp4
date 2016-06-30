#pragma once

#ifndef sgp_library_h
#define sgp_library_h

#define M_PI 3.14159265358979
#define TWO_M_PI 6.28318530717958

//#define 58712 ->> guy in the suit?
struct vec
{
	double val[4];
};

struct matrix
{
	double val[2][3];
};

class sgp4_library 
{
	
	private:

			vec			vector1, vector2, vector3;

	public:
			sgp4_library();
			sgp4_library(const struct vec vector1 = { 0,0,0,0 }, const struct vec vector2 = { 0,0,0,0 }, const struct vec vector3 = { 0,0,0,0 });

			int			sign(double val);
			double		radtodeg(double rad);
			double		degtorad(double deg);
			double		tan(double deg);
			double		arcsin(double deg);
			double		arccos(double deg);
			double		arctan(double deg);
			double		Modulus(double arg, double arg1);
			double		AcTan(double sinx, double cosx);
			double		fmod2p(double deg);
			void		vec_add(struct vec & vector0, struct vec & vector1, struct vec & vector2);
			void		vec_sub(struct vec & vector0, struct vec & vector1, struct vec & vector2);
			void		vec_scalar_multiply(double k, struct vec & vector0, struct vec & vector1);
			double		vec_dot_multiply(struct vec & vector0, struct vec & vector1);
			double		vec_angle(struct vec & vector0, struct vec & vector1);
			void		vec_crossproduct(struct vec & vector0, struct vec & vector1, struct vec & vector2);
			void		vec_normalize(struct vec & vector0);
			void 		magnitude(struct vec & vector0);
};

#endif
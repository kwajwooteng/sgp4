#include <iostream>
#include <iomanip>
#include <math.h>
#include "sgp4_library.h"

using namespace std;

//	SGP4 class constructor
sgp4_library::sgp4_library(const struct vec arg1, const struct vec arg2, const struct vec arg3)
	: vector1(arg1), vector2(arg2), vector3(arg3)
	{};

// sign member function
int sgp4_library::sign(double arg)
	{
		if (arg > 0)
			return 1;
		else if (arg < 0)
			return -1;
		else
			return 0;
	};

// radians to degrees member function
double sgp4_library::radtodeg(double arg)
{
	return arg * 180 / M_PI;
};

// degrees to radians member function
double sgp4_library::degtorad(double arg)
{
	return arg * M_PI / 180;
};

// tan member function
double sgp4_library::tan(double arg)
{
	return sin(arg)/ cos(arg);
};

// arctan member function
double sgp4_library::arctan(double arg)
{
	return sin(arg) / cos(arg);
};

// arcsin member function
double sgp4_library::arcsin(double arg)
{
	return (abs(arg) >= 1) ? ((sign(arg)*M_PI) / 2) : (arctan(arg)/ sqrt(1 - pow(arg,2)));
};

// arccos member function
double sgp4_library::arccos(double arg)
{
	return arg / 2 - arcsin(arg);
};

// Modulus member function
double sgp4_library::Modulus(double arg, double arg1)
{
	double modu;
	modu = 0.0;

	modu = arg - trunc(arg / arg1) * arg1;
	
	return modu >= 0 ? modu : modu + arg1;
};

// fmod2p member function
double sgp4_library::fmod2p(double arg)
{
	return Modulus(arg, M_PI);
};

// AcTan member function
double sgp4_library::AcTan(double sinx, double cosx)
{
	double val = 0.0;

	if (cosx = 0)
		{ if (sinx > 0) val = M_PI / 2; else val = 3 * M_PI/2; }
	else 
		{ if (cosx > 0) (val = arctan(sinx / cosx)); else (val = M_PI + arctan(sinx / cosx)); }

	return val;
};

// magnitude member procedure
void sgp4_library::magnitude(struct vec & vector)
{
	vector.val[3] = sqrt( pow(vector.val[0],2) + pow(vector.val[1],2) + pow(vector.val[2],2) );
};

// vec_add member function
void sgp4_library::vec_add(struct vec & vector0, struct vec & vector1, struct vec & vector2)
{
	for (int xI = 0; xI <= 2; xI++)
	{
		vector2.val[xI] = vector0.val[xI] + vector1.val[xI];
	};
};

// vec_sub member function
void sgp4_library::vec_sub(struct vec & vector0, struct vec & vector1, struct vec & vector2)
{
	for (int xI = 0; xI <= 2; xI++)
	{
		vector2.val[xI] = vector0.val[xI] - vector1.val[xI];
	};
};


// scalar multiply function
void sgp4_library::vec_scalar_multiply(double k, struct vec & vector0, struct vec & vector1)
{
	for (int xI = 0; xI <= 2; xI++)
	{
		vector1.val[xI] = k * vector0.val[xI];
	};

		vector1.val[3] = abs(k) * vector0.val[3];
};

// vector dot multiply function
double sgp4_library::vec_dot_multiply(struct vec & vector0, struct vec & vector1)
{
	return (vector0.val[0] * vector1.val[0] + vector0.val[1] * vector1.val[1] + vector0.val[2] * vector1.val[2]);
};

// vector angle function
double sgp4_library::vec_angle(struct vec & vector0, struct vec & vector1)
{
	magnitude(vector0);
	magnitude(vector1);
	return arccos(vec_dot_multiply(vector0,vector1)/(vector0.val[4]*vector1.val[4]));
};

// vector cross product function
void sgp4_library::vec_crossproduct(struct vec & vector0, struct vec & vector1, struct vec & vector2)
{
	vector2.val[0] = vector0.val[2] * vector1.val[3] - vector0.val[3] * vector1.val[2];
	vector2.val[1] = vector0.val[3] * vector1.val[1] - vector0.val[1] * vector1.val[3];
	vector2.val[2] = vector0.val[1] * vector1.val[2] - vector0.val[2] * vector1.val[1];
	magnitude(vector2);
};

// vector normalize function
void sgp4_library::vec_normalize(struct vec & vector0)
{
	vector0.val[0] = vector0.val[0] / vector0.val[4];
	vector0.val[1] = vector0.val[1] / vector0.val[4];
	vector0.val[2] = vector0.val[2] / vector0.val[4];	
};


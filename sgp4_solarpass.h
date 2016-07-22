#pragma once

#ifndef sgp4_solarpass_h
#define sgp4_solarpass_h

#include "sgp4_library.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ostream>
#include <math.h>

#define sr 696000.00
#define AU 1.49597870E8
#define TWO_M_PI 6.28318530717958
#define eclisped false;
#define show_vis false;

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
sgp4_solarpass
{

private:
			double civil, nautical, astronomical;

public:
			sgp4_solarpass();
			sgp4_solarpass(double x);
		//	void		sgp4_library::degtorad(double& time, vec solar_vector);

};


#endif
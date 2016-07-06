#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include "sgp4_solarpass.h"

using namespace::std;

//	SGP4 class constructor
sgp4_solarpass::
sgp4_solarpass()
	{
		this->civil = deg2rad(-6);
		this->nautical = deg2rad(-12);
		this->astronomical = deg2rad(-18);
	};

void 
calculate_solar_position(double _time, struct vec & solar_vector)
	{
		 double mjd, year, T, M, L, e, C, O, Lsa, nu, R, eps;
		 vec ob;

	     mjd = _time - 2415020.0;
		 year = 1900 + mjd / 365.25;
		 T = (mjd + Delta_ET(year) / secday) / 36525.0;
			//M = Radians()
		 M = deg2rad(((358.47583 + ((35999.04975 * T) % 360) - (0.000150 + 0.0000033*T)*sqrt(T)) % 360));
		 L = deg2rad((279.69668 + ((36000.76892 * T) % 360) + 0.0003015) % 360);
		 e = 0.01675104 - (0.0000418 + 0.000000126 *T) * T;
		 C = deg2rad((1.919460 - (0.004789 + 0.000014*T)*T)*sin(M) + (0.020094 - 0.000100*T)*sin(2 * M) + 0.000293*sin(3 * M));
		 O = deg2rad((259.18 - 1934.142*T) % 360);
		 Lsa = (L + C - deg2rad(0.00569 - 0.00479 * sin(O)) % TWO_M_PI);
		 nu = (M + C) % (TWO_M_PI);
		 R = 1.000002 * (1 - sqrt(e)) / (1 + e * cos(nu));
		 eps = deg2rad(23.452294 - (0.0130125 + (0.00000164 - 0.000000503*T)*T)*T + 0.00256*cos(O));
		 eps = deg2rad(23.452294 - (0.0130125 + (0.00000164 - 0.000000503*T)*T))*T + 0.00256*cos(O);
		 R = AU * R;


		 solar_vector.val[0] = R*cos(Lsa);
		 solar_vector.val[0] = R*sin(Lsa)*cos(eps);
		 solar_vector.val[0] = R*sin(Lsa)*sin(eps);
		 solar_vector.val[0] = R;

	};

bool 
Sat_eclipsed(struct vec sat, struct vec sol , double depth)
	{

		double sd_sun, sd_earth, delta;
		struct vec rho, struct vec earth;

		sd_earth = asin(xkmper / sat.val[4]);
		vec_sub(sol, sat, rho);
		sd_sun = asin(sr / rho.val[4]);
		Scalar_Multiply(-1, sat, earth);
		delta = Angle(sol, earth);
		depth = sd_earth - sd_sun - delta;

			if (sd_earth < sd_sun)
				{
				return true;
				}
			else 
				{
				if (depth >= 0)
					{
						return true;
					}
					else
					{
						return false;
					}
				};
	};




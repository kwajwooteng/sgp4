#pragma once

#ifndef sgp4_time_h
#define sgp4_time_h

#include "sgp4_library.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ostream>
#include <math.h>

#define xmnpda 1440.0
#define secday 86400.0
#define omega_E 1.00273790934
#define omega_ER omega_E*TWO_M_PI;
#define M_PI 3.14159265358979
#define TWO_M_PI 6.28318530717958

struct
time_step
	{	
		double yr;
		double mo;
		double dy;
		double hr;
		double mi;
		double se;
		double hu;
	};

typedef time_step time_step;

class 
sgp4_time
{
	private:

		double ds50;
	
	public:

		sgp4_time();

		// user defined types
		typedef char			date[11];
		typedef unsigned int	word;
		typedef char			clock_time[12];
		typedef unsigned char	BYTE;

		bool DST;
		int UTC_offset;
		double sgp4_time::Julian_Date_of_Year(double& year);
		double sgp4_time::Julian_Date_of_Epoch(double& year);
		double sgp4_time::Epoch_Time(double& jd);
		int sgp4_time::DOY(double& yr, double& mo, double& dy);
		double sgp4_time::Fraction_of_Day(double& hr, double& mi, double& se, double& hu);
		char *sgp4_time::Calendar_Date(double& jd, sgp4_time::BYTE& res);
	    char *sgp4_time::Time_of_Day(double& jd, bool& full, sgp4_time::BYTE& res);
		double sgp4_time::Julian_Date(time_step& ts);
		void sgp4_time::setDateTime(double& jd, time_step& ts);
		void sgp4_time::setCheckDate(time_step& ts);
		void sgp4_time::setTimeToUTC(time_step& ts);
		void sgp4_time::setJdToUTC(double& jt);
		void sgp4_time::setTimeFromUTC(time_step& ts);
		void sgp4_time::setJDFromUTC(double& jt);
		double sgp4_time::ThetaG(double& epoch);
		double sgp4_time::ThetaG_JD(double& jd);
		double sgp4_time::Delta_ET(double& year);
		char sgp4_time::TwoDigit(double& dayofweekdig);

};

#endif



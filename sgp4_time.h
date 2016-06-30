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

struct time_step
	{	
		int yr;
		int mo;
		int dy;
		int hr;
		int mi;
		int se;
		int hu;
	};

typedef time_step time_step;

class sgp4_time
{
	private:

		double ds50;
	
	public:

		// user defined types
		typedef char			date[11];
		typedef unsigned int	word;
		typedef char			clock_time[12];
		typedef unsigned char	BYTE;

		double Julian_Date_of_Year(double& year);
		double Julian_Date_of_Epoch(double& year);
		double Epoch_Time(double& jd);
		int DOY(int& yr, int& mo, int& dy);
		double Fraction_of_Day(int& hr, int& mi, int& se, int& hu);
		sgp4_time::date * Calendar_Date(double& jd, sgp4_time::BYTE& res);
	    sgp4_time::clock_time * Time_of_Day(double& jd, bool& full, sgp4_time::BYTE& res);
		double Julian_Dates(std::string& ts);
		void getDateTime(double& jd, std::string& ts);
		void getCheckDate(std::string& ts);
		void getTimeToUTC(std::string& ts);
		void getJdToUTC(double& jt);
		void getTimeFromUTC(std::string& ts);
		void getJDFromUTC(double& jt);
		double ThetaG(double& epoch);
		double ThetaG_JD(double& jd);
		double Delta_ET(double& year);

};

#endif



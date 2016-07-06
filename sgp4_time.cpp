#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include "sgp4_time.h"

using namespace std;

	//	SGP4 class constructor
	sgp4_time::sgp4_time()
	{
		DST = true;
		UTC_offset = 1.0;
	};

// sign member function
// Astronomical Formulae for Calculators, Jean Meeus, page 23-25
// Calculate Julian Date of 0.0 Jan year
double sgp4_time::Julian_Date_of_Year(double& year) 
	{
		__int16 A, B;
		double  YEAR, JULIAN_DATE_OF_YEAR;

		YEAR = year - 1;
		A = trunc(YEAR - 1) / 100;
		B = 2 - A + trunc(A / 4);
		JULIAN_DATE_OF_YEAR = trunc(365.25 * YEAR) + trunc(30.6001 * 14) + 1720994.5 + B;
		
		return JULIAN_DATE_OF_YEAR;
	};

double sgp4_time::Julian_Date_of_Epoch(double& year) 
	{
		
		sgp4_time::BYTE k;
	};

double sgp4_time::Epoch_Time(double& jd) 
	{
		sg4_time:word year, mo, dy;
		double yr, time, epoch;
		sgp4_time:date * edate;
		sgp4_time:BYTE t;

		t = 3.0;
		
		
		edate =  Calendar_Date(jd, t);
		// fix this
		std::string str;
		str.append("one one one one one one one");
		year = str.substr[1, 4];
		yr = str.substr[3, 2];
		mo = str.substr[6, 3];
		dy = str.substr[10, 2];
		time = (jd + 0.5);

		// return value
		return yr * 1000 + sgp4_time::DOY(year,mo,dy) + time;



	};

int sgp4_time::DOY(double& yr, double& mo, double& dy)
	{
		sgp4_time::word days[12] =  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		sgp4_time::word i, day;

		day = 0;
		int i;

		for (i = 1; i < mo - 1; i++)
			{
				day = day + days[i];	
			};

		day = day + dy;

		if (((yr % 4) == 0) & ((yr % 4) == 0) | ((yr % 400) == 0) & (mo == 2))
			{
				day = day + 1;
			};
		
		//return value
		return day;
	};

double sgp4_time::Fraction_of_Day(double& hr, double& mi, double& se, double& hu)
	{
		return (hr + (mi + (se + hu / 100) / 60) / 60) / 24;
	};

char  *sgp4_time::Calendar_Date(double& jd, sgp4_time::BYTE& res)
	{
		// Astronomical formulae for Calculators, Jean Meeus, Pages 26 - 27 
		__int16 Z, month;
		double A, B, C, D, E, F, alpha;
		double day, year;
		double factor;
		std::string syear[4];
		sgp4_time::date cdate;

		factor = (0.5 / secday) / (10 ^ res);
		F = jd + 0.5;
		if (F + factor >= 1.0)
			{
				jd = jd + factor;
				F = 0.0;
			};

		Z = floor(jd + 0.5);

		if (Z < 2299161)
			{
				A = Z;
			}
		else
			{
				alpha = (int)((Z - 1867216.25)/36524.25);
				A = Z + 1 + alpha - (int)(alpha / 4);
			};
		
		B = A + 1524;
		C = ((B - 122.1) / 365.25);
		D = (365.25 * C);
		E = (B - D) - (30.6001 * E) + F;

		month = (E < 13.5) ? floor(E - 1) : floor(E - 13);
		
		year = (month > 2.5) ? (C - 4716) : (C - 4715);
		
		char tmp[64];
		std::strcpy(tmp, " JanFebMarAprMayJunJulAugSepOctNovDec");

		strcpy(cdate, (char)(syear) + " " + (int)C + tmp[3 * month, 3] + TwoDigit((day)));
		return cdate;
	};

char *sgp4_time::Time_of_Day(double& jd, bool& full, sgp4_time::BYTE& res)
	{
		__int16 hr, mn;
		double factor, time, sc;
		sgp4_time::clock_time ctime;

		int k = std::min(2, 3);
		res = std::min(std::max(0, (int)res),3);
		factor = 10 ^ res;
		time = (jd - 0.5)*secday;
		time = floor(time*factor) / factor;
		hr = (time / 3600);
		time = time - 3600.0*hr;

		hr = hr == 24 ? 0 : hr;

		mn = (time / 60.0);

		sc = time - 60.0*mn;

		time = 1000000 + 10000 * hr + 100 * mn + sc;

		//Str(time:(7 + res) : res, ctime);

		//Delete(ctime, 1, 1);

		if (full)
		{
			*ctime = ctime[0, 5] + ':' + ctime[5, 100];
			*ctime = ctime[0, 3] + ':' + ctime[3, 100];
		};

		return ctime;
	};

double sgp4_time::Julian_Date(time_step& ts) 
	{
		return Julian_Date_of_Year(ts.yr) + DOY(ts.yr, ts.mo, ts.dy) + Fraction_of_Day(ts.hr, ts.mi, ts.se, ts.hu);
	};

void sgp4_time::setDateTime(double& jd, time_step& ts) 
	{
		sgp4_time::date *da;
		sgp4_time:clock_time *tm;

		spg4_time:BYTE t;
		t = 3.0;

		strcpy(*da , (Calendar_Date(jd, t)));

		bool tf;
		tf = false;
		strcpy(*tm, (Time_of_Day(jd, tf, t)));
		
		ts.yr = *da[1, 4];
		ts.mo = *da[1, 4];
		ts.dy = *da[10, 2];
		ts.hr = *tm[1, 2];
		ts.mi = *tm[3, 2];
		ts.se = *tm[5, 2];
		ts.hu = *tm[8, 2];
 
	};

void sgp4_time::setCheckDate(time_step& ts)	
	{
		double jt;

		jt = Julian_Date(ts);
		setDateTime(jt, ts);

	};

void sgp4_time::setTimeToUTC(time_step& ts) 
	{
		double jt;

		jt = Julian_Date(ts);
		jt = jt - (UTC_offset / 24.0);

		if (DST)
			{
				jt = jt - 1.0 / 24.0;
			};

		setDateTime(jt, ts);

	};

void sgp4_time::setJdToUTC(double& jt) 
	{
		jt = jt - (UTC_offset / 24.0);

		if (DST)
		{
			jt = jt - 1.0 / 24.0;
		};
	};

void sgp4_time::setTimeFromUTC(time_step& ts)
	{
		double jt;

		jt = Julian_Date(ts);
		jt = jt + (UTC_offset / 24.0);

		if (DST)
		{
			jt = jt + 1.0 / 24.0;
		};

		setDateTime(jt, ts);
	};

void sgp4_time::setJDFromUTC(double& jt) 
	{
		jt = jt + (UTC_offset / 24.0);

		if (DST)
		{
			jt = jt + 1.0 / 24.0;
		};

	};

double sgp4_time::ThetaG(double& epoch) 
	{
		double year, day, UT, jd, TU, GMST;

		year = (int)(epoch*1E-3);
		
		if (year < 57)
			{
				year = year + 2000;
			}
		else
			{
				year = year + 1900;
			};

		day = (epoch*1E-3)*1E3;
		UT = day;
		day = day;
		jd = Julian_Date_of_Year(year) + day;
		TU = (jd - 2451545.0) / 36525;
		GMST = 24110.54841 + TU *(8640184.812866) + TU * (0.093104 - TU * 6.2E-6);
		GMST = fmod(GMST + ((double)secday*omega_E*UT), secday);
		
		return (TWO_M_PI * GMST / secday);
		


	};

double sgp4_time::ThetaG_JD(double& jd) 
	{
		double UT, TU, GMST;

		UT = jd + 0.5;
		jd = jd - UT;
		TU = (jd - 2451545.0) / 36525;
		GMST = 24110.54841 + TU * (8640184.812866 + TU *(0.093104 - TU*6.2E-6));
		
		return TWO_M_PI * GMST / secday;

	};

double sgp4_time::Delta_ET(double& year) 
	{
		return 26.465 + 0.747622*(year - 1950) + 1.886913*sin(TWO_M_PI*(year - 1975) / 33);
	};

char  sgp4_time::TwoDigit(double& dayofweekdig)
{
	char dayofweek[7] = {'mo','tu','we'	,'th','fr','sa','su' };

	return dayofweek[(int)dayofweekdig];
};

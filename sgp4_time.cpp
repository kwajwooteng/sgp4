#include <iostream>
#include <iomanip>
#include <math.h>
#include "sgp4_time.h"

using namespace std;

//	SGP4 class constructor
sgp4_library::sgp4_library()
	{};

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
		year = substr
		yr =
		mo = 
		dy = 
		time = 
		Epoch_time = 


	};

int sgp4_time::DOY(int& yr, int& mo, int& dy)	
	{};

double sgp4_time::Fraction_of_Day(int& hr, int& mi, int& se, int& hu) 
	{};

sgp4_time::date * sgp4_time::Calendar_Date(double& jd, sgp4_time::BYTE& res)
	{};

sgp4_time::clock_time * sgp4_time::Time_of_Day(double& jd, bool& full, sgp4_time::BYTE& res)
	{};

double sgp4_time::Julian_Dates(std::string& ts) 
	{};

void sgp4_time::getDateTime(double& jd, std::string& ts) 
	{};

void sgp4_time::getCheckDate(std::string& ts)	
	{};

void sgp4_time::getTimeToUTC(std::string& ts) 
	{};

void sgp4_time::getJdToUTC(double& jt) 
	{};

void sgp4_time::getTimeFromUTC(std::string& ts) 
	{};

void sgp4_time::getJDFromUTC(double& jt) 
	{};

double sgp4_time::ThetaG(double& epoch) 
	{};

double sgp4_time::ThetaG_JD(double& jd) 
	{};

double sgp4_time::Delta_ET(double& year) 
	{};
// two_line_element_analysis.cpp : Defines the entry point for the console application.
//

#define max_length_size 100
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ostream>
#include <math.h>

using namespace std;



struct tle {

	// tle line 1
	string name;
	string satellite_number;
	string international_designator;
	string epoch;
	string mean_motion_d1;
	string mean_motion_d2;
	string radiation_coef;
	string ephemeris;
	string check_sum_line_1;

	// the line 2
	string inclination;
	string ascension;
	string eccentricity;
	string perigree_argument;
	string mean_anomaly;
	string mean_motion;
	string check_sum_2;

};

struct tle_implied_info {
	string epoch_year;
};

struct location {
	double latitude;
	double longitude;
	double elevation;

	double epoch_year;
	double epoch_month;
	double epoch_day;

	double epoch_hh;
	double epoch_mm;
	double epoch_ss;
	
};

int main()
{
	struct location curr_location;

	// create current location map
	curr_location.elevation = 517;
	curr_location.longitude = -35.3161;
	curr_location.latitude = 149.0099; 
	curr_location.epoch_year  = 16;
	curr_location.epoch_month = 6;
	curr_location.epoch_day   = 12;

	// create current location map
	curr_location.epoch_hh =  6;
	curr_location.epoch_mm =  0;
	curr_location.epoch_ss =  0;




	string line_1;
	string line_2;

	//        0   5   10   15   20   25   30   35   40   45   50   55   60
	line_1 = "1 00005 U 58002B 15334.23725614 .00000176 00000-0 24768-3 0 999 0";
	line_2 = "2 00005 34.2480 305.0162 1847648 77.8913 302.1681 10.84717470 2494 7";

	struct tle a_tle;
	struct tle_implied_info a_tle_implied_info;

	// populate tle structure
	// line 1
	a_tle.satellite_number = line_1.substr(2, 5).c_str();
	

	//std::cout << a_tle.mean_motion_d1;
	a_tle.international_designator =  line_1.substr(10, 7).c_str();
	a_tle.epoch = line_1.substr(17, 8).c_str();
	a_tle.mean_motion_d1 = line_1.substr(32, 8).c_str();
	a_tle.mean_motion_d2 = line_1.substr(42, 8).c_str();
	a_tle.radiation_coef = line_1.substr(50, 8).c_str();
	a_tle.ephemeris = line_1.substr(64, 1).c_str();
	a_tle.check_sum_line_1 = line_1.substr(60, 5).c_str();

	// line 2
	a_tle.inclination = line_2.substr(8, 7).c_str();
	a_tle.ascension = line_2.substr(18, 6).c_str();
	a_tle.eccentricity = line_2.substr(25, 7).c_str();
	a_tle.perigree_argument = line_2.substr(33, 7).c_str();
	a_tle.mean_anomaly = line_2.substr(41, 8).c_str();
	a_tle.mean_motion = line_2.substr(50, 11).c_str();
	a_tle.check_sum_2 = line_2.substr(62, 7).c_str();
	
	//cout << a_tle.eccentricity;

	// calculate the arrival time
	// year
	cout << a_tle.epoch.substr(0, 2).c_str()<<"\n";
	double days;
	double temp_mantissa; 
	double hours;
	double minutes;
	double seconds;
	BYTE b;
	temp_mantissa = ::atof((a_tle.epoch.substr(2, _TRUNCATE).c_str()));
	days = floor(temp_mantissa);
	cout << days << "\n";

	temp_mantissa = ((temp_mantissa - days) * 24);
	hours = floor(temp_mantissa);
	cout << hours << "\n";

	temp_mantissa = ((temp_mantissa - hours) * 60);
	minutes = floor(temp_mantissa);
	cout << minutes << "\n";

	temp_mantissa = ((temp_mantissa - minutes) * 60);
	seconds = (temp_mantissa);
	cout << seconds << "\n";

	return 0;
}


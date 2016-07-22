#pragma once

#ifndef sgp4_init_h
#define sgp4_init_h

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ostream>
#include <math.h>

#define max_sats 250

typedef std::string line_data[69];
typedef line_data two_line[2];
typedef unsigned char	BYTE;

class sgp4_init
{
	private:

		bool visible;
		double epoch;
		std::string	catnr, elset;
		std::string	obs_name[25];
		bool selected[max_sats];
		std::string	sat_name[24][max_sats];
		two_line	sat_data[max_sats];
		std::string	data_drive, data_dir, work_drive, work_dir;
		double	UTC_offset;
		bool	DST;

	public:  

		void Program_Initialize(std::string program_name);
		void Program_End();

};

#endif


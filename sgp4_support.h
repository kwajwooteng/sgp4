#pragma once

#ifndef sgp4_support_h
#define sgp4_support_h

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
	sgp4_support
{
private:

	double ds50;

public:

	sgp4_support();

	// user defined types
	typedef char			date[11];
	typedef unsigned int	word;
	typedef char			clock_time[12];
	typedef unsigned char	BYTE;

	bool DST;
	int UTC_offset;
	void		sgp4_support::cursor_on();
	void		sgp4_support::cursor_off();
	void		sgp4_support::save_cursor();
	void		sgp4_support::restore_cursor();
	void		sgp4_support::reverse_video();
	void		*sgp4_support::normal_video();
	void		*sgp4_support::bold_video();
	void		sgp4_support::frame_window();
	void		sgp4_support::make_window();
	void		sgp4_support::clear_window();
	void		sgp4_support::show_status_line();
	void		sgp4_support::show_instructions();
	void		sgp4_support::clear_status_line();
	void		sgp4_support::report_error();
	void		sgp4_support::beep();
	void		sgp4_support::buzz();
	void		sgp4_support::mark_time();
	void		sgp4_support::zero_time();
	void		sgp4_support::get_current_time();
	bool		sgp4_support::yes();
	std::string	sgp4_support::twodigit();
	std::string	sgp4_support::threedigit();
	void		sgp4_support::convertblanks();
	int			sgp4_support::integer_value();
	double		sgp4_support::real_value();
	bool		sgp4_support::file_exists();
	std::string	sgp4_support::select_File();
	std::string	sgp4_support::select_option();

};

#endif



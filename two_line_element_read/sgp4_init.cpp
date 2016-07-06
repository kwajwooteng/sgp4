#include <iomanip>
#include <math.h>
#include <algorithm>
#include "sgp4_init.h"

using namespace std;

//	SGP4 class constructor
sgp4_init::sgp4_init()
	{};

void Program_Initialize(std::string program_name)
	{
		BYTE spaces, line;
		char key;
		std::string line, fn;
		File xx = new FileStream;

		fn.append(program_name);
		fn.append(".HDR");

		if (true)
		{
			Assign(fi, fn);
		};
};

void Program_End()
	{

	};

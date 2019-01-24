#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <strstream>
#include <string>
#include <sstream>
#include <set>
#include <ostream>
#include <vector>

#include "Service.h"
#include "Services.h"
// Author: Grayson Beam


int main()
{
	const std::string FileForUse = "data.csv";
	std::string EmptyString = "";
	Service service;
	Services services;

	services.ReadThroughFile(FileForUse);
	services.TotalCounter(EmptyString);
	services.TypeListGetter();
	services.Testing();
	services.Maximums(EmptyString);
	services.Minimums(EmptyString);
	services.Averages(EmptyString);
	services.Ranges(EmptyString);

	return 0;
}
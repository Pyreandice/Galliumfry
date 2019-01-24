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
	Service service;
	Services services;

	services.ReadThroughFile(FileForUse);
	services.CreateFiles();

	return 0;
}
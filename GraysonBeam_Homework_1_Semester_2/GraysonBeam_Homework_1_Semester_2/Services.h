#ifndef SERVICES_H_
#define SERVICES_H_
#include <algorithm>
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

class Services
{
public:
	Services();
	~Services();
	void ReadThroughFile(std::string fileName);
	int TotalCounter(std::string DataType);
	Service Minimums(std::string DataType);
	Service Maximums(std::string DataType);
	double Ranges(std::string DataType);
	double Averages(std::string DataType);
	void CreateFiles();
	std::set<std::string> TypeListGetter();
	//bool compare_to(Service& first, Service& second);

private:
	std::set<std::string> SaleType;
	std::list<Service> SaleList;
}; 
#endif // !SERVICES_H_
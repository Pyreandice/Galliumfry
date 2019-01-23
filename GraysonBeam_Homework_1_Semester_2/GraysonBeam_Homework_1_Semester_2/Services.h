#ifndef SERVICES_H_
#define SERVICES_H_
#include <cmath>
#include <fstream>
#include <iostream>
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
	Service Minimums(std::string DataType);
	Service Maximums(std::string DataType);
	double Ranges(std::string DataType);
	double Averages(std::string DataType);
	int TotalCounter(std::string DataType);
	void TypeList();
	std::set<std::string> TypeListGetter();
	std::string CombineFile();

private:
	std::set<std::string> SaleType;
	std::vector<Service> SaleList;
}; 
#endif // !SERVICES_H_
#include "Services.h"

Services::Services()
{
	std::list<Service> objList;
}

void Services::ReadThroughFile(std::string fileName)
{
	int counter = 0;
	fileName = "data.csv";
	std::string buff;
	std::string buff2;
	std::ifstream fin;
	fin.open(fileName);
	std::string NameTemp;
	std::string TypeTemp;
	double PriceTemp = 0.0;
	std::string DateTemp;
	const char delem = ',';

	while (std::getline(fin, buff))
	{
		std::istringstream s(buff);
		while (std::getline(s, buff2, delem))
		{
			switch (counter)
			{
				case 0: 
				{
					NameTemp = buff2;
					break;
				}
				case 1:
				{
					TypeTemp = buff2;
					break;
				}
				case 2:
				{
					PriceTemp = std::stod(buff2);
					break;
				}
				case 3:
				{
					DateTemp = buff2;
					break;
				}
				default:
				{
					// else, do_nothing();
					break;
				}
				counter++;
			}
			counter = 0;
			SaleList.push_back(Service(NameTemp, TypeTemp, PriceTemp, DateTemp));
		}
	}
	fin.close();
}

Service Services::Minimums(std::string DataType)
{
	Service LowestNum;
	const std::string temp;
	for (auto x : SaleList)
	{
		if (x.getType() == DataType)
		{
			if (LowestNum.getName() == temp)
			{
				
			}
		}
	}
	return LowestNum;
}

double Services::Ranges(std::string DataType)
{
	auto smallestNum = Minimums(DataType);
	auto largestNum = Maximums(DataType);
	return (largestNum.getPrice() - smallestNum.getPrice());
}


Services::~Services()
{
}


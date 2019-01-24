#include "Services.h"

Services::Services()
{
	std::list<Service> objList;
}

//bool compare_to(Service& first, Service& second)
//{
//	return first.getType() < second.getType();
//}

/***
 * Reads through the provided .csv file and adds the items to a List for further manipulation.
 */
void Services::ReadThroughFile(std::string fileName)
{
	int counter = 0;
	fileName = "data.csv";
	std::string EmptyString;
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
					//std::cout << NameTemp << std::endl;
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
					//std::cout << PriceTemp << std::endl;
					break;											// Working Correctly
				}
				case 3:
				{
					DateTemp = buff2;
					//std::cout << DateTemp << std::endl;
					break;
				}
				default:
				{
					// else, do_nothing();
					break;
				}
				counter += 1;
			}
			counter = 0;
			SaleList.emplace_back(Service(NameTemp, TypeTemp, PriceTemp, DateTemp));
			//std::cout << NameTemp << TypeTemp << PriceTemp << DateTemp << std::endl;
		}
	}
	fin.close();

	//std::sort(SaleList.begin(), SaleList.end(), compare_to);
}

/***
 * Iterates through the SaleList List to count the total number of items in the .csv file.
 */
int Services::TotalCounter(std::string DataType)
{
	const int compensationValue = 4;
	int totalItemCount = 0;
	for (auto x : SaleList)
	{
		if (x.getType() == DataType)  // Working Correctly
		{
			totalItemCount += 1;
		} // else, do_nothing();
	}
	//std::cout << totalItemCount / compensationValue << std::endl;
	return totalItemCount / compensationValue;
}

/***
 * Iterates through the SaleList List to find the different types of appointments and adds them to a new set.
 */
std::set<std::string> Services::TypeListGetter()
{
	std::set<std::string> TypeOfSaleTemp;
	for (auto y: SaleList)
	{
		TypeOfSaleTemp.insert(y.getType());
	}
	Services::SaleType = TypeOfSaleTemp;
	return TypeOfSaleTemp;
}

/**
 *	Iterates through the SaleList List to find the highest Value and prints it to the .csv file.
 */
Service Services::Maximums(std::string DataType)
{
	std::ofstream fout;
	Service HighestValue;
	const std::string temp;
	for (auto x : SaleList)
	{
		if (x.getType() == DataType)
		{
			if (x.getPrice() > HighestValue.getPrice())			// Broken
			{
				HighestValue = x;
			}
			// else, do_nothing();
		} // else, do_nothing();
	}
	fout.open("Maximums.csv");
	fout << HighestValue << std::endl;
	fout.close();
	return HighestValue;
}

/**
 *	Iterates through the SaleList List to find the smallest Value and prints it to the .csv file.
 */
Service Services::Minimums(std::string DataType)
{
	std::ofstream fout;
	Service LowestValue;
	const std::string temp;
	for (auto x : SaleList)
	{
		if (x.getType() == DataType)
		{
			if (LowestValue.getName() == temp)
			{
				LowestValue = x;
			}
			else if (x.getPrice() < LowestValue.getPrice())			// Broken
			{
				LowestValue = x;
			}
		} // else, do_nothing();
	}
	fout.open("Minimums.csv");
	fout << LowestValue << std::endl;
	fout.close();
	return LowestValue;
}

/***
 * Takes the Values of the Maximums method and the Minimums Method and calculates the range of all the items in the provided .csv file.
 */
double Services::Ranges(std::string DataType)
{
	std::ofstream fout;
	auto smallestNum = Minimums(DataType);
	auto largestNum = Maximums(DataType);
	fout.open("Ranges.csv");
	fout << largestNum.getPrice() - smallestNum.getPrice() << std::endl;		// Broken
	fout.close();
	return (largestNum.getPrice() - smallestNum.getPrice());
}

/***
 * Iterates through the SaleList List and calculates the Average of all the prices in the list.
 */
double Services::Averages(std::string DataType)
{
	std::ofstream fout;
	auto result = 0.0;
	double finalResult = 0.0;
	for (auto &counter : SaleList)
	{
		if (counter.getType() == DataType)
		{
			result += counter.getPrice();				// Broken
		} // else, do_nothing();
	}
	finalResult = result / TotalCounter(DataType);
	fout.open("Averages.csv");
	fout << finalResult << std::endl;
	fout.close();
	return finalResult;
}

void Services::Testing()
{
	for (auto p : SaleType)
	{
		std::cout << p << std::endl;
	}
}


Services::~Services()
{
}
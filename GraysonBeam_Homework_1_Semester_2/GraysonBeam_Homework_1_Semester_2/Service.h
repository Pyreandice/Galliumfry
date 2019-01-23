#ifndef SERVICE_H_
#define SERVICE_H_
#include <vector>
#include <string>
#include <iostream>
class Service
{
public:
	Service();
	~Service();

	// get client name
	std::string getName() const;
	// get client type
	std::string getType() const;
	// get price rate
	double getPrice() const;
	// get dates
	std::string GetDate() const;

	// Overload comparison operators
	bool operator< (const Service&);
	bool operator> (const Service&);
	bool operator<= (const Service&);
	bool operator>= (const Service&);
	bool operator== (const Service&);
	bool operator!= (const Service&);

	// Overload the output operator
	friend std::ostream & operator<< (std::ostream& out, const Service &x);

	Service(std::string names = "null", std::string types = "null", double prices = 0.0, std::string dates = "null");

private:
	// Represents names in the file
	std::string FileNames;
	// Represents types in the file
	std::string FileTypes;
	// Represents the price per session in the file
	double FilePrices;
	// Represents the dates of the appointments in the file
	std::string FileDates;

	// compare righthand side
	int compare_to(const Service&);
};
#endif // !SERVICE_H_

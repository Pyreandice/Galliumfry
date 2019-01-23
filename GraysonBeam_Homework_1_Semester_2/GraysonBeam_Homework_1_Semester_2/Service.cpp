#include "Service.h"

Service::Service()
{
}

bool Service::operator<(const Service &right)
{
	return this -> compare_to(right) < 0;
}

bool Service::operator>(const Service &right)
{
	return this -> compare_to(right) > 0;
}

bool Service::operator<=(const Service &right)
{
	return this -> compare_to(right) <= 0;
}

bool Service::operator>=(const Service &right)
{
	return this -> compare_to(right) >= 0;
}

bool Service::operator==(const Service &right)
{
	return this -> compare_to(right) == 0;
}

bool Service::operator!=(const Service &right)
{
	return this -> compare_to(right) != 0;
}

Service::Service(std::string names, std::string types, double prices, std::string dates)
{
	FileNames = names;
	FileTypes = types;
	FilePrices = prices;
	FileDates = dates;
}

int Service::compare_to(const Service &right)
{
	if (this->getPrice() < right.getPrice())
	{
		return -1;
	}
	else if (this->getPrice() > right.getPrice())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

std::ostream & operator<<(std::ostream & out, const Service & x)
{
	out << x.getName() << " " << x.getType() << " " << x.getPrice() << " " << x.GetDate();
	return out;
}

std::string Service::getName() const
{
	return FileNames;
}

std::string Service::getType() const
{
	return FileTypes;
}

double Service::getPrice() const
{
	return FilePrices;
}

std::string Service::GetDate() const
{
	return FileDates;
}


Service::~Service()
{
}



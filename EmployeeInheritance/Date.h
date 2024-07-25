#pragma once
// a class to represent date
#include <array>

class Date
{
public:
	Date(unsigned int m = 1, unsigned d = 1, unsigned y = 1900); // default constructor

	void setDate(unsigned, unsigned, unsigned); // set month, day, year


	Date& operator++();  // prefix increment operator ++i
	Date operator++(int);  // postfix increment operator  i++
	Date& operator+=(unsigned);

	static bool Date::leapYear(unsigned y)// is year y a leap year or not *** DONE!!
	{
		return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	}

	bool Date::endOfMonth(unsigned d) const   // is day d end of the month ** DONE !!
	{
		if (month == 2) // February
		{
			if (leapYear(year))
				return (d == 29);
			else
				return (d == 28);
		}
		else
		{
			return (d == days[month]);
		}
	}
	int yearsEmployed(int currMonth, int currYear) const;



	virtual std::string to_string() const
	{
		return month + day + year + "\n";
	}

	operator std::string() const { return to_string(); } // trying to see if adding to string here and in phone number will fix issues.

private:
	unsigned int month, day, year;
	static const std::array<unsigned int, 13> days;
	void helpIncrement(); // utility method used internally for incrementing date

	// add operator<< and operator>> as friend here, similar to how was done for PhoneNumber class ** DONE!

	friend std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		os << date.month << "/" << date.day << "/" << date.year;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Date& date)
	{
		char slash1, slash2;
		is >> date.month >> slash1 >> date.day >> slash2 >> date.year;
		return is;
	}

};

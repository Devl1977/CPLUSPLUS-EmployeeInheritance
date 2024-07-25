#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include "BaseEmployee.h"

// add support to keep track of number of SalaryEmployees !!!DONE!!!
class SalaryEmployee : virtual public BaseEmployee
{
public:
	SalaryEmployee(std::string first = {}, std::string last = {}, std::string sin = {}, double pay={ 35000. }) :
		BaseEmployee(first, last, sin), salary(pay)
	{
	}
	
	~SalaryEmployee()
	{
		std::cout << "~SalaryEmployee.\n";
	}

	virtual double earning() const override
	{
		return salary;
	}



	virtual std::string to_string() const override
	{
		std::ostringstream os;
		os << (BaseEmployee::to_string() + ", pay=") << earning();
		return os.str();

	}

	void setSalary(double pay) 
	{
		salary = pay;
	}
	int setSalary(double pay, int count) // overloading setSalary
	{
		salary = pay;
		return 1;
	}
	double getSalary() const
	{
		return salary;
	}
protected:

	// implement friend operator<<() here
	// must use BaseEmployee input support.
	friend std::ostream& operator<<(std::ostream& os, const SalaryEmployee* sal);
	
	{
		os << static_cast<const BaseEmployee*>(sal); // using the base information here to use in the output stream.
		os << ", Salary: " << sal->getSalary(); // also adding salary to the output stream.
		return os;
	}
	
	// implement friend opereator>> here
	friend std::istream& operator>>(std::istream& is, SalaryEmployee& se);
	{
		
		is >> static_cast<BaseEmployee&>(se); // using the same logic as the output stream but this whole thing doesn't work.  Salary 
		// shows as undefined now.. I'm so confused.

		
		std::cout << "Enter Salary: ";
		is >> se.salary; // Assuming you have a member variable named 'salary'

		return is;
	}

private:
	double salary;
};

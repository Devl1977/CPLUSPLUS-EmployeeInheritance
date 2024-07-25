#pragma once

#include <string>
#include <sstream>
#include "SalaryEmployee.h"
#include "CommissionEmployee.h"
#include "BaseEmployee.h"

class SalaryCommissionEmployee : public SalaryEmployee, public CommissionEmployee
{
public:
	SalaryCommissionEmployee(std::string first = {},
		std::string last = {},
		std::string sin = {}, double pay = { 35000. }, double rate = { 0.10 }) :
		BaseEmployee(first, last, sin),
		SalaryEmployee(first, last, sin, pay), 
		CommissionEmployee(first, last, sin, rate)
	{
		setSalary(pay);
		setcommisionRate(rate);
	}

	~SalaryCommissionEmployee() 
	{
		std::cout << "salarycommission employee deleted";
	}

	virtual double earning() const override
	{
		return SalaryEmployee::earning() + CommissionEmployee::earning();
	}

	virtual std::string to_string() const override
	{	
		return "SalaryCommisionEmployee: " + BaseEmployee::to_string() + ", earning=" + std::to_string(earning());
	}

private:

// add static variable to keep track of number of SalComm Employees.
	static int numSalCommEmployees;  // ok i did this but it still doesn't work?
	int SalaryCommissionEmployee::numSalCommEmployees = 0; // so i initialized it to 0 but still not working!

	friend std::ostream& operator<<(std::ostream& os, SalaryCommissionEmployee* salComm)
	{
		std::cout<<"To be done by students. Use BaseEmployee string coversion operator to print the base info. THen add salary print out.\n";
		os << static_cast<BaseEmployee*> (salComm); // Print base info
		os << ", Salary: " << salComm->getSalary(); // Add salary info
		return os;
	}

	friend std::istream& operator>>(std::istream& is, SalaryCommissionEmployee* salComm)
	{
		// todo: implement this. Use BaseEmployee input opearator for receiving base info.
		is >> static_cast<BaseEmployee*>(salComm); //  I DONT UNDERSTAND WHY THIS DOESNT WORK...  I've looked everywhere.
		
		return is;
	}
};

#pragma once
#include <string>
#include <iostream>

#include "PhoneNumber.h"
#include "Date.h"

class BaseEmployee
{
public:
	BaseEmployee(std::string fn = {}, std::string ln = {}, std::string sn = {}, int salary = 0) : firstName(fn), lastName(ln), SIN(sn)//, baseSalary(salary)
	{
		++sNumEmployees;
	}

	virtual ~BaseEmployee()
	{
		--sNumEmployees;
		std::cout << "~BaseEmployee: " << firstName << " " << lastName << " deleted" << std::endl;
	}

	std::string getFirstName() const
	{
		return firstName;
	}
	std::string getLastName() const
	{
		return lastName;
	}
	std::string getSIN() const
	{
		return SIN;
	}
	int getBaseSalary() const
	{
		return baseSalary;
	}

	

	// add getter for lastname, SIN, baseSalary (done).
	// add setter for baseSalary (this was already done by you below)

	std::string getFullName() const
	{
		return firstName + " " + lastName;
	}


	void setBaseSalary(int newSalary) {
		baseSalary = newSalary;
	}

	operator std::string() const // string converter for BaseEmployee class
	{
		// todo: add  phone number and starting date to the following string output. ( done )
		return "Employee: " + firstName + " " + lastName + ", SIN: " + SIN + ", phone number: " + phone.to_string() + ", startDate: " + startDate.to_string();
	}


	static int getNumEmployees() //const // it is a "class" method vs "obj" method
	{
		return sNumEmployees;
	}

	std::string getPhoneNumber() const
	{
		return phone.to_string();
	}

	virtual double earning() const = 0; 

	int getYearsWorked() const
	{
		return startDate.yearsEmployed();
	}
	
	virtual std::string to_string() const
	{
		return "Employee: " + firstName + " " + lastName + ", SIN: " + SIN + ", phone number: " + phone.to_string() + ", startDate: " + startDate.to_string();
	}

protected:
	std::string firstName, lastName, SIN;
	PhoneNumber phone;
	Date startDate;
	int baseSalary{};

private:
	static int sNumEmployees; // to keep track of total number of employees.

	friend std::ostream& operator<<(std::ostream& os, const BaseEmployee* bEmp)
	{
		os << std::left << std::setw(19) <<
			"Employee Name:" << bEmp->firstName << " " << bEmp->lastName << std::left << std::setw(20) <<
			"\nStart Date: " << bEmp->startDate << std::left << std::setw(20) <<
			"\nPhone Number: " << bEmp->phone << std::left << std::setw(20) << std::endl;
		
		return os;
	}

	// add overload for output operator >> bellow:
	friend std::istream& operator>>(std::istream& is, BaseEmployee* bEmp)
	{
		is >> std::left >> std::setw(19) >>
			
			std::cout << "Enter Employee First Name: ";
			is >> bEmp->firstName;

			std::cout << "Enter Employee Last Name: ";
			is >> bEmp->lastName;

			std::cout << "StartDate: ";
			is >> bEmp->startDate;

			std::cout << "Phone: ";
			is >> bEmp->phone;

		return is;
	}
};
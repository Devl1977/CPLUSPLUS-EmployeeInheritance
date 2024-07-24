
#include <iostream>
#include <vector>
#include "BaseEmployee.h"
#include "CommissionEmployee.h"
#include "SalaryCommisionEmployee.h"
#include "Date.h"

int BaseEmployee::sNumEmployees{};


using namespace std;
int main()
{

	// This assignment is to test functionalities supported by the Employee Hierarchy along with operator overloading we introduced in class, in the form of overloading <<, >>, ++, and so on. The steps to perform the tests are as following:
	// 1- Complete operator overloading for stream input >> and output << for BaseEmployee, SalaryEmployee, CommisionEmployee, and SalaryCommisionEmployee, and Date and PhoneNumber classes. You are supposed to use the input operator overload to load the data from the data file EmployeeData.txt. Read the data in this file, line by line (after skipping the first few comment lines). For each line that you read, first detect what type of employee it is. Based on the type, construct an employee of that type and add that employee to the vector of employees bellow:
	vector<BaseEmployee*> employees;
	ifstream file("EmployeeData.txt");
	// suppose you have read a line from the file into a string str. Also suppose you have determined that str is for SalaryEmployee. Then constructing the employee and adding it to the vector goes as following:
	string aline; // suppose you have read this line from the input file
	SalaryEmployee* sEmp0{ new SalaryEmployee; };
	istringstream is{ aline };
	is >> sEmp0;
    employees.push_back(&sEmp0);
	// The above is a sample code. Your code goes here bellow:
	// ....
	
	// 2- print all the employees out using output operator >> for each employee.
	cout<<"Printing all the employees:\n";
	// YOur code goes here ....
	
	// 3-Increase salary for SalaryEmployees by 10% and increase commission rate for the rest by 3%. Then print each employee 
	//  new earning using earning() method.
	cout << "Increase salary for all SalaryEmployees and SalaryCommissionEmployees by 10% " <<
		"  and increase commission rate by 3% " <<
		" and finally print the updated earnings below : \n\n";
	// Your code goes here: 

	
	// 4-Find all employees who have been with the company more than 2 years, and print those employees info using output operator >>
	cout<<"List of all employees who have been with the company for more than 2 years to date:\n";
	// Your code goes here: 

	
	// 5- Compute average earning for each type of employee in the company, and print the result
	// Your code goes here: 

	cout<<"\nAverage earning for SalaryEmployees: ";
	// Your code goes here: 

	cout<<"\nAverage earning for CommissionEmployees: ";
	// Your code goes here: 

	cout<<"\nAverage earning for SalaryCommissionEmployees: ";
	// Your code goes here: 

	// 5- Print average earning for the whole company. Then Remove the toppest earning employee from the company and then compute  average company earning again and print it.
	cout<<"\nAverage employees earning for the whole company:";
	// Your code goes here: 

	cout << "\n Find the toppest earner and print his/her info.\n";
	// Your code goes here: 

	
	cout<<"\nRemove the toppest earner and print the earning average for the company before and after the removal: ";
	// Your code goes here: 
	
	cout << "\nDelete all dynamic object:";
		// Your code goes here: 

	cout<<"\nEnd of tests. Enter any key to finish.";
	cin.ignore();

	return 0;
}
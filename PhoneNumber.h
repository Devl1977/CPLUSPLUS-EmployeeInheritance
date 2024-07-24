#pragma once
#include <string>
#include <iostream>
#include <iomanip>

struct PhoneNumber
{
	std::string areaCode; // 3 digit area code
	std::string exchange; // 3-digit exchange
	std::string line; // 4-digit line

	virtual std::string to_string() const 
	{
		return "(" + areaCode + ")" + exchange + "-" + line;
	}

	operator std::string() const { return to_string(); }

	friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& pn)
	{
		// to be done by students. Must use to_string() method above. ** DONE!
		os << pn.to_string(); // I'm assuming this is to display the phone number using the to_string() method? but im not sure if this is all you're asking for???
		return os;
	}

	// we expect the phone number be given in this format : (604) 333-3131
	friend std::istream& operator>>(std::istream& is, PhoneNumber& pn)
	{
		is.ignore(2); // skipping (
		is >> std::setw(3) >> pn.areaCode;
		is.ignore();
		is >> std::setw(3) >> pn.exchange;
		is.ignore();
		is >> std::setw(4) >> pn.line;

		return is; // this is to enable us to do things like: std::cin >> a >> b >> c;

	}
};

/* sample test use:
	PhoneNumber pn;

	std::cout << "Enter phone number in the form (555) 555-5555 : " << std::endl;
	std::string msg;
	//msg = std::getline();
	std::cin >> pn >> msg;
	std::cout << "Msg is :" << msg << std::endl;
	std::cout << "\n The phone number entered was: \n";
	std::cout << pn << std::endl;
	//operator<<(std::cout, pn);


*/
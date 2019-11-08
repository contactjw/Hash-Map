/*
 * Employee.hpp
 *
 *  Created on: Nov 7, 2019
 *      Author: johnwest
 */

#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_
#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
	string employeeKey;
	string lastName;
	string firstName;
	int income;

	Employee();
	virtual ~Employee();
};

#endif /* EMPLOYEE_HPP_ */

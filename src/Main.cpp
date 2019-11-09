//============================================================================
// Name        : HashClass.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "Hash.hpp"
using namespace std;

int main() {

	Hash* newHashTable = new Hash();
	Employee* newEmp = nullptr;
	fstream iFile;
	iFile.open("EmployeesExample.txt");


	if (iFile.is_open()) {
		cout << "The file is open... reading employee information.\n\n";
	}
	string key;
	string lastName;
	string firstName;
	int income;

	while (iFile >> key >> lastName >> firstName >> income) {
		newEmp = new Employee();
		newEmp->employeeKey = key;
		newEmp->lastName = lastName;
		newEmp->firstName = firstName;
		newEmp->income = income;
		if(newHashTable->Insert(newEmp->employeeKey, newEmp)) {
			cout << "Successful insertion." << endl;
		}

	}


//	Employee* foundEmployee = new Employee();
//
//	string tempKey;
//	cout << "Enter an employee key and I will find it: ";
//	cin >> tempKey;
//
//	newEmp->employeeKey = tempKey;
//
//	foundEmployee = newHashTable->Find(newEmp->employeeKey);
//
//
//	cout << "\nFound Employee Information\n";
//	cout << "Employee Key: " << foundEmployee->employeeKey << endl;
//	cout << "Employee first name: " << foundEmployee->firstName << endl;
//	cout << "Employee last name: " << foundEmployee->lastName << endl;
//	cout << "Employee income: " << foundEmployee->income << endl;

	cout << "\nCollision Count: " << newHashTable->CollisionCount() << endl;

	newHashTable->PrintCollisionCount();

	cout << "Program ending.. goodbye!" << endl; // prints !!!Hello World!!!


	iFile.close();
	return 0;
}

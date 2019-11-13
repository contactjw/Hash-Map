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
		if (newHashTable->Insert(newEmp->employeeKey, newEmp)) {
			cout << "Successful insertion." << endl;
		}

	}

	Employee* foundEmployee = nullptr;
	string tempKey;
	bool endLoop = false;

	while (!endLoop) {
		cout
				<< "Enter an employee key and I will find it, or enter end when done: ";
		getline(cin, tempKey);
		if (tempKey == "End" || tempKey == "end") {
			endLoop = true;
		} else {
			foundEmployee = newHashTable->Find(tempKey);
			if (foundEmployee == nullptr) {
				cout << "Employee not found. Try again.\n\n";
			} else {
				cout << "\nFound Employee Information\n";
				cout << "Employee Key: " << foundEmployee->employeeKey << endl;
				cout << "Employee first name: " << foundEmployee->firstName
						<< endl;
				cout << "Employee last name: " << foundEmployee->lastName
						<< endl;
				cout << "Employee income: " << foundEmployee->income << endl;
			}
		}
	}

	cout << "\nTotal Collision Count: " << newHashTable->CollisionCount()
			<< endl;

	newHashTable->PrintCollisionCount();

	cout << "\nProgram ending.. goodbye!" << endl;

	delete newHashTable;
	newHashTable = nullptr;

	iFile.close();

	return 0;
}

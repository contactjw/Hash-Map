
#ifndef HASH_HPP_
#define HASH_HPP_
#include <iostream>
#include <string>
#include <cmath>
#include "Employee.hpp"
using namespace std;

class Hash {
public:
	Hash();
	bool Insert(string, Employee*);
	Employee* Find(string);
	int CollisionCount();
	void PrintCollisionCount();
	void PrintARow(); // remove this function later
	virtual ~Hash();

	struct HashNode {
		string keyValue;
		Employee* employee;
	};

private:
	static const int tableSize = 1000;
	HashNode** hashTable[tableSize];
	int collisionCount;

};

#endif /* HASH_HPP_ */

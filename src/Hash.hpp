
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
	HashNode** hashTable[1000];
	int collisionCount;
	int tableSize;

};

#endif /* HASH_HPP_ */

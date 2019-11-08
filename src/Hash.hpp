
#ifndef HASH_HPP_
#define HASH_HPP_
#include <iostream>
#include <string>
#include "Employee.hpp"
using namespace std;

struct HashNode {
	string keyValue;
	Employee* employee;
};


class Hash {
private:
	HashNode** hashTable[1000];
	int collisionCount;
public:
	Hash();
	bool Insert(string, Employee*);
	Employee* Find(string);
	int CollisionCount();
	void PrintCollisionCount();
	virtual ~Hash();
};

#endif /* HASH_HPP_ */

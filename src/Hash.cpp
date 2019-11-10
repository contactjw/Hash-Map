
#include "Hash.hpp"

// Description
// 	- Constructor to set the collisionCounter to 0, and fill the array with Buckets of size 20.
// Preconditions
//  - must create a Hash object in order for constructor to execute.
// Postconditions
// 	- collisionCount is now 0.
//  - each hashTable index now has an array of 20 available spaces for HashNode pointers.
Hash::Hash() {
	collisionCount = 0;
	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = new HashNode*[20];
	}
}

bool Hash::Insert(string keyVal, Employee* emp) {
	// Hash function
	int hashValue = 0;
	int index;

	// This is not the simple hashing algorithm, but making sure words with the same letters
	// ie. (ab and ba) do not get hashed to the same location.
	// The simple algorithm would be to remove pow(), and just have
	// hashValue = hashValue + static_cast<int>(keyVal[i]);
	for (int i = 0; i < keyVal.length(); i++) {
		hashValue = hashValue + pow(static_cast<int>(keyVal[i]), i);
	}

	index = hashValue % tableSize;

	// Create the HashNode to insert into table
	HashNode* newHashNode = new HashNode();
	newHashNode->keyValue = keyVal;
	newHashNode->employee = emp;
	if (hashTable[index][0] == nullptr) {
		hashTable[index][0] = newHashNode;
		cout << "HashNode properly inserted at index " << index << " bucket " << "0" << endl;
		return true;
	}
	else {
		int i = 0;
		while (hashTable[index][i] != nullptr) {
			i++;
			collisionCount++;
		}
		hashTable[index][i] = newHashNode;
		cout << "HashNode properly inserted at index " << index << " bucket " << i << endl;
		return true;
	}
	return false;
}

Employee* Hash::Find(string keyVal) {
	int hashValue = 0;
	int index;

	for (int i = 0; i < keyVal.length(); i++) {
		hashValue += static_cast<int>(keyVal[i]);
	}
	index = hashValue % tableSize;

	for (int i = 0; i < 20; i++) {
		if (hashTable[index][i] == nullptr)
			break;
		if (hashTable[index][i]->employee->employeeKey == keyVal) {
			return hashTable[index][i]->employee;
		}
	}

	return nullptr;
}

int Hash::CollisionCount() {
	return collisionCount;
}

void Hash::PrintCollisionCount() {
	for (int i = 0; i < 1000; i++) {
		int rowCollisions = 0;
		for (int j = 1; j < 20; j++) {
			if (hashTable[i][j] != nullptr)
				rowCollisions++;
		}
		cout << "---------------------------------" << endl;
		cout << "Row index:" << i << endl;
		cout << "# of Collisions: " << rowCollisions << endl;
	}
}

Hash::~Hash() {
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 20; j++) {
			delete hashTable[i][j]->employee;
			hashTable[i][j]->employee = nullptr;
			hashTable[i][j] = nullptr;
			delete [] hashTable[j];
		}
	}
}




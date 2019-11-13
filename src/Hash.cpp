#include "Hash.hpp"

// Description
// 	- Constructor to set the collisionCounter to 0, and fill the array with Buckets of size 20.
// Preconditions
//  - Must create a Hash object in order for constructor to execute.
// Postconditions
// 	- collisionCount is now 0.
//  - each hashTable index now has an array of 20 available spaces for HashNode pointers.
Hash::Hash() {
	collisionCount = 0;
	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = new HashNode*[20];
	}
}

// Description
// 	- Function to insert an Employee into the Hash Map.
// Preconditions
//  - Must have a valid string keyVal and Employee* as arguments.
// Postconditions
// 	- The hash function will generate a hashIndex and copy the key and Employee information
//  	 to the HashNode for insertion into the Hash Map.
//  - If an element exists at said index, collisionCount will be incremented and
//       inserted in the next available index through linear probing.
bool Hash::Insert(string keyVal, Employee* emp) {
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

	HashNode* newHashNode = new HashNode();
	newHashNode->keyValue = keyVal;
	newHashNode->employee = emp;
	if (hashTable[index][0] == nullptr) {
		hashTable[index][0] = newHashNode;
		return true;
	} else {
		int i = 0;
		while (hashTable[index][i] != nullptr) {
			i++;
		}
		hashTable[index][i] = newHashNode;
		return true;
	}
	return false;
}

// Description
// 	- Function to find an Employee through passing a keyVal as an argument.
// Preconditions
//  - Must have a valid string keyVal in order to generate the proper index.
// Postconditions
// 	- The hash function will generate a hashIndex and find the key in the Map that matches
//       the key that the user was looking for.  It will return the Employee information.
//  - If the keyVal does not generate an index with an employee at said location, nullptr
//       will be returned.
Employee* Hash::Find(string keyVal) {
	int hashValue = 0;
	int index;

	for (int i = 0; i < keyVal.length(); i++) {
		hashValue = hashValue + pow(static_cast<int>(keyVal[i]), i);
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

// Description
// 	- Function to return the number of collisions that occurred during insertion.
// Preconditions
//  - Must return the collisionCount.
// Postconditions
// 	- The function returns the number of collisions that occurred during insertion.  If no
//       collisions occurred, the value 0 is returned.
int Hash::CollisionCount() {
	for(int i = 0; i < tableSize; i++) {
		for (int j = 1; j < 20; j++) {
			if (hashTable[i][j] != nullptr) {
				collisionCount++;
			}
		}
	}
	return collisionCount;
}

// Description
// 	- Function to print the number of collisions that occurred at each index.
// Preconditions
//  - Must have a Hash object created in main to call the function.
// Postconditions
// 	- The index of the Hash will be printed, along with the number of collisions that occurred
//       at the specified index.
void Hash::PrintCollisionCount() {
	for (int i = 0; i < 1000; i++) {
		int rowCollisions = 0;
		for (int j = 1; j < 20; j++) {
			if (hashTable[i][j] != nullptr)
				rowCollisions++;
		}
		cout << "---------------------------------" << endl;
		cout << "Index:" << i << endl;
		cout << "# of Collisions: " << rowCollisions << endl;
	}
}

// Description
// 	- Function to deallocate the memory that was created for the Hash object.
// Preconditions
//  - Must have a Hash object created, once it goes out of scope, the destructor will execute.
// Postconditions
// 	- All Employees, HashNodes, and Arrays will be deallocated.
Hash::~Hash() {
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 20; j++) {
			delete hashTable[i][j]->employee;
			hashTable[i][j]->employee = nullptr;
			hashTable[i][j] = nullptr;
			delete[] hashTable[j];
		}
	}
}


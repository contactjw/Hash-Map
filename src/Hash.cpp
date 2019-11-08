
#include "Hash.hpp"

Hash::Hash() {
	collisionCount = 0;
	tableSize = 1000;
	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = new HashNode*[20];
	}
}

bool Hash::Insert(string keyVal, Employee* emp) {
	// Hash function
	int hashValue = 0;
	int index;
	for (int i = 0; i < keyVal.length(); i++) {
		hashValue = hashValue + static_cast<int>(keyVal[i]);
	}
	index = hashValue % tableSize;

	// Create the HashNode to insert into table
	HashNode* newHashNode = new HashNode();
	newHashNode->keyValue = keyVal;
	newHashNode->employee = emp;
	if (hashTable[index][0] == nullptr) {
		hashTable[index][0] = newHashNode;
		cout << "HashNode properly inserted at key: " << index << ", " << "0" << endl;
		return true;
	}
	else {
		int i = 0;
		while (hashTable[index][i] != nullptr) {
			i++;
			collisionCount++;
		}
		hashTable[index][i] = newHashNode;
		cout << "HashNode properly inserted at key: " << index << ", " << i << endl;
		return true;
	}
	return false;
}

Employee* Hash::Find(string keyVal) {
	int hashValue = 0;
		for (int i = 0; i < keyVal.size(); i++) {
			hashValue += static_cast<int>(keyVal[i]);
		}
		hashValue %= 1000;

	if (hashTable[hashValue][0]) {
		return hashTable[hashValue][0]->employee;
	}
	else {
		int i = 0;
		while (hashTable[hashValue][i]->keyValue != keyVal) {
			i++;
			if (i > 20) {
				return nullptr;
			}
		}
		return hashTable[hashValue][i]->employee;
	}
}

int Hash::CollisionCount() {
	return collisionCount;
}

void Hash::PrintCollisionCount() {
	for (int i = 0; i < 1000; i++) {
		int newCollisionCount = 0;
		for (int j = 0; j < 20; j++) {
			if (hashTable[i][j] != nullptr) {
				newCollisionCount++;
			}
		}
		cout << "Row " << i + 1 << " Collisions: " << newCollisionCount << endl;
	}

}

void Hash::PrintARow(){
	for(int i = 0; i < 4; i++) {
		cout << (hashTable[0][i]) << endl;
	}
}



Hash::~Hash() {
	// TODO Auto-generated destructor stub
}


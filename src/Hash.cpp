
#include "Hash.hpp"

Hash::Hash() {
	collisionCount = 0;
	for (int i = 0; i < 1000; i++) {
		hashTable[i] = new HashNode*[20];
	}
}

bool Hash::Insert(string keyVal, Employee* emp) {
	int hashValue = 0;
	for (int i = 0; i < keyVal.size(); i++) {
		hashValue += static_cast<int>(keyVal[i]);
	}
	hashValue %= 1000;
	HashNode* newHashNode = new HashNode();
	newHashNode->keyValue = keyVal;
	newHashNode->employee = emp;
	if (!hashTable[hashValue][0]) {
		hashTable[hashValue][0] = newHashNode;
		cout << "HashNode properly inserted at key: " << hashValue << endl;
		return true;
	}
	else {
		int i = 0;
		while (hashTable[hashValue][i] != nullptr) {
			i++;
			collisionCount++;
		}
		hashTable[hashValue][i] = newHashNode;
		cout << "HashNode properly inserted at key: " << hashValue << endl;
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
		collisionCount = 0;
		for (int j = 1; j < 20; j++) {
			while (hashTable[i][j] != nullptr) {
				collisionCount++;
			}
		}
		cout << "Row " << i + 1 << " Collisions: " << collisionCount << endl;
	}

}




Hash::~Hash() {
	// TODO Auto-generated destructor stub
}


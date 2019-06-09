#ifndef HASHMAP_H
#define HASHMAP_H
#include "HashEntry.h"
#include <string>

using namespace std;
const long TABLE_SIZE = 12725525;
template<class T>
class HashMap
{
private:
	HashEntry<T> **table;
public:
	HashMap()
	{
		table = new HashEntry<T>*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++) { table[i] = NULL; }
	}
	T get(int &key)
	{
		int hash = (key % TABLE_SIZE);
		
		while (table[hash] != NULL && table[hash]->getKey() != key)
		{
			hash = (hash + 1) % TABLE_SIZE;
		}
		
		if (table[hash] == NULL) { return T(); }
		else
		{
			return table[hash]->getValue();
		}
	}
	void put(int key, T value)
	{
		int hash = (key % TABLE_SIZE);
		while (table[hash] != NULL && table[hash]->getKey() != key)
		{
			hash = (hash + 1) % TABLE_SIZE;
		}
		if (table[hash] != NULL)
		{
			delete table[hash];
		}
		table[hash] = new HashEntry<T>(key, value);
	}
	~HashMap()
	{
		for (long i = 0; i < TABLE_SIZE; i++)
		{
			if (table[i] != NULL) delete table[i];
		}
		delete[] table;
	}
};
#endif //!HASHMAP_H
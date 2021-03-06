#ifndef  __HASHTABLE_H__
#define  __HASHTABLE_H__



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <string.h>

static size_t GetNextPrime(size_t value)
{
	int i = 0;
	//const int _PrimeSize = 28;
	static const unsigned long _PrimeList[28] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};

	for (; i < 28; ++i)
	{
		if (_PrimeList[i] > value)
		{
			return _PrimeList[i];
		}
	}

	return _PrimeList[27];
}

static size_t StrHash(const char* str)
{
	size_t hash = 0;
	size_t seed = 131;
	while (*str)
	{
		//hash += *str;
		hash = hash*seed + *str;
		++str;
	}

	/*printf("%u\n", hash);*/

	return hash;
}


typedef  char* HTKeyType;
typedef int HTValueType;

enum State
{
	EMPTY,
	EXITS,
	DELETE,
};

typedef struct HashNode
{
	enum State		_state;
	HTKeyType	_key;
	HTValueType _value;
}HashNode;

typedef struct HashTable
{
	HashNode* tables;
	size_t len;   // 长度
	size_t size;  // 有效数据个数
}HashTable;

void HTInit(HashTable* ht, size_t len);
void HTDestory(HashTable* ht);
int HTInsert(HashTable* ht, HTKeyType key, HTValueType value);
int HTRemove(HashTable* ht, HTKeyType key);
HashNode* HTFind(HashTable* ht, HTKeyType key);
int HTSize(HashTable* ht);
int HTEmpty(HashTable* ht);
void HashPrint(HashTable* ht);



#endif
#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
		
		Node* next;
	};
	struct Bucket
	{
		int count;

		Node* head;
	};

	int size;
	int capacity;

	Bucket* bucket;
public:
	HashTable()
	{
		size = 0;
		capacity = 8;

		bucket = new Bucket[capacity];

		for (int i = 0;i < capacity;i++)
		{
			bucket[i].head = nullptr;
			bucket[i].count = 0;
		}
	}

	template <typename KEY>
	unsigned int hash_function(KEY key)
	{
		return (unsigned int)key % capacity;
	}

	template<>
	unsigned int hash_function(const char* key)
	{
		unsigned int sum = 0;

		for (int i = 0; *key != '\0'; i++)
		{
			sum += key[i];

			key = key + 1;
		}
		return sum % capacity;
	}
	void insert(KEY key, VALUE value)
	{
		// 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = hash_function(key);

		// 새로운 노드를 생성합니다.
		Node* newNode = new Node;

		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		// 노드가 1개라도 존재하지 않는다면
		if (bucket[hashIndex].count == 0)
		{
			// bucket[hashIndex] 의 head 포인터가 newNode를 가리키게 합니다
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;
			bucket[hashIndex].head = newNode;
		}

		// bucket[hashIndex] 의 count 를 증가시킵니다.
		bucket[hashIndex].count++;

		size++;
	}
	const int& bucket_count()
	{
		return bucket->count;
	}
	const float& load_factor()
	{
		return bucket->count % capacity;
	}
};

int main()
{
	HashTable<const char*, int> hashTable;

	hashTable.insert("Abussal Mask", 3000);
	hashTable.insert("Bami's Cinder", 1000);

	hashTable.insert("Chain Vest", 8000);

	cout << "bucket count : " << hashTable.bucket_count() << endl;
	cout << "부하율 : " << hashTable.load_factor() << endl;

	return 0;
}
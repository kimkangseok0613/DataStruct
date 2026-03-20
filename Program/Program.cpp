#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	T* pointer;
	int count;
	int capacity;
public:
	Vector()
	{
		count = 0;
		capacity = 0;
		pointer = nullptr;
	}
	void resize(int newSize)
	{
		capacity = newSize;
		T* newPointer = new T[newSize];
		for (int i = 0; i < capacity; i++)
		{
			newPointer = NULL;
		}
		newPointer
		
	}
};

int main()
{
	Vector<int> vector;

	vector.resize(10);

	return 0;
}
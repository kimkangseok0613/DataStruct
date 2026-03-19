#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	int size;
	Node* head;
public:
	List()
	{
		size = 0;
		head = nullptr;
	}
	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{			
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next
				;
			head->next = newNode;
			
			head = newNode;
		}
		size++;
	}
	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "Linked list is empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (size == 1)
			{
				head = nullptr;
			}
			else
			{
				Node* currentNode = head->next;

				while (currentNode->next != head)
				{
					currentNode = currentNode->next;
				}

				currentNode->next = head->next;
				head = currentNode;
			}
			delete deleteNode;
			size--;
		}
	}
};

int main()
{
	List<int> list;

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	list.pop_back();

	return 0;
}
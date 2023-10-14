#include <iostream>

using namespace std;

template <typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	void pop_front();
	void clear();
	T& operator[](const int index);
	int size() { return Size; }
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();

private:

	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data, Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* Previous(int index)
	{
		Node<T>* temp = head;
		for (int i = 0; i < index - 1; i++) temp = temp->pNext;
		return temp;
	}

	int Size;
	Node<T>* head;
};

template <typename T>
List<T>::List()
{
	Size = 0;
	this->head = nullptr;
}

template <typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
		Size++;
	}
	else
	{
		Node<T>* current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

		Size++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = this->head;

	head = head->pNext;

	delete temp;
	
	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int iterator = 0;
	Node<T>* current = head;
	while (iterator != index)
	{
		current = current->pNext;
		iterator++;
	}
	return current->data;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (!index) push_front(data);
	else
	{
		Node<T>* previous = Previous(index);

		previous->pNext = new Node<T>(data, previous->pNext);

		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (!index) pop_front();
	else
	{
		Node<T>* previous = Previous(index);

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}






int main()
{
	List<int> lst;
	lst.push_back(3);
	lst.push_back(6);
	lst.push_back(74658);
	lst.push_front(6);
	lst.insert(2, 2);
	cout << lst[2];
	return 0;
}
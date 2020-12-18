#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
	Node* pNext;
	T data;

	Node(T data = T(), Node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
	template<class T>
	friend class ListIterator;
};
template<class T>
class ListIterator
{
protected:
	Node<T>* i;
public:
	ListIterator(Node<T>* _n) : i(_n) {}
	ListIterator(ListIterator<T>& _v) : i(_v.i) {}
	~ListIterator() {}

	bool CanMove() { return (i->pNext != nullptr); }
	void Move() { i = i->pNext; }

	bool operator==(const ListIterator<T>& _v) { return i == _v.i; }
	ListIterator<T> operator++(int)
	{
		if (!CanMove())
			throw logic_error("reached end");
		Move();
		return (*this);
	}
	ListIterator<T>& operator=(const ListIterator<T>& _v) { i = _v.i; return (*this); }

	T GetData() { return i->data; }
};
template<class T>
class List
{
private:

	int Size;
	Node<T>* head;

	Node<T>* find_prev(int index)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		return previous;
	}
public:
	List()
	{
		Size = 0;
		head = nullptr;
	}
	List(List<T>& _l)
	{
		ListIterator<T> k = _l.begin();
		Size = 0;
		head = nullptr;
		for (int i = 0; i < _l.Size; i++)
		{
			push_back(k.GetData());
			if (k.CanMove())
				k++;
		}
	}
	~List()
	{
		clear();
	}

	int GetSize() const { return Size; }

	ListIterator<T> begin() { return ListIterator<T>(head); }
	ListIterator<T> end()
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
			current = current->pNext;

		return ListIterator<T>(current);
	}

	void push_back(T data)
	{
		if (head == nullptr)
			head = new Node<T>(data);
		else
		{
			Node<T>* current = this->head;
			while (current->pNext != nullptr)
				current = current->pNext;
			current->pNext = new Node<T>(data);
		};

		Size++;
	}

	void pop_front()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}

	void clear()
	{
		while (Size)
			pop_front();
	}

	void push_front(T data)
	{
		head = new Node<T>(data, head);
		Size++;
	}

	void insert(T data, int index)
	{
		if (index < 0 || index > Size)
			throw logic_error("incorrect index");

		if (index == 0)
			push_front(data);
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* newNode = new Node<T>(data, previous->pNext);
			previous->pNext = newNode;
			
			Size++;
		}
	}

	void remove(int index)
	{
		if (index < 0 || index >= Size)
			throw logic_error("incorrect index");

		if (index == 0)
			pop_front();
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;

			delete toDelete;
			Size--;
		}
	}

	void pop_back()
	{
		if (Size == 0)
			throw logic_error("list empty");

		remove(Size - 1);
	}

	friend ostream& operator << (ostream& ostr, List<T>& _l)
	{
		ListIterator<T> k = _l.begin();
		ostr << "{";
		for (int i = 0; i < _l.GetSize() - 1; i++)
		{
			ostr << k.GetData() << ", ";
			k++;
		}
		ostr << k.GetData() << "}";

		return ostr;
	}
};
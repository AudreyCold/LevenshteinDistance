#include <iostream>
using namespace std;

template<typename T>
class Stack
{
public:
	Stack();
	~Stack();

	void push(T data); //insert new first element
	T pop(); //delete first element
	T peek(); //shows first element data
	size_t get_size() { return size; }; //function returns Stack size

private:
	//class Node for every node of List
	class Node
	{
	public:
		Node* next; //next element
		T data; //element value

				//Node constructor
		Node(T data = 0, Node * next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	size_t size; //number of elements
	Node* head; //first element

};

//constructor
template<typename T>
Stack<T>::Stack()
{
	size = 0;
	head = nullptr;
}

//destructor
template<typename T>
Stack<T>::~Stack()
{
	while (size) {
		pop();
	}
}

//insert new first element
template<typename T>
void Stack<T>::push(T data)
{
	head = new Node(data, head);
	size++;
}

//delete first element
template<typename T>
T Stack<T>::pop()
{
	if (head) {
		T dataFromHead = peek();
		Node* temp = head;
		if (head->next)
			head = head->next;
		else
		{
			head = nullptr;
		};
		delete temp;
		size--;
		return dataFromHead;
	}
	else throw out_of_range("Error: index is out of Stack range");
}

//shows first element data
template<typename T>
T Stack<T>::peek()
{
	if (!head) throw out_of_range("Error: index is out of Stack range");
	return this->head->data;
}



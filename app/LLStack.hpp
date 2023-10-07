#ifndef __ICS46_LL_STACK_HPP
#define __ICS46_LL_STACK_HPP

#include "runtimeexcept.hpp"

class StackEmptyException : public RuntimeException 
{
public:
	StackEmptyException(const std::string & err) : RuntimeException(err) {}
};

template<typename T>
struct Node{
	T data;
	Node* next;

	Node (const T& val, Node* nextNode = nullptr) : data(val),next(nextNode)
	{

	}
};
// This is the LLStack class you will be implementing for this project.
// Remember to see the write-up for more details!
template<typename Object>
class LLStack
{
private:
	// fill in private member data here
	//Node<Object>* head;

	Node<Object>* copy(Node<Object>* originNode); // helper function to make a deep copy of a linked list

	void free(Node<Object>* headToDelete); //helper function to free space and delete all entries within a list
public:
	Node<Object>* head;

	// constructor
	LLStack(); 

	// copy constructor (remember, deep copy!)
	LLStack(const LLStack & st);

	// assignment operator (remember, deep copy!)
	LLStack & operator=(const LLStack & st);

	
	// destructor
	~LLStack();
	
	size_t size() const noexcept;

	bool isEmpty() const noexcept;

	// We have two top() functions.  The first gets called if your LLStack is not
	// a const, while the latter gets called on a const LLStack
	// (the latter might occur via const reference parameter, for instance).
	// Be sure to test both!  It is important when testing to ensure that
	// EVERY funtion gets called and tested!
	Object & top();
	const Object & top() const;

	void push(const Object & elem) noexcept;
	void pop();

};











template <typename Object>
Node<Object>* LLStack<Object>::copy(Node<Object>* originNode)
{
	if (!originNode)//if there are no more entries in the linked list
	{
		return nullptr;
	}
	//create a Node object and point it to the allocated space for a new node
	//object that copies the data from the origin node(from st)
	Node<Object>* newNode = new Node<Object>(originNode->data,nullptr);
	newNode->next = copy(originNode->next);
	return newNode;
	//recursively go through the entirety of the list, copying the data and
	//pointing each node to a newly allocated set of data one at a time
}


template<typename Object>
void LLStack<Object>::free(Node<Object>* headToDelete)
{
	Node<Object>* current = headToDelete;
	while(current)
	{
		Node<Object>* next = current->next;
		delete current;
		current = next;
	}
}











template <typename Object>
LLStack<Object>::LLStack():head(nullptr)
{
	// TODO: Fill in your constructor implementation here.
}

template <typename Object>
LLStack<Object>::LLStack(const LLStack & st):head(nullptr)
{
	// TODO: Fill in your copy constructor implementation here.
	head = copy(st.head);
}

template <typename Object>
LLStack<Object> & LLStack<Object>::operator=(const LLStack & st)
{	
	//we want to first create a new list then set that equal to the current list before deleting
	//this is to account for if they use the = sign on the same object
	Node<Object>* newHead = copy(st.head);
	free(head); //free up space in current list
	head = newHead;
	return *this; // Stub so this function compiles without implementation.
}


template <typename Object>
LLStack<Object>::~LLStack()
{
	free(head); //delete every node in our linked list
}


template <typename Object>
size_t LLStack<Object>::size() const noexcept
{
	// TODO: Fill in your size() implementation here.
	Node<Object>* countingNode = head;
	size_t i = 0; //returnable index
	for(; countingNode != nullptr; ++i) // iterate index for each node
	{
		countingNode = countingNode->next;
	}
	return i; // Stub so this function compiles without an implementation.
}


template <typename Object>
bool LLStack<Object>::isEmpty() const noexcept
{
	return size() == 0; // Stub so this function compiles without an implementation.
}

template <typename Object>
Object& LLStack<Object>::top()
{
	// TODO: Fill in your top() implementation here.
	// The following is a stub just to get the template project to compile.
	// You should delete it for your implementation.
	if (!head)
	{
		throw StackEmptyException("The stack is empty!");
	}
	return head->data;
}

template <typename Object>
const Object& LLStack<Object>::top() const
{
	// TODO: Fill in your const top() implementation here.
	// The following is a stub just to get the template project to compile.
	// You should delete it for your implementation.
	if (!head)
	{
		throw StackEmptyException("The stack is empty!");
	}
	return head->data;
}

template <typename Object>
void LLStack<Object>::push(const Object& elem) noexcept
{	
	Node<Object>* newNode = new Node<Object>(elem,head);
	head = newNode;
}

template <typename Object>
void LLStack<Object>::pop()
{	
	if(head)
	{
		Node<Object>* popNode = head;
		head = head->next;
		delete popNode;
	}
	else
	{
		throw StackEmptyException("The stack is empty!");
	}
}









#endif 

#pragma once

// MOVE TO PRIVATE, SEPERATE MAIN INTO FUNCTIONS, CHANGE THE operator= WAY OF ALLOCATING MEMOry

class Stack
{
private:
	int *items;
	int topElement;
	size_t size;

public:
	// Constructor
	Stack();

	// Copy Constructor
	Stack(const Stack &source);

	// Destructor
	~Stack();

	// Asignment Operator
	Stack &operator=(const Stack &rhs);

	void errorDelete();
	void memAlloc(size_t sizeAlloc);
	void printStack() const;
	void push(int element);
	int pop();
	int top();
	bool isEmpty() const;
};

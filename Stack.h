#pragma once

class Stack
{
private:
	int *items;
	int topElement;
	size_t size;

	void errorDelete();
	void memAlloc(size_t sizeAlloc);
public:
	// Constructor
	Stack();

	// Copy Constructor
	Stack(const Stack &source);

	// Destructor
	~Stack();

	// Asignment Operator
	Stack &operator=(const Stack &rhs);

	void printStack() const;
	void push(int element);
	int pop();
	int top();
	bool isEmpty() const;
};

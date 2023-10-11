#pragma once

class Stack{
	private:
		int* items;
		int topElement;
		int size;
	public:
		// Constructor
		Stack();

		// Copy Constructor
		Stack(const Stack &source);

		// Destructor
		~Stack();

		void push(int element);
		int pop();
		int top() const;
		bool isEmpty() const;
};

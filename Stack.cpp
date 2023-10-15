#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "Stack.h"

// ASK WHICH IS BETTER #define vs const int
// #define DOUBLE_TRESHOLD 4096
// #define SIZE_INCREMENT 128
// #define TOP_BASIC_VALUE -1

const int DOUBLE_TRESHOLD = 4096;
const int SIZE_INCREMENT = 128;
const int TOP_BASIC_VALUE = -1;

// Old Constructor
// Stack::Stack()
// {
// 	size = 0;
// 	items = NULL;
// 	topElement = TOP_BASIC_VALUE;
// }

// Better way as the top method first initializes into smth random - > changes into basic value, wheras the bottom method initializes right into the correct method.
Stack::Stack()
	: items{NULL}, topElement{TOP_BASIC_VALUE}, size{0} {}

// Copy Constructor
// Shalow copy - copy pointer vs deep copy - copy of the pointed data
Stack::Stack(const Stack &source)
	: items{NULL}, topElement{source.topElement}, size{source.size}
{
	int *newItems = NULL;
	newItems = (int *)realloc(items, size * sizeof(int));
	if (newItems == NULL)
	{
		printf("Memory allocation failed during push operation.\n");
		abort();
	}
	items = newItems;
	for (int i = 0; i < int(source.size); i++)
	{
		items[i] = source.items[i];
	}
}

// Destructor
Stack::~Stack()
{
	if (size > 0)
	{
		free(items);
		topElement = TOP_BASIC_VALUE;
		size = 0;
	}
}

Stack &Stack::operator=(const Stack &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	// deallocate the memory
	if (size > 0)
	{
		free(items);
	}
	items = NULL;

	// allocate the memory
	memAlloc(rhs.size);

	// copy the data
	for (int i = 0; i <= rhs.topElement; i++)
	{
		items[i] = rhs.items[i];
	}
	size = rhs.size;
	topElement = rhs.topElement;

	return *this;
}

void Stack::errorDelete()
{
	if (size > 0)
	{
		free(items);
		topElement = TOP_BASIC_VALUE;
		size = 0;
	}
}

void Stack::memAlloc(size_t sizeAlloc)
{
	int *newItems = NULL;
	newItems = (int *)realloc(items, sizeAlloc * sizeof(int));
	if (newItems == NULL)
	{
		printf("Memory allocation failed during push operation.\n");
		errorDelete();
		exit(EXIT_FAILURE);
	}
	items = newItems;
}

void Stack::printStack() const
{
	for (int i = 0; i <= topElement; i++)
	{
		printf("%d ", items[i]);
	}
}

void Stack::push(int element)
{
	topElement += 1;
	if (int(size) == topElement)
	{
		if (size == 0)
		{
			size += 1;
		}
		else if (size < DOUBLE_TRESHOLD)
		{
			size *= 2;
		}
		else
		{
			if (size += SIZE_INCREMENT < SIZE_MAX)
			{
				size += SIZE_INCREMENT;
			}
			else
			{
				if (size + 1 < SIZE_MAX)
				{
					size += 1;
				}
				else
				{
					printf("Unable to perform push operation as the size is too big.");
					errorDelete();
					exit(EXIT_FAILURE);
				}
			}
		}
		memAlloc(size);
	}
	items[topElement] = element;
}

int Stack::pop()
{
	if (topElement == TOP_BASIC_VALUE)
	{
		printf("The stack is empty, unable to perform operation.");
		errorDelete();
		exit(EXIT_FAILURE);
	}
	topElement -= 1;
	return items[topElement + 1];
}

int Stack::top()
{
	if (topElement == TOP_BASIC_VALUE)
	{
		printf("The stack is empty, unable to perform operation.");
		errorDelete();
		exit(EXIT_FAILURE);
	}
	return items[topElement];
}

bool Stack::isEmpty() const
{
	return (topElement == TOP_BASIC_VALUE);
}

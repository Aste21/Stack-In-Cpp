#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "Stack.h"

#define DOUBLE_TRESHOLD 4096
#define SIZE_INCREMENT 128
#define TOP_BASIC_VALUE -1

// Old Constructor
// Stack::Stack()
// {
// 	size = 0;
// 	items = NULL;
// 	topElement = TOP_BASIC_VALUE;
// }


// Better way as the top method first initializes into smth random - > changes into basic value, wheras the bottom method initializes right into the correct method.
Stack::Stack()
	: items{NULL}, topElement{TOP_BASIC_VALUE}, size{0}{}

// Copy Constructor
// Shalow copy - copy pointer vs deep copy - copy of the pointed data
Stack::Stack(const Stack &source)
	: items{NULL}, topElement{source.topElement}, size{source.size}\
{
		int* new_items = NULL;
		new_items = (int*) realloc(items, size * sizeof(int));
		if (new_items == NULL)
        {
            printf("Memory allocation failed during push operation.\n");
            abort();
        }
        items = new_items;
		for(int i = 0;i < source.size;i++)
		{
			items[i] = source.items[i];
		}
		
}

// Destructor
Stack::~Stack()
{
	if(size > 0)
	{
		free(items);
		topElement = TOP_BASIC_VALUE;
		size = 0;
	}
}

void Stack::push(int element)
{
	topElement += 1;
	if(size == topElement)
	{
		int* new_items = NULL;
		if(size == 0)
		{
			size += 1;
		}
		else if(size < DOUBLE_TRESHOLD)
		{
			size *= 2;
		}
		else
		{
			size += SIZE_INCREMENT;
		}
		new_items = (int*) realloc(items, size * sizeof(int));
        if (new_items == NULL)
        {
            printf("Memory allocation failed during push operation.\n");
            abort();
        }
        items = new_items;
    }
    items[topElement] = element;
}

int Stack::pop()
{
	if(topElement == TOP_BASIC_VALUE)
	{
		printf("The stack is empty, unable to perform operation.");
		abort();
	}
	topElement -= 1;
	return items[topElement + 1];
}

// the const reasures that i do not change any value of the class in this function - Is this good practice tho?
int Stack::top() const
{
	if(topElement == TOP_BASIC_VALUE)
	{
		printf("The stack is empty, unable to perform operation.");
		abort();
	}
	return items[topElement];
}

bool Stack::isEmpty() const
{
	return (topElement == TOP_BASIC_VALUE);
}
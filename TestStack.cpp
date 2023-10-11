#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "Stack.h"


int main(int argc, char *argv[])
{ 

	// STANDARD TEST
	Stack stack;
	int choice;
	int input;
	bool loopBool = true;
	while(loopBool)
	{
		printf("Press 1 to test push\nPress 2 to test pop\nPress 3 to test isEmpty");
		printf("\nPress 4 to test top\nPress 5 to turn off program\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nInput the number to be added to stack: ");
				scanf("%d", &input);
				printf("%d", input);
				stack.push(input);
				break;
			}
			case 2:
			{
				printf("\nPopped element: %d", stack.pop());
				break;
			}
			case 3:
			{
				printf("\nisEmpty result: %d", stack.isEmpty());
				break;
			}
			case 4:
			{
				printf("\nTop element: %d", stack.top());
				break;
			}
			case 5:
			{
				loopBool = false;
				break;
			}
			default:
			{
				printf("\nWrong element sorry.");
			}
		}
		printf("\n");
	}


	// TEST OF COPYING
	Stack stack1;

	stack1.push(5);
	stack1.push(7);
	std::cout<<stack1.top()<<std::endl;

	Stack stack2(stack1);

	std::cout<<stack2.pop()<<std::endl;
	std::cout<<stack2.pop()<<std::endl;

	return 0;
} 
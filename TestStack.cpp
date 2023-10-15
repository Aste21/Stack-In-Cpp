#include <stdlib.h>
#include <iostream>
#include "Stack.h"

int main(int argc, char *argv[])
{

	printf("Testing push:\n\n");
	Stack s1;
	s1.push(1);
	printf("s1.push(1), state of s1: \n");
	s1.printStack();
	s1.push(2);
	printf("\ns1.push(2), state of s1: \n");
	s1.printStack();
	s1.push(3);
	printf("\ns1.push(3), state of s1: \n");
	s1.printStack();

	Stack s2(s1);
	printf("\ns2(s1), state of s2: \n");
	s2.printStack();

	printf("\n\nCalling assignment operator when one of the stacks is empty: \n");
	Stack s3 = s1;
	printf("\ns3 = s1: state of s3: \n");
	s3.printStack();

	//assigning smaller stack to larger stack

	printf("\n\nAssigning larger stack to smaller stack: \n");
	Stack s4;
	s4.push(10);
	printf("\ns4.push(10), state of s4: \n");
	s4.printStack();
	s4 = s1;
	printf("\ns4 = s1, state of s4: \n");
	s4.printStack();

	printf("\n\nAssigning the stack to itself: \n");
	s4 = s4;
	printf("\ns4 = s4, state of s4: \n");
	s4.printStack();

	printf("\n\nCalling assignment operator when both stacks have equal size: \n");
	Stack s5;
	s5.push(5);
	s5.push(6);
	s5.push(7);
	printf("\nState of s5 before assignment: \n");
	s5.printStack();
	s5 = s1;
	printf("\ns5=s1, state of s5: \n");
	s5.printStack();

	printf("\n\nAssigning smaller stack to larger stack: \n");
	Stack s6;
	s6.push(5);
	printf("\nState of s5 before assignment: \n");
	s5.printStack();
	printf("\nState of s6 before assignment: \n");
	s6.printStack();
	s5 = s6;
	printf("\ns5=s6, state of s5: \n");
	s5.printStack();


	printf("\n\nTesting pop:\n\nPopped element from s1: %d, state of s1 after pop: \n", s1.pop());
	s1.printStack();

	printf("\n");
	return 0;
}

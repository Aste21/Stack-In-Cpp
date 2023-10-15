#include <stdlib.h>
#include <iostream>
#include "Stack.h"

int main(int argc, char *argv[])
{
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

	Stack s3 = s1;
	printf("\ns3 = s1: state of s3: \n");
	s3.printStack();

	Stack s4;
	s4.push(10);
	printf("\ns4.push(10), state of s4: \n");
	s4.printStack();
	s4 = s1;
	printf("\ns4 = s1, state of s4: \n");
	s4.printStack();
	s4 = s4;
	printf("\ns4 = s4, state of s4: \n");
	s4.printStack();

	printf("\nTesting pop:\nPopped element from s1: %d, state of s1 after pop: \n", s1.pop());
	s1.printStack();

	printf("\n");
	return 0;
}

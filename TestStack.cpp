#include <stdlib.h>
#include <iostream>
#include "Stack.h"

void testPush(Stack& s1);
void testAssignmentOperatorWithEmptyStack(const Stack& s1);
void testAssignmentOperatorWithDifferentStackSizes(const Stack& s1);
void testSelfAssignment(const Stack& s1);
void testAssignmentOperatorWithEqualStackSizes(const Stack& s1);
void testPop(Stack& s1);
void testFuctionByValue(const Stack s1);
void testFunctionByReference(const Stack& s1);
void testCopyConstructor(const Stack s1);


int main(int argc, char* argv[]) {
    Stack s1;
    testPush(s1);
    testCopyConstructor(s1);
    testAssignmentOperatorWithEmptyStack(s1);
    testAssignmentOperatorWithDifferentStackSizes(s1);
    testSelfAssignment(s1);
    testAssignmentOperatorWithEqualStackSizes(s1);
    testPop(s1);
    testFuctionByValue(s1);
    testFunctionByReference(s1);

    printf("\n");
    return 0;
}

void testPush(Stack& s1) {
    printf("Testing push:\n\n");
    s1.push(1);
    printf("s1.push(1), state of s1: \n");
    s1.printStack();
    s1.push(2);
    printf("\ns1.push(2), state of s1: \n");
    s1.printStack();
    s1.push(3);
    printf("\ns1.push(3), state of s1: \n");
    s1.printStack();
}

void testCopyConstructor(const Stack s1)
{
    printf("\n\nTest of copy constructor: \n\n");
    Stack s2(s1);
    printf("s2(s1):\n");
    printf("State of s1: ");
    s1.printStack();
    printf("\nState of s2: ");
    s2.printStack();
}

void testAssignmentOperatorWithEmptyStack(const Stack& s1) {
    printf("\n\nCalling assignment operator when one of the stacks is empty: \n");
    Stack s3 = s1;
    printf("\ns3 = s1: state of s3: \n");
    s3.printStack();
}

void testAssignmentOperatorWithDifferentStackSizes(const Stack& s1) {
    printf("\n\nAssigning larger stack to smaller stack: \n");
    Stack s4;
    s4.push(10);
    printf("\ns4.push(10), state of s4: \n");
    s4.printStack();
    s4 = s1;
    printf("\ns4 = s1, state of s4: \n");
    s4.printStack();
}

void testSelfAssignment(const Stack& s1) {
    printf("\n\nAssigning the stack to itself: \n");
    Stack s4 = s1;
    printf("\nState of s4 before assignment: \n");
    s4.printStack();
    s4 = s4;
    printf("\ns4 = s4, state of s4: \n");
    s4.printStack();
}

void testAssignmentOperatorWithEqualStackSizes(const Stack& s1) {
    printf("\n\nCalling assignment operator when both stacks have equal size: \n");
    Stack s5;
    s5.push(5);
    s5.push(6);
    s5.push(7);
    printf("\nState of s5 before assignment: \n");
    s5.printStack();
    s5 = s1;
    printf("\ns5 = s1, state of s5: \n");
    s5.printStack();
}

void testPop(Stack& s1) {
    printf("\n\nTesting pop:\n\n");
    printf("Popped element from s1: %d, state of s1 after pop: \n", s1.pop());
    s1.printStack();
}

void testFuctionByValue(const Stack s1)
{
    printf("\n\n");
    s1.printStack();
}

void testFunctionByReference(const Stack &s1)
{
    printf("\n\n");
    s1.printStack();
}


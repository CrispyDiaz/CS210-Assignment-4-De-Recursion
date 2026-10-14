Write and test a C++ program that revises a recursive implementation into an iterative one that utilizes a stack.

Be sure to follow all of these specifications for full credit.  

 

CS 210 - Assignment 4
(30 points)

Due: Upload .cpp source code file to Canvas by Wed. 10/14 @ 4:00 pm

Objectives:
Write and test a C++ program that utilizes an STL stack to implement recursion..

Practice concepts from Ch. 3.

Tasks:
Create a class with a custom name (detailed below) with a simple main() that is a non-recursive implementation of this recursive method:

int factorial( int x )
{
    if( x <= 1 )
        return 1;
    else
        return x * factorial( x - 1 );
}
Have your code:

Ask the user for a non-negative integer.  Be sure to efficiently check and enforce the range before proceeding.
Generate the factorial of the number by:
Creating an instance of std::stack with int as its parameterized type
Repeatedly push all of the values from 1 to your input value (inclusive) onto the stack
Repeatedly pop all of the values off the stack (be sure to call top first) until the stack signals it is empty, using those values to generate the factorial.
Output the following:
Your name, ID#, and "CS 210 - Assignment 4" on its own line.
The factorial with a descriptive caption

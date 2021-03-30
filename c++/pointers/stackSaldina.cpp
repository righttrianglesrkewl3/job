#include <iostream>
#include <string>
#include <vector>
#include <stack> // need to make stacks
using namespace std;

void printStackElements(stack<int> stack);

int main()
{
    // 5 functions/methods needed to implement stack
    // empty(), size(), push(), pop(), top()
    stack<int>numbersStack;
    // goes to top of stack (make sure type corret as declared when initialize stack)
    numbersStack.push(1);
    numbersStack.push(2); 
    numbersStack.push(3);

    // remove first element from top of stack 
    // numbersStack.pop(); 
    // numbersStack.pop(); 
    // numbersStack.pop(); 

    printStackElements(numbersStack);

    // if (numbersStack.empty())
    //     cout << "Stack is empty" << endl;
    // else
    //     cout << "Stack is not empty" << endl;
    // cout << "Stack size is: " 
    //     << numbersStack.size() << endl; 

}

void printStackElements(stack<int> stack) {
    // ask for top element, write to console, then remove from stack with pop() function while stack size > 0 (or stack size not empty)

    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }

}

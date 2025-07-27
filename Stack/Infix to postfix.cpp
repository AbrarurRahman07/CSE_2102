#include <iostream>
#include <cmath>
#include <cctype>  // for isdigit()
using namespace std;

// Linked list node for the stack
struct node
{
    int data;
    node* link;
} *stack1 = NULL;

// Push integer onto stack
void push(int val)
{
    node* ptr = new node;
    ptr->data = val;
    ptr->link = stack1;
    stack1 = ptr;
}

// Pop integer from stack (with underflow check)
int pop()
{
    if (stack1 == NULL)
    {
        cout << "Stack underflow!" << endl;
        exit(1); // Exit the program on underflow
    }
    node* ptr = stack1;
    int val = ptr->data;
    stack1 = stack1->link;
    delete ptr;
    return val;
}

int main()
{
    char str[] = "753*51^/+32-+";

    for (int i = 0; str[i] != '\0'; ++i)
    {
        char a = str[i];

        if (isdigit(a))
        {
            push(a - '0');  // Convert char to int and push
        }
        else
        {
            int b = pop();  // Right operand
            int a1 = pop(); // Left operand
            int res = 0;

            switch (a)
            {
            case '+':
                res = a1 + b;
                break;
            case '-':
                res = a1 - b;
                break;
            case '*':
                res = a1 * b;
                break;
            case '/':
                res = a1 / b;
                break;
            case '^':
                res = pow(a1, b);
                break;
            default:
                cout << "Invalid operator: " << a << endl;
                exit(1);
            }

            push(res);
        }
    }

    cout << "Final result: " << pop() << endl;

    return 0;
}

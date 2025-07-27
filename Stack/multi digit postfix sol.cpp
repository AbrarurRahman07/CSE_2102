#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

struct node
{
    int data;
    node* link;
} *stack1 = NULL;

void push(int val)
{
    node* ptr = new node;
    ptr->data = val;
    ptr->link = stack1;
    stack1 = ptr;
}

int pop()
{
    node* ptr = stack1;
    int val = ptr->data;
    stack1 = stack1->link;
    delete ptr;
    return val;
}

int main()
{
    string expr= "73 53 43 * 5 1^ / + 30 2 - +";
    /**cout << "Enter postfix expression (e.g., \"12 145 1234 + *\"): ";
    getline(cin, expr);*/

    istringstream num(expr);///  <sstream>

    string token;
    while (num >> token)///
    {


        if (isdigit(token[0]))
        {
            push(stoi(token));/// stoi to make the token into int value.
        }


        else
        {
            int b = pop();
            int a = pop();
            int res = 0;

            switch (token[0])
            {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = a / b;
                break;
            case '^':
                res = pow(a, b);
                break;
            default:
                cout << "Invalid operator: " << token << endl;
                exit(1);
            }

            push(res);
        }
    }

    cout << "Final result: " << pop() << endl;
    return 0;
}


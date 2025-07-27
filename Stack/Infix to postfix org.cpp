#include <iostream>
#include <cctype>   // for isalnum()
#include <string>
using namespace std;

// Node structure for linked list stack
struct Node
{
    char data;
    Node* next;
};

// Stack operations
Node* top = nullptr;

void push(char c)
{
    Node* temp = new Node;
    temp->data = c;
    temp->next = top;
    top = temp;
}

char pop()
{
    if (top == nullptr) return '\0';
    Node* temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

char peek()
{
    return (top != nullptr) ? top->data : '\0';
}

bool isEmpty()
{
    return top == nullptr;
}

// Precedence of operators
int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix (assuming left-associative operators)
string infixToPostfix(const string& infix)
{
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix += pop();
            }
            if (!isEmpty()) pop(); // Remove '('
        }
        else   // operator
        {
            while (!isEmpty() &&
                    precedence(ch) <= precedence(peek()) &&
                    peek() != '(')
            {
                postfix += pop();
            }
            push(ch);
        }
    }

    while (!isEmpty())
    {
        postfix += pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression (e.g. (A+B)*C ): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

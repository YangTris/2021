#include <iostream>
using namespace std;
struct Stack
{
    int top;
    int array[100];
};

void initS(Stack &s)
{
    s.top = -1;
}

void push(Stack &s, int x)
{
    s.top = s.top + 1;
    s.array[s.top] = x;
}

int pop(Stack &s)
{
    int temp;
    temp = s.array[s.top];
    s.top = s.top - 1;
    return temp;
}

bool isemptyS(Stack s)
{
    if (s.top == -1)
        return true;
    else
        return false;
}

int main()
{
    struct Stack s;
    initS(s);
    int n;
    cout << "input a number:";
    cin >> n;

    while (n != 0)
    {
        push(s, n % 2);
        n = n / 2;
    }

    while (!isemptyS(s))
    {
        printf("%d", pop(s));
    }

    return 0;
}
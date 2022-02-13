#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *createNode(int x)
{
    node *temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

void printList(node *head)
{
    node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

node *addElement(node *p, int x)
{
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}

node *addAt(node *l, int k, int x)
{
    node *p = l;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    node *temp = new node;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;

    return l;
}

int main()
{
    int n, x;
    cout << "Input n: ";
    cin >> n;
    cout << "First node: ";
    cin >> x;
    node *head = createNode(x);
    node *cur = head;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        cur = addElement(cur, x);
    }

    printList(head);
    return 0;
}
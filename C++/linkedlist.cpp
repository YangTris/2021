#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void initNode(struct Node *head, int n)
{
    head->data = n;
    head->next = NULL;
}

void addNode(struct Node *head, int n)
{
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    Node *cur = head;
    while (cur)
    {
        if (cur->next == NULL)
        {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}

void insertFront(struct Node **head, int n)
{
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = *head;
    *head = newNode;
}

bool searchNode(struct Node *head, int n)
{
    Node *cur = head;
    while (cur)
    {
        if (cur->data == n)
            return true;
        cur = cur->next;
    }
    return false;
}

void deleteNode(struct Node **head, int n)
{
    Node *cur = *head;
    Node *prev = NULL;
    if (cur->data == n) //first node
    {
        *head = cur->next;
        delete cur;
        return;
    }
    else
        while (cur != NULL && cur->data != n)
        {
            prev = cur;
            cur = cur->next;
        }

    if (cur == NULL)
        return;
    prev->next = cur->next;
    delete cur;
}

void deleteList(struct Node **head)
{
    Node *cur = *head;
    while (cur)
    {
        cur = cur->next;
        delete *head;
        *head = cur;
    }
}
void reverseList(struct Node **head)
{
    Node *cur = *head;
    Node *prev = NULL, *next = NULL;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

bool compareList(struct Node *head, struct Node *newHead)
{
    while (head && newHead)
    {
        if (head->data != newHead->data)
            return false;
        head = head->next;
        newHead = newHead->next;
    }
    if (head == NULL && newHead == NULL)
        return true;
    else
        return false;
}

void copyList(struct Node *head, Node *&newHead)
{
    initNode(newHead, head->data);
    Node *cur = head->next;
    while (cur)
    {
        int x = cur->data;
        addNode(newHead, x);
        cur = cur->next;
    }
}

void printList(struct Node *head)
{
    Node *cur = head;
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

int main()
{
    Node *head = new Node;
    initNode(head, 1);
    addNode(head, 3);
    addNode(head, 2);
    addNode(head, 5);
    addNode(head, 4);
    deleteNode(&head, 5);
    reverseList(&head);
    printList(head);
    Node *newHead = new Node;
    copyList(head, newHead);
    cout << endl;
    reverseList(&newHead);
    cout << "new Head= ";
    printList(newHead);
    cout << "compare= ";
    cout << compareList(head, newHead);
    deleteList(&head);
    return 0;
}
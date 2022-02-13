#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void addTail(struct Node **head, int n)
{
    Node *cur = *head;
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    if (*head == NULL) //empty list
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (cur->next) //traverse to the last node
        cur = cur->next;

    cur->next = newNode;
    newNode->prev = cur;
}
void insertFront(struct Node **head, int n)
{
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) //if not empty
        (*head)->prev = newNode;
    *head = newNode;
}
struct Node *searchNode(struct Node *head, int n)
{
    Node *cur = head;
    while (cur)
    {
        if (cur->data == n)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void deleteNode(struct Node **head, int n)
{
    Node *cur = *head;
    Node *temp1 = NULL; //store prev
    Node *temp2 = NULL; //store next

    if (cur->data == n) //first node
    {
        *head = cur->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        delete cur;
        return;
    }

    while (cur != NULL && cur->data != n)
    {
        temp1 = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        return;

    if (cur->next == NULL) //last node
    {
        temp1->next = NULL;
        delete cur;
        return;
    }

    temp2 = cur->next;
    temp1->next = temp2;
    temp2->prev = temp1;
    delete cur;
}
void Reverse(struct Node **head)
{
    Node *cur = *head;
    Node *temp = NULL;
    while (cur)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    if (temp != NULL) //if not empty or not 1 node in list
        *head = temp->prev;
}
struct Node *Copy(struct Node *head)
{
    Node *cur = head;
    Node *newL = NULL; //head new list
    while (cur)
    {
        addTail(&newL, cur->data);
        cur = cur->next;
    }

    return newL;
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
bool Compare(struct Node *list1, struct Node *list2)
{
    while (list1 && list2)
    {
        if (list1->data != list2->data)
            return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 == NULL && list2 == NULL)
        return true;
    else
        return false;
}

void Print(struct Node *head)
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
    Node *list1 = NULL, *list2 = NULL;
    addTail(&list1, 5);
    addTail(&list1, 4);
    addTail(&list1, 4);
    addTail(&list1, 21);
    addTail(&list1, 1);
    insertFront(&list1, 9);
    deleteNode(&list1, 21);
    if (list1 == NULL)
        cout << "null\n";
    Reverse(&list1);
    Print(list1);

    // list2 = Copy(list1);
    // if(Compare(list1,list2)){
    //     cout<<"\nlist 1 = list 2";
    // }
    return 0;
}
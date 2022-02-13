#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void addTail(struct Node **head, int n)
{
    Node *cur = *head;
    Node *newNode = new Node;
    newNode->data = n;
    if (*head == NULL) // empty list
    {
        *head = newNode;
        (*head)->next = *head;
        return;
    }

    while (cur->next != *head)
        cur = cur->next;

    cur->next = newNode;
    newNode->next = *head;
}
void insertFront(struct Node **head, int n)
{
    Node *cur = *head;
    Node *newNode = new Node;
    newNode->data = n;
    if (*head == NULL) // empty list
    {
        *head = newNode;
        (*head)->next = *head;
        return;
    }

    while (cur->next != *head)
    {
        cur = cur->next;
    }
    newNode->next = *head;
    cur->next = newNode;
    *head = newNode;
}
struct Node *searchNode(struct Node *head, int n)
{
    Node *cur = head;
    do
    {
        if (cur->data == n)
            return cur;
        cur = cur->next;
    } while (cur != head);
    return NULL;
}
void deleteNode(struct Node **head, int n)
{
    if (*head == NULL)
        return;
    Node *cur = *head;
    Node *prev = NULL;
    if (cur->data == n) // first node
    {
        if (cur->next == *head) //if 1 node in list
        {
            *head = NULL;
            delete cur;
            return;
        }
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        *head = cur->next;
        prev->next = *head;
        delete cur;
        return;
    }
    while (cur->data != n)
    {
        if (cur->next == *head) // n is not found in list
            return;
        prev = cur;
        cur = cur->next;
    }

    if (cur->next == *head) //last node
    {
        prev->next = *head;
        delete cur;
    }
    else
    {
        prev->next = cur->next;
        delete cur;
    }
}
void Reverse(struct Node **head)
{
    Node *cur = *head;
    Node *prev = NULL, *next = NULL;

    do
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    } while (cur != *head);
    cur->next = prev;
    *head = prev;
}
struct Node *Copy(struct Node *head)
{
    Node *cur = head;
    Node *newL = NULL; // head new list

    do
    {
        addTail(&newL, cur->data);
        cur = cur->next;
    } while (cur != head);
    return newL;
}
void deleteList(struct Node **head)
{
    Node *cur = *head;
    Node *temp = NULL;
    do
    {
        temp = cur->next;
        delete cur;
        cur = temp;
    } while (cur != *head);
    *head = NULL;
}
bool Compare(struct Node *list1, struct Node *list2)
{
    Node *cur1 = list1;
    Node *cur2 = list2;
    do
    {
        if (cur1->data != cur2->data)
            return false;
        cur1 = cur1->next;
        cur2 = cur2->next;
    } while (cur1 != list1 && cur2 != list2);
    if (cur1 == list1 && cur2 == list2)
        return true;
    else
        return false;
}

void Print(struct Node *head)
{
    Node *cur = head;
    if (head != NULL)
    {
        do
        {
            cout << cur->data << " ";
            cur = cur->next;
        } while (cur != head);
    }
}

int main()
{
    Node *list1 = NULL;
    addTail(&list1, 4);
    addTail(&list1, 4);
    addTail(&list1, 21);
    addTail(&list1, 1);
    insertFront(&list1, 9);
    deleteNode(&list1, 21);
    // Reverse(&list1);
    // deleteList(&list1);
    Print(list1);
    Node *list2 = NULL;
    list2 = Copy(list1);
    cout << '\n'
         << "list 2: ";
    Print(list2);
    Node *search = searchNode(list1, 9);
    cout << '\n';
    if (search != NULL)
        cout << "Co node can tim trong list\n";
    else
        cout << "Khong co node can tim trong list\n";
    return 0;
}
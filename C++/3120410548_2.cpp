#include <iostream>
using namespace std;
struct Node //tạo cấu trúc của Node
{
    int data;
    Node *next;
};

void initNode(struct Node *head, int n) //khởi tạo Node
{
    head->data = n;
    head->next = NULL;
}

void addNode(struct Node *head, int n) //thêm một Node ở cuối
{
    Node *newNode = new Node; //khai báo Node newNode
    newNode->data = n;        //gán giá trị newNode bằng giá trị truyền vào
    newNode->next = NULL;     //con trỏ next trỏ đến NULL
    Node *cur = head;         //khai báo con trỏ cur để giữ node hiện tại
    while (cur)               //chưa hết danh sách
    {
        if (cur->next == NULL) //node cuối
        {
            cur->next = newNode; //gán node newNode vào cur
            return;
        }
        cur = cur->next; //trỏ đến node tiếp theo cho đến khi gặp node cuối
    }
}

void insertFront(struct Node **head, int n) //thêm một Node ở đầu
{
    Node *newNode = new Node; //khai báo Node newNode
    newNode->data = n;        //gán giá trị newNode bằng giá trị truyền vào
    newNode->next = *head;    //newNode trỏ đến con trỏ head
    *head = newNode;          //thay đổi con trỏ head bằng newNode
}

bool searchNode(struct Node *head, int n) //tìm kiếm một Node
{
    Node *cur = head; //khai báo con trỏ cur để giữ node hiện tại
    while (cur)       //chưa hết danh sách
    {
        if (cur->data == n) //tìm thấy giá trị n trả về true
            return true;
        cur = cur->next; //trỏ đến node tiếp theo cho đến khi hoặc tới cur == NULL
    }
    return false; //không tìm thấy giá trị n
}

void deleteNode(struct Node **head, int n) //xóa một Node
{
    Node *cur = *head;  //khai báo con trỏ cur để giữ node hiện tại
    Node *prev = NULL;  //khai báo con trỏ prev để giữ nodetrước cur
    if (cur->data == n) //xóa ở node đầu
    {
        *head = cur->next;
        delete cur;
        return;
    }
    else                                      //xóa ở node bất kì
        while (cur != NULL && cur->data != n) //chưa tìm được node cần xóa
        {
            prev = cur;
            cur = cur->next;
        }

    if (cur == NULL)        //không tìm thấy node cần xóa
        return;             //kết thúc chương trình
    prev->next = cur->next; //tìm thấy node cần xóa ta gán cho nút trước trỏ đến node tiếp theo bằng nút hiện tại trỏ đến node tiếp theo bỏ qua node cur
    delete cur;             //xóa cur
}

void deleteList(struct Node **head) //xóa toàn bộ danh sách
{
    Node *cur = *head; //khai báo con trỏ cur để giữ node hiện tại
    while (cur)        //xóa từng nút
    {
        cur = cur->next;
        delete *head;
        *head = cur;
    }
}

void reverseList(struct Node **head) //đảo ngược danh sách liên kết
{
    Node *cur = *head;               //khai báo con trỏ cur để giữ node hiện tại
    Node *prev = NULL, *next = NULL; //con trỏ prev để giữ node trước cur và con trỏ next giữ node sau cur

    while (cur) //chưa hết danh sách
    {
        next = cur->next; //con trỏ tiếp theo bằng node cur tiếp theo
        cur->next = prev; //cur trỏ next bằng con trỏ trước
        prev = cur;       //con trỏ trước bằng con trỏ cur
        cur = next;       // con trỏ cur bằng con trỏ next
    }
    *head = prev;
}

bool compareList(struct Node *head, struct Node *newHead) //so sánh danh sách
{
    while (head && newHead) //Cả 2 danh sách còn phần tử
    {
        if (head->data != newHead->data) //giá trị danh sách khác nhau => false
            return false;
        head = head->next; // trỏ đến node tiếp theo
        newHead = newHead->next;
    }
    if (head == NULL && newHead == NULL) //cả 2 danh sách hết phần tử
        return true;
    else //1 trong 2 danh sách còn phần tử  => false
        return false;
}

void copyList(struct Node *head, Node *&newHead) //sao chép danh sách
{
    initNode(newHead, head->data); //khởi tạo danh sách mới để sao chép danh sách cũ
    Node *cur = head->next;        //khai báo con trỏ cur để giữ node hiện tại
    while (cur)                    //chưa hết danh sách
    {
        int x = cur->data;   //gán giá trị x bằng giá trị của node hiện tại
        addNode(newHead, x); //thêm cuối với giá trị truyền vào là x
        cur = cur->next;     //trỏ đến node tiếp theo
    }
}

void printList(struct Node *head) //In danh sách
{
    Node *cur = head; //khai báo con trỏ cur để giữ node hiện tại
    while (cur)       // chưa hết danh sách
    {
        cout << cur->data << " "; //in giá trị của node
        cur = cur->next;          //trỏ đến node tiếp theo
    }
}
int main()
{
    Node *head = new Node; //khai báo Node con trỏ head
    initNode(head, 1);     //khởi tạo danh sách liên kết đơn head và truyền vào giá trị 1
    addNode(head, 3);      //thêm cuối danh sách liên kết head
    addNode(head, 2);
    addNode(head, 5);
    addNode(head, 4);
    insertFront(&head, 7); //thêm đầu danh sách liên kết head
    cout << "Danh sach lien ket: ";
    printList(head); //in danh sách head
    cout << endl;
    deleteNode(&head, 5); //xóa node trong head
    reverseList(&head);   //đảo ngược danh sách liên kết head
    cout << "Sau khi xoa va dao nguoc danh sach lien ket:" << endl;
    printList(head);          //in danh sách
    Node *newHead = new Node; //khai báo Node newHead
    copyList(head, newHead);  //sao chép danh sách head sang danh sách newHead
    cout << endl;
    cout << "Danh sach moi= ";
    printList(newHead); //in danh sách newHead
    cout << endl;
    if (compareList(head, newHead)) //so sánh 2 danh sách
        cout << "Danh sach lien ket giong nhau";
    else
        cout << "Danh sach lien ket khong giong nhau";
    deleteList(&head); //xóa danh sách head
    return 0;
}
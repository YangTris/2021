#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int n) //tạo nút lá có giá trị bằng giá trị truyền vào
{
    struct Node *newnode = new Node;
    newnode->data = n;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node *insertNode(Node *root, int value) //chèn một node vào cây
{
    if (root == NULL) //nếu cây rỗng thì truyền giá trị vào
        return createNode(value);
    else
    {
        if (root->data < value)                           //giá trị nút hiện tại bé hơn giá trị truyền vào
            root->right = insertNode(root->right, value); //cây sang phải
        else
            root->left = insertNode(root->left, value); //cây sang trái
        return root;
    }
}

void scanLNR(Node *root) //duyệt cây từ trái qua phải (bé đến lớn)
{
    if (root != NULL) //nếu cây không rỗng
    {
        scanLNR(root->left);       //cây sang trái
        cout << root->data << " "; //in giá trị
        scanLNR(root->right);      //cây sang phải
    }
}

bool searchNode(struct Node *root, int value) //tìm kiếm một node
{
    if (root == NULL) //không tìm thấy node trả về false
        return false;
    if (root->data == value) //tìm thấy node trả về true
        return true;
    if (value < root->data)                   //giá trị truyền vào nhỏ hơn giá trị nút hiện tại
        return searchNode(root->left, value); //cây sang trái
    return searchNode(root->right, value);    //cây sang phải
}

Node *findMin(Node *root) //tìm nút nhỏ nhất trong cây
{
    Node *cur = root;
    while (cur != NULL && cur->left != NULL) //tìm cực trái của cây
        cur = cur->left;
    return cur;
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL) //cây rỗng
        return root;
    if (value < root->data)                           //giá trị truyền vào bé hơn giá trị hiện tại
        root->left = deleteNode(root->left, value);   //cây sang trái
    else if (value > root->data)                      //giá trị truyền vào lớn hơn giá trị hiện tại
        root->right = deleteNode(root->right, value); //cây sang phải
    else
    {
        //xóa nút nhánh có 1 con hoặc nút lá
        if (root->left == NULL)
        {
            Node *temp = root->right; //tìm nút thay thế là giá trị của cây sang phải
            delete root;              //xóa phần tử của cây
            return temp;              //trả về nút thay thế
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //Xóa nút có nhánh có 2 con
        Node *temp = findMin(root->right);                 //tìm nút thay thế là cực trái bên cây phải
        root->data = temp->data;                           //gán giá trị nút gốc = giá trị cực trái bên phải
        root->right = deleteNode(root->right, temp->data); //gọi hàm đệ quy
    }
    return root; //trả về giá trị nút gốc
}

void deleteTree(Node *root) //Xóa cây
{
    if (root == NULL) //cây rỗng
        return;
    deleteTree(root->left);  //xóa cây trái
    deleteTree(root->right); //xóa cây phải
    delete root;
}

void scanNLR(Node *root) //duyệt cây từ trái qua phải (bé đến lớn)
{
    if (root != NULL) //nếu cây không rỗng
    {
        cout << root->data << " "; //in giá trị
        scanNLR(root->left);       //cây sang trái
        scanNLR(root->right);      //cây sang phải
    }
}

void scanNRL(Node *root) //duyệt cây từ trái qua phải (bé đến lớn)
{
    if (root != NULL) //nếu cây không rỗng
    {
        cout << root->data << " "; //in giá trị
        scanNRL(root->right);      //cây sang phải
        scanNRL(root->left);       //cây sang trái
    }
}

int main()
{
    Node *t = NULL;        //khai báo Node con trỏ t
    t = insertNode(t, 15); //chèn node vào cây
    t = insertNode(t, 1);
    t = insertNode(t, 2);
    t = insertNode(t, 71);
    t = insertNode(t, 3);
    t = insertNode(t, 4);
    t = insertNode(t, 23);

    // t = insertNode(t, 10);
    // t = insertNode(t, 20);
    // t = insertNode(t, 30);
    // t = insertNode(t, 40);
    // t = insertNode(t, 50);
    // t = insertNode(t, 25);
    deleteNode(t, 15); //xóa node trong cây
    scanLNR(t);        //in danh sách từ trái sang phải
    cout<<endl<<"NLR= ";
    scanNLR(t);
    cout<<endl<<"RNL= ";
    scanNRL(t);
    cout << endl;
    int n;
    cout << "Nhap node muon tim: ";
    cin >> n;
    if (searchNode(t, n)) //tìm node n trong cây t
        cout << "Node " << n << " co trong cay";
    else
        cout << "Node " << n << " khong co trong cay";
    return 0;
}
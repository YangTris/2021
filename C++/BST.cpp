#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *createNode(int n)
{
    struct Node *newnode = new Node;
    newnode->data = n;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
Node *insertNode(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    else
    {
        if (root->data < value)
            root->right = insertNode(root->right, value);
        else
            root->left = insertNode(root->left, value);
        return root;
    }
}
void scanLNR(Node *root)
{
    if (root != NULL)
    {
        scanLNR(root->left);
        cout << root->data << " ";
        scanLNR(root->right);
    }
}

bool searchNode(struct Node *root, int value) //tìm kiếm một node
{
    if (root == NULL) //không tìm thấy node trả về false
        return false;
    if (root->data == value) //tìm thấy node trả về true
        return true;
    if (value < root->data)                   //giá trị truyền vào nhỏ hơn giá trị nút hiện tại
        return searchNode(root->left, value); //sang trái
    return searchNode(root->right, value);    //sang phải
}

Node *findMin(Node *root)
{
    Node *cur = root;
    while (cur != NULL && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        //xóa nút nhánh có 1 con hoặc nút lá
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //Xóa nút có nhánh có 2 con
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void deleteTree(Node *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    Node *t = NULL;
    // int n;
    // cin >> n;
    // t = createNode(n);
    //    cout << t->data;
    t = insertNode(t, 15);
    t = insertNode(t, 4);
    t = insertNode(t, 5);
    t = insertNode(t, 71);
    t = insertNode(t, 6);
    t = insertNode(t, 7);
    t = insertNode(t, 23);

    deleteNode(t, 15);

    scanLNR(t);
    cout << "Search=" << searchNode(t, 7);
    return 0;
}
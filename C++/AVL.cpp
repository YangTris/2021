#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

// tao ra nut la co du lieu la data
Node *createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// lay chieu cao cua cay
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *rightRotate(Node *root)
{
    Node *t = root->left;
    root->left = t->right;
    t->right = root;

    // Update heights
    root->height = max(height(root->left), height(root->right)) + 1;
    t->height = max(height(t->left), height(t->right)) + 1;

    // Return new root
    return t;
}

Node *leftRotate(Node *root)
{
    Node *t = root->right;
    root->right = t->left;
    t->left = root;

    // Update heights
    root->height = max(height(root->left), height(root->right)) + 1;
    t->height = max(height(t->left), height(t->right)) + 1;

    // Return new root
    return t;
}

int getBalance(Node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

// Recursive function to insert a data
// in the subtree rooted with node and
// returns the new root of the subtree.
Node *insert(Node *root, int data)
{
    /* 1. Perform the normal BST insertion */
    if (root == NULL)
        return (createNode(data));

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else // Equal keys are not allowed in BST
        return root;

    /* 2. Update height of this ancestor node */
    root->height = 1 + max(height(root->left),
                           height(root->right));

    /* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
    int balance = getBalance(root);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    /* return the (unchanged) node pointer */
    return root;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
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

    t = insert(t, 10);
    t = insert(t, 20);
    t = insert(t, 30);
    t = insert(t, 40);
    t = insert(t, 50);
    t = insert(t, 25);

    /* The constructed AVL Tree would be
			30
			/ \
			20 40
			/ \ \
		   10 25 50
	*/
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(t);

    return 0;
}

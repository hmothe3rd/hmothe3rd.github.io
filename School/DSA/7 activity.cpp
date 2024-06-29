#include <iostream>
using namespace std;

class IntBinaryTree
{
public:
    struct TreeNode
    {
        int value;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;

    IntBinaryTree() 
    {
        root = NULL;
    }

    ~IntBinaryTree() 
    {
        destroyTree(root);
    }

    void insertNode(int num);
    bool searchNode(int num);
    void remove(int num);
    void showNodesInOrder() const
    {
        displayInOrder(root);
    }
    void showNodesPreOrder() const
    {
        displayPreOrder(root);
    }
    void showNodesPostOrder() const
    {
        displayPostOrder(root);
    }

private:
    void deleteNode(int num, TreeNode*& nodePtr);
    void makeDeletion(TreeNode*& nodePtr);
    void displayInOrder(TreeNode* nodePtr) const;
    void displayPreOrder(TreeNode* nodePtr) const;
    void displayPostOrder(TreeNode* nodePtr) const;
    void destroyTree(TreeNode* nodePtr);
};

void IntBinaryTree::insertNode(int num)
{
    TreeNode* newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = NULL;

    if (!root) 
    {
        root = newNode;
    }
    else
    {
        TreeNode* nodePtr = root;
        while (true)
        {
            if (num < nodePtr->value)
            {
                if (nodePtr->left)
                {
                    nodePtr = nodePtr->left;
                }
                else
                {
                    nodePtr->left = newNode;
                    break;
                }
            }
            else if (num > nodePtr->value)
            {
                if (nodePtr->right)
                {
                    nodePtr = nodePtr->right;
                }
                else
                {
                    nodePtr->right = newNode;
                    break;
                }
            }
            else
            {
                cout << "Duplicate value found in tree.\n";
                delete newNode; 
                break;
            }
        }
    }
}

void IntBinaryTree::displayInOrder(TreeNode* nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPreOrder(TreeNode* nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPostOrder(TreeNode* nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

void IntBinaryTree::makeDeletion(TreeNode*& nodePtr)
{
    TreeNode* tempNodePtr;
    if (nodePtr == NULL)
    {
        cout << "Cannot delete empty node.\n";
    }
    else if (nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if (nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    else
    {
        tempNodePtr = nodePtr->right;
        while (tempNodePtr->left)
        {
            tempNodePtr = tempNodePtr->left;
        }
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

void IntBinaryTree::remove(int num)
{
    deleteNode(num, root);
}

void IntBinaryTree::deleteNode(int num, TreeNode*& nodePtr)
{
    if (nodePtr == NULL)
    {
        cout << "Value not found in the tree.\n";
        return;
    }

    if (num < nodePtr->value)
    {
        deleteNode(num, nodePtr->left);
    }
    else if (num > nodePtr->value)
    {
        deleteNode(num, nodePtr->right);
    }
    else
    {
        makeDeletion(nodePtr);
    }
}

bool IntBinaryTree::searchNode(int num)
{
    TreeNode* nodePtr = root;
    while (nodePtr)
    {
        if (nodePtr->value == num)
        {
            return true;
        }
        else if (num < nodePtr->value)
        {
            nodePtr = nodePtr->left;
        }
        else
        {
            nodePtr = nodePtr->right;
        }
    }
    return false;
}

void IntBinaryTree::destroyTree(TreeNode* nodePtr)
{
    if (nodePtr)
    {
        destroyTree(nodePtr->left);
        destroyTree(nodePtr->right);
        delete nodePtr;
    }
}

int main()
{
    IntBinaryTree tree;
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Search for a node\n";
        cout << "3. Remove a node\n";
        cout << "4. Display in-order traversal\n";
        cout << "5. Display pre-order traversal\n";
        cout << "6. Display post-order traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insertNode(value);
            break;
        case 2:
            cout << "Enter value to search for: ";
            cin >> value;
            if (tree.searchNode(value))
                cout << "Value found in the tree.\n";
            else
                cout << "Value not found in the tree.\n";
            break;
        case 3:
            cout << "Enter value to remove: ";
            cin >> value;
            tree.remove(value);
            break;
        case 4:
            cout << "In-order traversal:\n";
            tree.showNodesInOrder();
            break;
        case 5:
            cout << "Pre-order traversal:\n";
            tree.showNodesPreOrder();
            break;
        case 6:
            cout << "Post-order traversal:\n";
            tree.showNodesPostOrder();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

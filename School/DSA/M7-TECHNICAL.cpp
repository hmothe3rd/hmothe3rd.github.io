#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
private:
    Node* root;

    void insertNode(Node*& node, int key) {
        if (node == NULL) {
            node = new Node(key);
            return;
        }
        if (key < node->key) {
            insertNode(node->left, key);
        } else if (key > node->key) {
            insertNode(node->right, key);
        }
    }

    Node* searchNode(Node* node, int key) {
        if (node == NULL || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return searchNode(node->left, key);
        } else {
            return searchNode(node->right, key);
        }
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node*& node, int key) {
        if (node == NULL) {
            return node;
        }
        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
        return node;
    }

    void inorderTraversal(Node* node) {
        if (node == NULL) return;
        inorderTraversal(node->left);
        cout << node->key << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == NULL) return;
        cout << node->key << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == NULL) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->key << " ";
    }

    void displayBST(Node* node, int space) {
        if (node == NULL) {
            return;
        }
        space += 5;
        displayBST(node->right, space);
        cout << endl;
        for (int i = 5; i < space; i++) {
            cout << " ";
        }
        cout << node->key << "\n";
        displayBST(node->left, space);
    }

public:
    BST() {
        this->root = NULL;
    }

    void insert(int key) {
        insertNode(this->root, key);
    }

    Node* search(int key) {
        return searchNode(this->root, key);
    }

    void remove(int key) {
        deleteNode(this->root, key);
    }

    void inorder() {
        inorderTraversal(this->root);
        cout << endl;
    }

    void preorder() {
        preorderTraversal(this->root);
        cout << endl;
    }

    void postorder() {
        postorderTraversal(this->root);
        cout << endl;
    }

    void display() {
        displayBST(this->root, 0);
    }
};

int main() {
    BST bst;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Search for a node\n";
        cout << "3. Remove a node\n";
        cout << "4. Display in-order traversal\n";
        cout << "5. Display pre-order traversal\n";
        cout << "6. Display post-order traversal\n";
        cout << "7. Display BST\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Enter value to search for: ";
                cin >> value;
                if (bst.search(value))
                    cout << "Node found in the BST: " << value << endl;
                else
                    cout << "Node not found in the BST\n";
                break;
            case 3:
                cout << "Enter value to remove: ";
                cin >> value;
                bst.remove(value);
                break;
            case 4:
                cout << "In-order traversal: ";
                bst.inorder();
                break;
            case 5:
                cout << "Pre-order traversal: ";
                bst.preorder();
                break;
            case 6:
                cout << "Post-order traversal: ";
                bst.postorder();
                break;
            case 7:
                cout << "Displaying BST:\n";
                bst.display();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
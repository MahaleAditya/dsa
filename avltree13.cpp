#include <iostream>
#include <string>

using namespace std;

// Node structure for AVL tree
struct Node {
    string keyword; // Keyword for dictionary
    string meaning; // Meaning of the keyword
    Node* left; // Pointer to left child
    Node* right; // Pointer to right child
    int height; // Height of the node

    // Constructor to initialize node with keyword and meaning
    Node(string key, string mean) : keyword(key), meaning(mean), left(nullptr), right(nullptr), height(1) {}
};

// AVL tree class
class AVLTree {
private:
    Node* root; // Pointer to root of AVL tree

    // Function to calculate height of a node
    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Function to calculate balance factor of a node
    int balanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    // Function to perform right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Function to perform left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Function to insert a node into AVL tree
    Node* insertNode(Node* node, string key, string mean) {
        // If tree is empty, create new node
        if (node == nullptr)
            return new Node(key, mean);

        // Insert node recursively based on key value
        if (key < node->keyword)
            node->left = insertNode(node->left, key, mean);
        else if (key > node->keyword)
            node->right = insertNode(node->right, key, mean);
        else
            node->meaning = mean; // Update meaning for existing keyword

        // Update height of current node
        node->height = 1 + max(height(node->left), height(node->right));

        // Get balance factor of current node
        int balance = balanceFactor(node);

        // Perform rotations if necessary to balance the tree
        if (balance > 1 && key < node->left->keyword)
            return rightRotate(node);

        if (balance < -1 && key > node->right->keyword)
            return leftRotate(node);

        if (balance > 1 && key > node->left->keyword) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->keyword) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Function to find node with minimum value in a subtree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Function to delete a node from AVL tree
    Node* deleteNode(Node* root, string key) {
        if (root == nullptr)
            return root;

        // Perform standard BST delete operation
        if (key < root->keyword)
            root->left = deleteNode(root->left, key);
        else if (key > root->keyword)
            root->right = deleteNode(root->right, key);
        else {
            // Node with only one child or no child
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                // Node with two children, get successor
                Node* temp = minValueNode(root->right);
                root->keyword = temp->keyword;
                root->right = deleteNode(root->right, temp->keyword);
            }
        }

        // If the tree had only one node then return
        if (root == nullptr)
            return root;

        // Update height of current node
        root->height = 1 + max(height(root->left), height(root->right));

        // Get balance factor of current node
        int balance = balanceFactor(root);

        // Perform rotations if necessary to balance the tree
        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Function to display AVL tree in inorder traversal
    void displayInOrder(Node* node) {
        if (node != nullptr) {
            displayInOrder(node->left);
            cout << node->keyword << ": " << node->meaning << endl;
            displayInOrder(node->right);
        }
    }

    // Function to display AVL tree in reverse inorder traversal
    void displayReverseInOrder(Node* node) {
        if (node != nullptr) {
            displayReverseInOrder(node->right);
            cout << node->keyword << ": " << node->meaning << endl;
            displayReverseInOrder(node->left);
        }
    }

    // Helper function for searching a keyword
    int searchHelper(Node* node, string key, int& comparisons) {
        if (node == nullptr)
            return -1;

        comparisons++;
        if (node->keyword == key)
            return comparisons;

        if (key < node->keyword)
            return searchHelper(node->left, key, comparisons);
        else
            return searchHelper(node->right, key, comparisons);
    }

public:
    AVLTree() : root(nullptr) {}

    // Function to insert a keyword-meaning pair into AVL tree
    void Insert(string key, string mean) {
        root = insertNode(root, key, mean);
    }

    // Function to delete a keyword from AVL tree
    void Delete(string key) {
        root = deleteNode(root, key);
    }

    // Function to display AVL tree in ascending order of keywords
    void DisplayAscending() {
        cout << "Dictionary Contents (Ascending Order):\n";
        displayInOrder(root);
    }

    // Function to display AVL tree in descending order of keywords
    void DisplayDescending() {
        cout << "Dictionary Contents (Descending Order):\n";
        displayReverseInOrder(root);
    }

    // Function to search for a keyword in AVL tree and return the maximum comparisons required
    int Search(string key) {
        int comparisons = 0;
        int result = searchHelper(root, key, comparisons);
        cout << "Maximum comparisons required for finding keyword \"" << key << "\": " << comparisons << endl;
        return result;
    }
};

// Main function
int main() {
    AVLTree dictionary;
    int choice;
    string key, mean;
    int comparisons; // Move the declaration outside the switch block

    // Menu-driven loop for interacting with the AVL tree
    do {
        cout << "\nMenu:\n";
        cout << "1. Add New Keyword\n";
        cout << "2. Search Keyword\n";
        cout << "3. Update Meaning of Keyword\n";
        cout << "4. Display (Ascending Order)\n";
        cout << "5. Display (Descending Order)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> key;
                cout << "Enter meaning: ";
                cin.ignore(); // Clear buffer
                getline(cin, mean);
                dictionary.Insert(key, mean);
                cout << "Keyword \"" << key << "\" inserted.\n";
                break;
            case 2:
                cout << "Enter keyword to search: ";
                cin >> key;
                comparisons = dictionary.Search(key); // Assign here
                if (comparisons != -1)
                    cout << "Keyword \"" << key << "\" found after " << comparisons << " comparisons.\n";
                else
                    cout << "Keyword \"" << key << "\" not found.\n";
                break;
            case 3:
                cout << "Enter keyword to update: ";
                cin >> key;
                cout << "Enter new meaning: ";
                cin.ignore(); // Clear buffer
                getline(cin, mean);
                dictionary.Insert(key, mean);
                cout << "Meaning of keyword \"" << key << "\" updated.\n";
                break;
            case 4:
                dictionary.DisplayAscending();
                break;
            case 5:
                dictionary.DisplayDescending();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

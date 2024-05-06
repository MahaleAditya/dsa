#include <iostream>
#include <string>

using namespace std;

// Node structure for storing key-value pairs
struct Node {
    string key;
    int value;
    Node* next;
    
    Node(string k, int v) : key(k), value(v), next(nullptr) {}
};

// HashTable class
class HashTable {
private:
    static const int TABLE_SIZE = 10; // Size of the hash table
    Node* table[TABLE_SIZE]; // Array of pointers to nodes
    
    // Hash function to determine index from key
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE; // Modulus operation to ensure index within table bounds
    }
    
public:
    // Constructor to initialize table with nullptrs
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }
    
    // Function to insert a key-value pair into the hash table
    void Insert(const string& key, int value) {
        int index = hashFunction(key); // Compute index
        
        // Insert node at index (handle collision with chaining)
        switch (table[index] == nullptr) {
            case true:
                table[index] = new Node(key, value); // No collision, create new node
                break;
            case false:
                // Collision detected, traverse to end of chain and append new node
                Node* temp = table[index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = new Node(key, value);
                break;
        }
    }
    
    // Function to find the value associated with a key
    int Find(const string& key) {
        int index = hashFunction(key); // Compute index
        Node* temp = table[index]; // Start at head of chain
        
        // Traverse chain to find matching key
        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->value; // Key found, return value
            }
            temp = temp->next; // Move to next node in chain
        }
        
        return -1; // Key not found
    }
    
    // Function to delete a key-value pair from the hash table
    void Delete(const string& key) {
        int index = hashFunction(key); // Compute index
        Node* temp = table[index]; // Start at head of chain
        Node* prev = nullptr; // Pointer to previous node
        
        // Traverse chain to find node with matching key
        while (temp != nullptr && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }
        
        // If key found, delete node
        if (temp != nullptr) {
            switch (prev == nullptr) {
                case true:
                    table[index] = temp->next; // Special case: first node in chain
                    break;
                case false:
                    prev->next = temp->next; // Update previous node's next pointer
                    break;
            }
            delete temp; // Deallocate memory for node
        }
    }
    
    // Function to display the contents of the hash table
    void Display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << "(" << temp->key << ", " << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

// Main function
int main() {
    HashTable dictionary;
    int choice;
    string key;
    int value;
    
    // Menu-driven loop for interacting with the hash table
    do {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Find\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dictionary.Insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                value = dictionary.Find(key);
                if (value != -1) {
                    cout << "Value found: " << value << endl;
                } else {
                    cout << "Key not found.\n";
                }
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dictionary.Delete(key);
                cout << "Key deleted.\n";
                break;
            case 4:
                cout << "Hash Table Contents:\n";
                dictionary.Display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);
    
    return 0;
}

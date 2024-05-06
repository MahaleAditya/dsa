#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

}*root = NULL;#include<iostream>
using namespace std;

// Structure for a node in the binary search tree
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

// Global root pointer initially set to NULL
struct node* root = NULL;

// Function to insert a node into the binary search tree
void insert(int data)
{
    // Creating a new node
    struct node* nn = new node;
    nn->data = data;
    nn->right = nn->left = NULL;

    // If the tree is empty, make the new node as root
    if(root == NULL)
    {
        root = nn;
    }
    else
    {
        // Traverse the tree to find the appropriate position for insertion
        struct node* temp = root;
        while(true)
        {
            if(data == temp->data)
            {
                cout<<"\n Duplicate data found"; // Duplicate data not allowed
                delete nn; // Free the memory allocated for the new node
                return;
            }
            else if(data < temp->data)
            {
                if(temp->left == NULL)
                {
                    temp->left = nn; // Insert new node as left child
                    return;
                }
                temp = temp->left; // Move to the left child
            }
            else
            {
                if(data > temp->data)
                {
                    if(temp->right == NULL)
                    {
                        temp->right = nn; // Insert new node as right child
                        return;
                    }
                    temp = temp->right; // Move to the right child
                }
            }
        }
    }
}

// Function to calculate the height of the binary search tree
int height(struct node *r)
{
    if(r == NULL)
    {
        return 0; // Base case: height of an empty tree is 0
    }
    // Recursively calculate the height of the left and right subtrees
    int lh = height(r->left);
    int rh = height(r->right);
    // Return the maximum height among left and right subtrees, plus 1 for the current node
    return max(lh, rh) + 1;
}

// Function to find the minimum node in the binary search tree
int min(struct node *r)
{
    if(r == NULL)
    {
        cout<<"Tree is empty"; // If tree is empty, return -1
        return -1;
    }
    // Traverse left until the leftmost node is reached
    while(r->left != NULL)
    {
        r = r->left;
    }
    return r->data; // Return the data of the leftmost node
}

// Function to perform an inorder traversal and display the nodes of the binary search tree
void display(struct node *r)
{
    if(r == NULL)
    {
        return; // Base case: if tree is empty, return
    }
    // Inorder traversal: left subtree -> current node -> right subtree
    display(r->left); // Recursively traverse left subtree
    cout<<"->"<<r->data; // Print data of current node
    display(r->right); // Recursively traverse right subtree
}

int main()
{
    int data;
    int choice;

    while(true)
    {
        cout<<"\n1. Insert node";
        cout<<"\n2. Display tree";
        cout<<"\n3. Height of tree";
        cout<<"\n4. Minimum node";
        cout<<"\n5. Exit";
        cout<<"\n=> ";
        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"Enter data: ";
                cin>>data;
                insert(data); // Insert a node into the tree
                break;

            case 2:
                display(root); // Display the binary search tree
                cout<<endl;
                break;
            
            case 3:
                cout<<"Height of the tree is: "<<height(root)<<endl; // Calculate and display the height of the tree
                break;

            case 4:
                cout<< "Minimum data: "<<min(root)<<endl; // Find and display the minimum node in the tree
                break;

            case 5:
                return 0; // Exit the program
                break;

            default:
                cout<<"\n Wrong choice! \n"; // Display error message for wrong choice           
        }
    }
    return 0;
}

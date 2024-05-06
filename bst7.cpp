#include<iostream>
using namespace std;

// Structure for a node in the binary search tree
struct node{
    int data;
    struct node* left;
    struct node* right;
}*root=NULL;

// Function to insert a node into the binary search tree
void insert(int data){
    struct node *nn = new node;
    nn->data = data;
    nn->left=nn->right=NULL;
    if(root==NULL){
        root = nn; // If tree is empty, make the new node as root
    }
    else{
        struct node* temp=root;
        while(1){
            if(data==temp->data){
                cout<<"\nDuplicate data found"; // Duplicate data not allowed
                delete nn; // Free the memory allocated for the new node
                return;
            }
            else if(data<temp->data){
                if(temp->left==NULL){
                    temp->left = nn; // Insert new node as left child
                    return;
                }
                temp = temp->left; // Move to the left child
            }
            else{
                if(temp->right==NULL){
                    temp->right = nn; // Insert new node as right child
                    return;
                }
                temp = temp->right; // Move to the right child
            }
        }
    }
}

// Function to search for a data in the tree
void search(int data){
    if(root==NULL){
        cout<<"\nEmpty tree..."; // If tree is empty, data not found
        return;
    }
    struct node *temp=root;
    while(temp!=NULL){
        if(temp->data == data){
            cout<<"\nData Found..."; // Data found
            return;
        }
        else if(data<temp->data){
            temp = temp->left; // Move to the left child
        }
        else{
            temp = temp->right; // Move to the right child
        }
    }
    cout<<"\nData not found"; // Data not found
}

// Function to create mirror of the tree
void mirror(struct node* r){
    if(r==NULL)
        return;
    
    // Swap left and right subtrees of current node
    struct node* temp=r->left;
    r->left = r->right;
    r->right = temp;
    
    // Recursively create mirror for left and right subtrees
    mirror(r->left);
    mirror(r->right);  
}

// Function to perform an inorder traversal and display the nodes of the binary search tree
void display(struct node* r){
    if(r==NULL)
        return;
    
    // Inorder traversal: left subtree -> current node -> right subtree
    display(r->left); // Recursively traverse left subtree
    cout<<"->"<<r->data; // Print data of current node
    display(r->right); // Recursively traverse right subtree
}

// Driver code
int main(){
    int data;
    int choice;

    while(true){
        cout<<"\n1. Insert Node";
        cout<<"\n2. Display Tree";
        cout<<"\n3. Search";
        cout<<"\n4. Mirror of Tree";
        cout<<"\n5. Exit";
        cout<<"\n=>";
        cin>>choice;
        
        switch(choice){
            case 1:
                cout<<"\nEnter data : ";
                cin>>data;
                insert(data); // Insert a node into the tree
                break;
            case 2:
                display(root); // Display the binary search tree
                cout<<endl;
                break;
            case 3:
                cout<<"Enter key to search : ";
                cin>>data;
                search(data); // Search for a data in the tree
                break;
            case 4:
                mirror(root); // Create mirror of the tree
                cout<<"\nMirror Tree : ";
                display(root); // Display the mirror tree
                break;
            case 5:
                return 0; // Exit the program
                break;
            default:
                cout<<"\nWrong choice\n"; // Display error message for wrong choice
        }
    }

    return 0;
}

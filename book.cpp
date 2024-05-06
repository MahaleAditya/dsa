#include<iostream>
using namespace std;

int i,j,k;

// Structure for a node representing a section or subsection in a book
struct node
{
	string label;         // Label of the section or subsection
	int count;            // Number of subsections (if it's a section) or chapters (if it's a chapter)
	struct node* child[50]; // Array of pointers to child nodes
};

// Class representing a book
class book
{
	node* root; // Pointer to the root node of the book
	public:
	void create();    // Function to create the book structure
	void display();   // Function to display the book structure
	book()            // Constructor to initialize the root pointer to NULL
	{
		root = NULL;
	}
};

// Function to create the book structure
void book::create()
{
	root = new node;   // Create the root node
	cout<<"Enter name of book: ";
	cin>>root->label;  // Input the name of the book
	cout<<"Enter number of chapters: ";
	cin>>root->count;  // Input the number of chapters in the book

	// Loop to create chapters
	for(i = 0; i < root->count; i++)
	{
		root->child[i] = new node;  // Create a new node for each chapter
		cout<<"Enter the name of chapter "<<i+1<<": ";
		cin>>root->child[i]->label; // Input the name of the chapter
		cout<<"Enter number of sections for chapter "<<i+1<<": ";
		cin>>root->child[i]->count; // Input the number of sections in the chapter

		// Loop to create sections within the chapter
		for(j = 0; j < root->child[i]->count; j++)
		{
			root->child[i]->child[j] = new node; // Create a new node for each section
			cout<<"Enter the name of section "<<j+1<<" for chapter "<<i+1<<": ";
			cin>>root->child[i]->child[j]->label; // Input the name of the section
			cout<<"Enter number of sub-sections for section "<<j+1<<" in chapter "<<i+1<<": ";
			cin>>root->child[i]->child[j]->count; // Input the number of sub-sections in the section

			// Loop to create sub-sections within the section
			for(k = 0; k < root->child[i]->child[j]->count; k++)
			{
				root->child[i]->child[j]->child[k] = new node; // Create a new node for each sub-section
				cout<<"Enter the name of sub-section "<<k+1<<" for section "<<j+1<<" in chapter "<<i+1<<": ";
				cin>>root->child[i]->child[j]->child[k]->label; // Input the name of the sub-section
			}
		}
	}
}

// Function to display the book structure
void book::display()
{
	if(root == NULL)
		cout<<"Tree is empty";
	else
	{
		cout<<"Book name: "<<root->label<<"\n"; // Display the name of the book

		// Loop to iterate over chapters
		for(i = 0; i < root->count; i++)
		{
			cout<<i+1<<". "<<root->child[i]->label<<endl; // Display the name of each chapter

			// Loop to iterate over sections within each chapter
			for(j = 0; j < root->child[i]->count; j++)
			{
				cout<<"\t"<<j+1<<" --> "<<root->child[i]->child[j]->label<<endl; // Display the name of each section

				// Loop to iterate over sub-sections within each section
				for(k = 0; k < root->child[i]->child[j]->count; k++)
				{
					cout<<"\t\t"<<k+1<<" --> "<<root->child[i]->child[j]->child[k]->label<<endl; // Display the name of each sub-section
				}
			}
		}
	}
}

// Main function
int main()
{
	book b;      // Create an object of the book class
	b.create();  // Create the book structure
	b.display(); // Display the book structure
	return 0;
}

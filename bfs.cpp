#include <iostream>
#include <queue>
using namespace std;

// Structure to represent a node in the adjacency list
struct node
{
    int v;          // Vertex number
    node *next;     // Pointer to the next adjacent vertex
};

node *array[10];    // Array of pointers to nodes representing the adjacency list
int n, i, j;        // Variables for graph size and iteration
int vertex[10];     // Array to store vertex numbers
int visited[10];    // Array to keep track of visited vertices

// Function to get input from the user and construct the graph
void get()
{
    char ch;
    node *temp = NULL;
    
    // Initialize visited array
    for(i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    
    // Input number of landmarks
    cout << "\nEnter number of landmarks: ";
    cin >> n;
    
    // Input names of landmarks
    cout << "\nEnter name of landmarks: ";
    for(i = 1; i <= n; i++)
    {
        cin >> vertex[i];
    }

    // Initialize adjacency list
    for(i = 1; i <= n; i++)
    {
        array[i] = NULL;
    }

    // Construct adjacency list
    for(i = 1; i <= n; i++)
    {
        // Create a new node for the current vertex
        node *nn = new node;
        nn->next = NULL;
        nn->v = vertex[i];
        array[i] = nn;

        // Input connections from current vertex to other vertices
        for(j = 1; j <= n; j++)
        {
            if(i != j)
            {
                cout << "\nIs there a way from " << vertex[i] << " to " << vertex[j] << " (y/n): ";
                cin >> ch;
                if(ch == 'y')
                {
                    // Create a new node for the adjacent vertex
                    node *nn = new node;
                    nn->next = NULL;
                    nn->v = vertex[j];

                    // Add the new node to the adjacency list
                    if(array[i]->next == NULL)
                    {
                        array[i]->next = nn;
                    }
                    else
                    {
                        temp = array[i];
                        while(temp->next != NULL)
                        {
                            temp = temp->next;
                        }
                        temp->next = nn;
                    }
                }
            }
        }
    }
}

// Function to display the adjacency list representation of the graph
void display()
{
    node* temp = NULL;
    cout << "\nAdjacency list is:";
    for(i = 1; i <= n; i++)
    {
        cout << "\nFrom " << vertex[i] << " there is way to -> ";
        temp = array[i]->next;
        while(temp != NULL)
        {
            cout << "\t" << temp->v;
            temp = temp->next;
        }
    }
}

// Function to perform Breadth-First Search traversal
void bfs(int s)
{
    int var;
    queue <int> q;
    node *p;
    int c;

    // Enqueue the starting vertex
    q.push(s);
    
    // BFS traversal
    while(!q.empty())
    {
        // Dequeue a vertex
        var = q.front();
        q.pop();

        // Print the dequeued vertex
        cout << var << "->";

        // Mark the dequeued vertex as visited
        visited[var] = 1;

        // Enqueue all unvisited neighbors of the dequeued vertex
        for(p = array[var]; p != NULL; p = p->next)
        {
            c = p->v;
            if(visited[c] == 0)
            {
                visited[c] = 1;
                q.push(c);
            }
        }
    }
}

int main()
{
    // Construct the graph
    get();

    // Display the adjacency list
    display();

    int source;
    // Input the starting vertex for BFS traversal
    cout << "\nEnter starting vertex: ";
    cin >> source;

    // Perform BFS traversal starting from the specified source vertex
    bfs(source);

    return 0;
}

#include<iostream>
#include<stack>
using namespace std;

// Global variables
int adj_mat[50][50] = {0};  // Adjacency matrix to represent the graph
int visited[50] = {0};       // Array to keep track of visited nodes
string vertex[50];           // Array to store names of landmarks
char ch;                      // Temporary variable for user input
int i, j, v, n, s;           // Variables for iteration, vertex, number of nodes, and starting node

// Function to get input from the user and construct the graph
void get()
{
    cout << "\nEnter the number of total nodes: ";
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cout << "\nEnter the name of landmark " << i << ": ";
        cin >> vertex[i];
    }
    // Initialize visited array and adjacency matrix
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
        for(j = 0; j < n; j++)
        {
            adj_mat[i][j] = 0;
        }
    }
    // Input connections between landmarks
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i != j)
            {
                cout << "Is there a way from " << vertex[i] << " to " << vertex[j] << " (y/n): ";
                cin >> ch;
                if(ch == 'y')
                {
                    adj_mat[i][j] = 1;
                }
            }
        }
    }    
}

// Function to display the adjacency matrix
void show()
{
    cout << "\t";
    for(i = 0; i < n; i++)
    {
        cout << vertex[i] << "\t";
    }
    cout << "\n";

    for(i = 0; i < n; i++)
    {
        cout << vertex[i] << "\t";
        for(j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Function to perform Depth-First Search (DFS) traversal
void dfs(int s)
{
    stack<int> st;

    // Push the starting node onto the stack and mark it as visited
    st.push(s);
    visited[s] = 1;
    while(!st.empty())
    {
        v = st.top();
        cout << vertex[v]; // Print the vertex being visited
        st.pop();
        // Explore all unvisited neighbors of the current vertex
        for(i = 0; i < n; i++)
        {
            if(visited[i] == 0 && adj_mat[v][i] == 1)
            {
                visited[i] = 1; // Mark the neighbor as visited
                st.push(i);     // Push the neighbor onto the stack
            }
        }
    }
}

int main()
{
    get(); // Construct the graph
    show(); // Display the adjacency matrix
    cout << "Enter the starting node: ";
    cin >> s; // Input the starting node for DFS traversal
    dfs(s); // Perform DFS traversal starting from the specified node
    return 0;
}

#include <iostream>
#include <cstdlib> // for exit(0)
using namespace std;

// Function declarations
void obst();
void print(int, int);

// Global arrays to store weights, probabilities, costs, and root nodes
float a[10], b[11], wt[10][10], c[10][10];
int r[10][10], n;

// Function to calculate the optimal binary search tree
void obst() {
    // Calculate weights and initialize cost and root arrays for each interval [i, j]
    for (int i = 0; i < n; i++) {
        wt[i][i] = b[i];
        c[i][i] = 0.0;
        r[i][i] = i;
        wt[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
        c[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
        r[i][i + 1] = i + 1;
    }
    wt[n][n] = b[n];
    c[n][n] = 0.0;
    r[n][n] = 0;

    // Fill in the cost and root arrays for intervals of length greater than 1
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l;
            wt[i][j] = wt[i][j - 1] + a[j] + b[j];
            c[i][j] = 9999; // Initialize to a large value
            for (int k = i + 1; k <= j; k++) {
                float temp = c[i][k - 1] + c[k][j];
                if (temp < c[i][j]) {
                    c[i][j] = temp;
                    r[i][j] = k;
                }
            }
            c[i][j] += wt[i][j];
        }
    }

    // Print the results
    cout << "Optimal BST:\n";
    cout << "Weight of tree: " << wt[0][n] << endl;
    cout << "Cost of tree: " << c[0][n] << endl;
    cout << "Root node of tree: " << r[0][n] << endl;
}

// Function to print the structure of the optimal binary search tree
void print(int l, int r) {
    if (l >= r)
        return;
    cout << "Root: " << ::r[l][r] << endl; // Print the root of the subtree [l, r]
    if (l < r - 1) {
        cout << "Left Child of " << ::r[l][r] << ": ";
        print(l, ::r[l][r] - 1); // Recursively print the left subtree
    }
    if (r > l + 1) {
        cout << "Right Child of " << ::r[l][r] << ": ";
        print(::r[l][r], r); // Recursively print the right subtree
    }
}

int main () {
    // Input number of nodes and probabilities
    cout << "Enter the no. of nodes: ";
    cin >> n;
    cout << "Enter the probability of successful search: ";
    for (int i = 1; i <= n; i++) {
        cout << "p[" << i << "]: ";
        cin >> a[i];
    }
    cout << "Enter the probability of unsuccessful search: ";
    for (int i = 0; i <= n; i++) {
        cout << "q[" << i << "]: ";
        cin >> b[i];
    }
    obst(); // Calculate the optimal binary search tree
    cout << "Structure of Optimal BST:\n";
    print(0, n); // Print the structure of the optimal binary search tree
    return 0;
}

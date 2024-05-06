#include <iostream>
using namespace std;

class Heap {
public:
    // Function to maintain the max heap property
    void maxHeap(int marks[], int i, int n);
    
    // Function to build max heap
    void buildMaxHeap(int marks[], int n);
    
    // Function to perform heapsort
    void heapsort(int marks[], int n);
    
    // Function to accept input
    void accept();
    
    // Function to display sorted marks
    void display(int marks[], int n);
};

// Function to maintain the max heap property
void Heap::maxHeap(int marks[], int i, int n) {
    int l, r, largest;

    l = 2 * i;
    r = (2 * i + 1);

    largest = ((l <= n) && marks[l] > marks[i]) ? l : i; // Find the largest among i, left child, and right child

    if ((r <= n) && (marks[r] > marks[largest]))
        largest = r; // Update largest if right child is larger

    if (largest != i) { // If largest is not the current node
        swap(marks[largest], marks[i]); // Swap largest with current node
        maxHeap(marks, largest, n); // Recursively heapify the affected subtree
    }
}

// Function to build max heap
void Heap::buildMaxHeap(int marks[], int n) {
    for (int k = n / 2; k >= 1; k--)
        maxHeap(marks, k, n); // Heapify each subtree starting from the last non-leaf node
}

// Function to perform heapsort
void Heap::heapsort(int marks[], int n) {
    buildMaxHeap(marks, n); // Build max heap
    for (int i = n; i >= 2; i--) {
        swap(marks[i], marks[1]); // Swap the maximum element with the last element
        maxHeap(marks, 1, i - 1); // Heapify the reduced heap
    }
}

// Function to accept input
void Heap::accept() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    int marks[n];
    cout << "\nEnter the marks of students:";
    for (int i = 1; i <= n; i++)
        cin >> marks[i]; // Input marks of students

    heapsort(marks, n); // Perform heapsort
    display(marks, n); // Display sorted marks
}

// Function to display sorted marks
void Heap::display(int marks[], int n) {
    cout << "\nSORTED MARKS\n\n";
    for (int i = 1; i <= n; i++)
        cout << marks[i] << endl; // Print sorted marks

    cout << "\nMinimum marks obtained: " << marks[1]; // Print minimum marks
    cout << "\nMaximum marks obtained: " << marks[n]; // Print maximum marks
}

int main() {
    Heap h;
    h.accept(); // Start the process by accepting input and performing heapsort
    return 0;
}

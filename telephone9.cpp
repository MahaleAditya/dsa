#include<iostream>
#include<string.h>
#define max 10
using namespace std;

// Structure to represent a node in the hash table
struct node
{
    char name[10];
    long int mn;
    node()
    {
        mn = 0;
        strcpy(name, "--------"); // Initialize name with dashes
    }
};

// Class to implement a telephone directory using hashing with linear and quadratic probing
class telephone
{
public:
    node h[max]; // Array for linear probing
    node ht[max]; // Array for quadratic probing
    int count; // Counter variable
    telephone()
    {
        count = 0; // Initialize counter
    }
    int hashfun(long int); // Hash function
    void Insert(); // Function to insert using linear probing
    void insert(); // Function to insert using quadratic probing
    void display(); // Function to display using quadratic probing
    void Display(); // Function to display using linear probing
    int linearProbe(long int); // Function for linear probing
    int quadraticProbe(long int); // Function for quadratic probing
};

// Hash function to determine the index for a given phone number
int telephone::hashfun(long int num)
{
    return (num % 10); // Simple modulo hashing
}

// Function for linear probing
int telephone::linearProbe(long int num)
{
    int ind = hashfun(num);
    int comparisons = 1;

    while (h[ind].mn != num && h[ind].mn != 0) { // Continue until empty slot or matching phone number is found
        ind = (ind + 1) % max; // Move to the next slot
        comparisons++; // Increment comparisons count
    }

    return comparisons; // Return number of comparisons made
}

// Function for quadratic probing
int telephone::quadraticProbe(long int num)
{
    int ind = hashfun(num);
    int comparisons = 1;
    int i = 1;

    while (h[ind].mn != num && h[ind].mn != 0) { // Continue until empty slot or matching phone number is found
        ind = (ind + i * i) % max; // Move to the next slot with quadratic increment
        i++;
        comparisons++; // Increment comparisons count
    }

    return comparisons; // Return number of comparisons made
}

// Function to insert using linear probing
void telephone::Insert()
{
    node s1;
    int ind;
    cout << "**DATA FOR LINEAR PROBING**" << endl;
    cout << "Enter name:";
    cin >> s1.name;
    cout << "Enter telephone number:";
    cin >> s1.mn;
    ind = hashfun(s1.mn);
    if (h[ind].mn == 0)
    {
        h[ind] = s1; // Insert at calculated index
    }
    else
    {
        // Linear probing
        int i = 1;
        int newIndex = (ind + i) % max; // Calculate the new index
        while (h[newIndex].mn != 0 && newIndex != ind) // Continue until an empty slot or back to the original index
        {
            i++;
            newIndex = (ind + i) % max; // Recalculate the new index
        }
        if (newIndex != ind) // If we found an empty slot
        {
            h[newIndex] = s1; // Insert at new index
        }
        else
        {
            cout << "Hash table is full, cannot insert." << endl;
        }
    }
}

// Function to display using linear probing
void telephone::Display()
{
    for (int i = 0; i < max; i++)
    {
        cout << i << "\t" << h[i].name << "\t" << h[i].mn << endl;
    }
}

// Function to insert using quadratic probing
void telephone::insert()
{
    node s;
    int ind;
    long int m;
    cout << "enter name and telephone no.:" << endl;
    cin >> s.name >> s.mn;
    m = s.mn;
    ind = hashfun(s.mn);
    cout << "index:" << ind << endl;
    if (ht[ind].mn == 0)
    {
        ht[ind] = s;
    }
    else
    {
        int i = 1;
        while (ht[ind].mn != 0)
        {
            ind = (m + (i * i)); // Quadratic probing
            ind = ind % max;
            i++;
        }
        ht[ind] = s;
    }
}

// Function to display using quadratic probing
void telephone::display()
{
    for (int i = 0; i < max; i++)
    {
        cout << i << "\t" << ht[i].name << "\t" << ht[i].mn << endl;
    }
}

// Main function
int main()
{
    telephone t;
    int ch;
    char ans;
    do
    {
        cout << "enter your choice" << endl;
        cout << "1. Linear insert" << endl;
        cout << "2. Display for linear" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Display" << endl;
        cout << "5. Compare linear and quadratic probing" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            t.Insert(); // Insert using linear probing
            break;
        case 2:
            t.Display(); // Display using linear probing
            break;
        case 3:
            t.insert(); // Insert using quadratic probing
            break;
        case 4:
            t.display(); // Display using quadratic probing
            break;
        case 5:
            {
                long int phoneNumber;
                cout << "Enter telephone number to search: ";
                cin >> phoneNumber;
                int linearComparisons = t.linearProbe(phoneNumber);
                int quadraticComparisons = t.quadraticProbe(phoneNumber);
                cout << "Linear probing comparisons: " << linearComparisons << endl;
                cout << "Quadratic probing comparisons: " << quadraticComparisons << endl;
            }
            break;
        default:
            cout << "Invalid choice!!!" << endl;
        }
        cout << "Do you want to continue? (y/n)";
        cin >> ans;
    } while (ans == 'y');
    return 0;
}

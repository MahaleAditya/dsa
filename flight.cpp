#include<iostream>
using namespace std;

class flight
{
    int time[10][10];   // 2D array to store flight times between cities
    string name[10];    // Array to store names of cities
    int n;              // Number of cities
public:
    void read();        // Function to read input from the user
    void disp();        // Function to display the flight schedule
    void connect();     // Function to check if the flight network is connected
};

// Function to read input from the user
void flight::read()
{
    int i,j;
    cout<<"Enter number of cities: ";
    cin>>n;
    // Input names of cities
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the name of city "<< i + 1 << ": ";
        cin>>name[i];
    }
    // Initialize flight times matrix to 0
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            time[i][j]=0;
        }
    }
    // Input flight times between cities
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                char ch;
                cout<<"Is there a flight from "<<name[i]<<" to "<<name[j]<<" (y/n): ";
                cin>>ch;
                if(ch=='y' || ch=='Y')
                {
                    cout<<"Enter the time required for the flight (in min): ";
                    cin>>time[i][j];
                    time[j][i]=time[i][j];  // Since it's an undirected graph, time[j][i] is set to the same value
                }
            }
        }
    }
}

// Function to display the flight schedule
void flight::disp()
{
    // Display column headers (city names)
    for(int i=0;i<n;i++)
    {
        cout<<"  "<<name[i];
    }
    cout<<endl;
    // Display flight times between cities
    for(int i=0;i<n;i++)
    {
        cout<<name[i]<<"|";
        for(int j=0;j<n;j++)
        {
            cout<<time[i][j]<<" ";  // Display flight time
        }
        cout<<"|"<<endl;
    }
}

// Function to check if the flight network is connected
void flight::connect()
{
    int c=0;
    // Check if there are any zero values in the flight times matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(time[i][j]==0)
            {
                c++;  // Increment count if a zero value is found
            }
        }
        // If all elements in a row are zero, the graph is not connected
        if(c==n)
        {
            break;
        }
    }
    // If count equals the number of cities, the graph is not connected
    if(c==n)
    {
        cout<<"Graph is not connected";
    }
    else
    {
        cout<<"Graph is connected";
    }
}

// Main function
int main()
{
    flight f;  // Create an object of the flight class
    f.read();  // Read input (flight schedule) from the user
    f.disp();  // Display the flight schedule
    f.connect(); // Check if the flight network is connected
    return 0;
}

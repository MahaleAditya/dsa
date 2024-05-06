#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

// Function to add a student to the database
void addstudent(){
    // Declaration of variables to store student information
    string name, add, b, rn;

    // Opening the file in append mode
    ofstream f("db.txt", ios::app);

    // Getting student information from the user
    cout << "\nEnter roll no.: ";
    cin >> rn;
    cout << "\nEnter name: ";
    cin >> name;
    cout << "\nEnter Division: ";
    cin >> b;
    cout << "\nEnter Address: ";
    cin >> add;

    // Writing student information to the file
    f << "\n" << left << setw(20) << rn << setw(20) << name << setw(20) << b << setw(20) << add;

    // Closing the file
    f.close();
    cout << "Data added successfully\n";
}

// Function to delete a student from the database
void deletestudent(){
    // Opening the file in input mode
    ifstream f("db.txt");
    string line, rn, filedata;
   
    cout << "\nEnter the roll no. to delete: ";
    cin >> rn;
    
    // Reading each line from the file
    while(getline(f, line)){
        // Checking if the roll number is found in the line
        if(line.find(rn) == string::npos ){
            // If not found, append the line to filedata
            filedata += line;
            filedata += "\n";    
        }
    }
    f.close();
    
    // Opening the file in output mode to overwrite
    ofstream f1("db.txt", ios::out);
    // Writing filedata to the file
    f1 << filedata;
    f1.close();
}

// Function to search for a student in the database
void searchstudent(){
    // Opening the file in input mode
    ifstream f("db.txt");
    string line, rn;
   
    cout << "\nEnter the roll no. to search: ";
    cin >> rn;
    bool found = false;
    // Reading each line from the file
    while(getline(f, line)){
        // Checking if the roll number is found in the line
        if(line.find(rn) != string::npos ){
            // If found, print the line
            cout << line << endl;
            found = true;
        }
    }
    f.close();
    // If roll number not found, display message
    if(!found){
        cout << "\nStudent does not exist.";
    }
}

// Function to print all students' data from the database
void printstudent(){
    // Opening the file in input mode
    ifstream f("db.txt", ios::in);
    string line; 
    cout << "Student data:\n";
    // Reading each line from the file and printing it
    while(getline(f, line)){
        cout << line << "\n";
    }
    
    f.close();
}

// Main function
int main(){
    // Writing headers to the file
    ofstream f("db.txt", ios::out);
    f << left << setw(20) << "Roll no." << setw(20) << "Name" << setw(20) << "Division" << setw(20) << "Address";
    f.close();

    int ch;

    // Menu-driven loop to perform operations
    while(ch != -1){
        cout << "Enter your choice\n1. Add Student\n2. Delete Student\n3. Search Student\n4. Print Student\n5. Exit\n";
        cin >> ch;
        switch(ch){
            case 1:
                addstudent(); // Add a student
                break;
            case 2:
                deletestudent(); // Delete a student
                break;
            case 3:
                searchstudent(); // Search for a student
                break;
            case 4:
                printstudent(); // Print all students' data
                break;
            case 5:
                break; // Exit the program
            default:
                cout << "Give valid input\n"; // Handle invalid input
        }
    }
    return 0;
}

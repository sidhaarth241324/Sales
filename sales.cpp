#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void create(){
    srand(time(0)); // Seed for random SaleID

    // Check if sales.csv exists, if not create with header
    ifstream checkFile("sales.csv");
    bool fileExists = checkFile.good();
    checkFile.close();

    ofstream file("sales.csv", ios::app); // Open in append mode
    if (!fileExists) {
        file << "Date,SaleID,Item,Quantity,Price\n"; // Add header
    }

    string date, itemName;
    int quantity;
    int unitPrice;
    int saleID = rand() % 9000 + 1000; // Generate random SaleID (1000-9999)

    // Get inputs from user
    cout << "Enter Date (DD/MM/YYYY): ";
    cin >> date;

    cout << "Generated SaleID: " << saleID << "\n";

    cout << "Enter Item Name: ";
    cin >> itemName;

    cout << "Enter Quantity: ";
    cin >> quantity;

    cout << "Enter Unit Price: ";
    cin >> unitPrice;

    // Write to CSV
    file << date << "," << saleID << "," << itemName << "," << quantity << "," << unitPrice << "\n";

    file.close();
    cout << "Record saved successfully in sales.csv!\n";
}

int main() 
{
    cout << "Does sales.csv exists?";
    char ch;
    cin >> ch;
    if (ch=='y'){
        
        cout<<"sales.csv exists" << endl;
        create();
        // read();
        // update();
        // delete();
    } else {
        cout << "Create a sales.csv" << endl;
        ofstream file("sales.csv");
    }
    cout << "Does temp.csv exists?" << endl;
    char chh;
    cin >> chh;
    if (chh=='y'){
        cout << "temp.csv exists" << endl;
        // sort();
        // Report();
    }else{
        cout << "Create a temp.csv" << endl;
        ofstream file("temp.csv");
    }
}    
   
    

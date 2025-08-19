#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

void read(){
    ifstream file("sales.csv");
    if (!file) {
        cout << "sales.csv not found!\n";
        return;
    }

    string line;
    getline(file, line); // Skip header

    bool isEmpty = true;

    cout << "\nSales Records:\n";
    cout << "--------------------------------------------------------\n";
    cout << "Date         SaleID   Item       Quantity    Price\n";
    cout << "--------------------------------------------------------\n";

    while (getline(file, line)) {
        if (line.empty()) continue;
        isEmpty = false;

        // Split by comma
        stringstream ss(line);
        string date, saleID, item, quantity, price;
        getline(ss, date, ',');
        getline(ss, saleID, ',');
        getline(ss, item, ',');
        getline(ss, quantity, ',');
        getline(ss, price, ',');

        // Display
        cout << date << "   " << saleID << "     "
             << item << "       " << quantity
             << "         " << price << "\n";
    }

    if (isEmpty) {
        cout << "No records found. The list is empty!\n";
    }
    cout << "--------------------------------------------------------\n";

    file.close();
}

void update(){
    ifstream file("sales.csv");
    if (!file) {
        cout << "sales.csv not found!\n";
        return;
    }

    string line;
    getline(file, line); // Read header
    string header = line;

    vector<string> records;
    while (getline(file, line)) {
        if (!line.empty()) {
            records.push_back(line);
        }
    }
    file.close();

    if (records.empty()) {
        cout << "No records found. The list is empty!\n";
        return;
    }

    string searchID;
    cout << "Enter SaleID to update: ";
    cin >> searchID;

    bool found = false;
    for (size_t i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        string date, saleID, item, quantity, price;
        getline(ss, date, ',');
        getline(ss, saleID, ',');
        getline(ss, item, ',');
        getline(ss, quantity, ',');
        getline(ss, price, ',');

        if (saleID == searchID) {
            found = true;
            cout << "Record found! Current details:\n";
            cout << "Date: " << date << " Item: " << item
                 << " Quantity: " << quantity << " Price: " << price << "\n";

            // Get new details
            cout << "Enter new Date (DD/MM/YYYY): ";
            cin >> date;
            cout << "Enter new Item Name: ";
            cin >> item;
            cout << "Enter new Quantity: ";
            cin >> quantity;
            cout << "Enter new Price: ";
            cin >> price;

            // Update the record
            records[i] = date + "," + saleID + "," + item + "," + quantity + "," + price;
            break;
        }
    }

    if (!found) {
        cout << "Error: SaleID not found!\n";
        return;
    }

    // Rewrite the CSV file with updated data
    ofstream outFile("sales.csv");
    outFile << header << "\n";
    for (string &rec : records) {
        outFile << rec << "\n";
    }
    outFile.close();

    cout << "Record updated successfully!\n";
}



int main() 
{
    cout << "Does sales.csv exists?";
    char ch;
    cin >> ch;
    if (ch=='y'){
        
        cout<<"sales.csv exists" << endl;
        create();
        read();
        update();
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
   
    

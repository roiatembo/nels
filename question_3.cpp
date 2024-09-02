#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("orders.dat");
    ofstream outputFile("result.dat");

    if (!inputFile) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    int numFamilies = 0;
    int totalPeople = 0;
    int familiesWithSpecial = 0;
    float totalCommission = 0.0;
    float totalBill = 0.0;

    int members, specialOrders, wineBottles;
    float billAmount;

    while (inputFile >> members >> specialOrders >> wineBottles >> billAmount) {
        totalPeople += members;
        totalBill += billAmount;

        if (members >= 5 && specialOrders >= 4 && wineBottles >= 2) {
            familiesWithSpecial++;
            totalCommission += 0.03 * billAmount;
        }

        numFamilies++;
    }

    inputFile.close();

    float avgSpentPerPerson = totalBill / totalPeople;

    outputFile << fixed << setprecision(2);
    outputFile << "Number of families that ordered the special: " << familiesWithSpecial << endl;
    outputFile << "Commission earned from the special meal: R" << totalCommission << endl;
    outputFile << "Average spent per person for the evening: R" << avgSpentPerPerson << endl;

    outputFile.close();

    cout << "Results have been written to result.dat." << endl;

    return 0;
}

/*
Sample content of orders.dat

5 2 2 670.60
6 4 2 890.80
2 2 0 220.00
10 8 1 1340.60
10 4 3 1430.70
4 0 0 460.30
5 3 1 700.00
7 5 2 1100.80
3 1 0 340.80

Expected Output

Number of families that ordered the special: 3
Commission earned from the special meal: R102.67
Average spent per person for the evening: R137.59

*/
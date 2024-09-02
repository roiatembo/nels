#include <iostream>
using namespace std;

const double GLOBALMAIL_ZONE_1_TO_3_RATE = 108.0;
const double GLOBALMAIL_ZONE_4_TO_6_RATE = 130.0;

const double DHL_RATE_PER_KG = 70.0;

double calcPostage(double weight, int zone) {
    double cost = 0.0;
    if (zone >= 1 && zone <= 3) {
        cost = weight * GLOBALMAIL_ZONE_1_TO_3_RATE;
    } else if (zone >= 4 && zone <= 6) {
        cost = weight * GLOBALMAIL_ZONE_4_TO_6_RATE;
    } else {
        cout << "Zone must be between 1 and 6." << endl;
    }
    return cost;
}

double calcPostage(double weight, double length, double width, double height) {
    double volumetric_weight = (length * width * height) / 5000.0;
    double chargeable_weight = max(weight, volumetric_weight);
    double cost = chargeable_weight * DHL_RATE_PER_KG;
    return cost;
}

int main() {
    char service_choice;
    cout << "Enter 'd' for DHL or 'g' for GlobalMail: ";
    cin >> service_choice;

    if (service_choice == 'g' || service_choice == 'G') {
        double weight;
        int zone;
        cout << "Enter the weight of the parcel in kg: ";
        cin >> weight;
        cout << "Enter the zone (1-6): ";
        cin >> zone;
        
        if (zone >= 1 && zone <= 6) {
            double cost = calcPostage(weight, zone);
            cout << "The cost for GlobalMail is: R" << cost << endl;
        } else {
            cout << "Invalid zone. Please enter a zone between 1 and 6." << endl;
        }

    } else if (service_choice == 'd' || service_choice == 'D') {
        double weight, length, width, height;
        cout << "Enter the actual weight of the parcel in kg: ";
        cin >> weight;
        cout << "Enter the length of the box in cm: ";
        cin >> length;
        cout << "Enter the width of the box in cm: ";
        cin >> width;
        cout << "Enter the height of the box in cm: ";
        cin >> height;
        
        double cost = calcPostage(weight, length, width, height);
        cout << "The cost for DHL is: R" << cost << endl;

    } else {
        cout << "Invalid choice. Please enter 'd' for DHL or 'g' for GlobalMail." << endl;
    }

    return 0;
}
/*
Input
Enter 'd' for DHL or 'g' for GlobalMail: d
Enter the actual weight of the parcel in kg: 3.5
Enter the length of the box in cm: 40
Enter the width of the box in cm: 30
Enter the height of the box in cm: 20

Output
The cost for DHL is: R245.00
*/
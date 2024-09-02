#include <iostream>
#include <cassert> 
using namespace std;

int main() {
    int yearOfBirth, currentYear = 2024; 

    cout << "Enter your year of birth: ";
    cin >> yearOfBirth;

    assert(yearOfBirth != currentYear && yearOfBirth <= currentYear);

    int age = currentYear - yearOfBirth;

    if (age >= 18) {
        cout << "You are " << age << " years old. You are allowed to vote." << endl;
    } else {
        cout << "You are " << age << " years old. You are not allowed to vote." << endl;
    }

    return 0;
}

/*
Input
Enter your year of birth: 2010
Output
You are 14 years old. You are not allowed to vote.

*/
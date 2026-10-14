#include <iostream>
#include <stack>
#include <limits>
using namespace std;
/*
    Anthony Diaz / adiaz6040@sdsu.edu
    CS 210 / Scovil
    Assignment 4 - De-Recursion
*/

//This asks if the user wants to keep continuing calculations for factorials
bool askToContinue() {
    char userInput;
    while (true) {
        cout << "Want to calculate another factorial? (Y/N)" << endl;
        cin >> userInput;
        if (cin.fail() == true) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again." << endl;
        } else if (userInput == 'Y' || userInput == 'y') {
            return true;
        } else if (userInput == 'N' || userInput == 'n') {
            return false;
        }
        else {
            cout << "Invalid input. Try again." << endl;

        }
    }
}
//Takes User Input
int userInput() {
    int userNum;
    bool validInput = false;
    do {
        cout << "Please enter an integer (0-20): ";
        cin >> userNum;
        if (cin.fail()) {
            cin.clear(); // Clears cin input if it fails
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
            cout << "Invalid input. Try again." << endl;
        }
        else if (userNum < 0 || userNum > 20) {
            cout << "Invalid input. Try again." << endl;
            validInput = false;
        } else {
            validInput = true;
        }
    }   while (!validInput);
    return userNum;
}
void printName() {
    cout << "Anthony Diaz" << endl;
    cout << "ID : 134646574" << endl;
    cout << "CS210 - Assignment 4" << endl;
}
//I used unsigned long long to open up the range for the input becasue
class Factorial {
public:
    unsigned long long calculate(int num) {
        stack<int> s;
        for (int i = 1; i <= num; i++) {
            s.push(i);
        }
        unsigned long long accumulator = 1;
        while (!s.empty()) {
            int currentValue = s.top();
            s.pop();
            accumulator *= currentValue;
        }
        return accumulator;
    }
};
int main() {
    printName();
    Factorial f;
    while (true) {
        int userSelection = userInput();
        unsigned long long result = f.calculate(userSelection);
        cout << "The factorial of " << userSelection
             << " is " << result << "." << endl;
        if (!askToContinue()) {
            break;
        }
    }
    return 0;
}
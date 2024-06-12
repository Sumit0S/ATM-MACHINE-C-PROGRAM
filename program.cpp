#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();
void depositMoney();
void withdrawMoney();
void requestBalance();

// Global variables
char menuInput;
map<string, pair<string, double> > accounts; 
string loggedInUser;

// Main function
int main() {
    cout << "Hi! Welcome to Mr. Zamar's ATM Machine!" << endl;
   
    start();
    return 0;
}

void printIntroMenu() {
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void printMainMenu() {
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void start() {
    while (true) {
        printIntroMenu();
        cin >> menuInput;

        switch (menuInput) {
            case 'l':
                login();
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                exit(0);
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
}

void createAccount() {
    string userId, password;

    cout << "Please enter your user name: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    if (accounts.find(userId) != accounts.end()) {
        cout << "User already exists. Please try logging in." << endl;
        return;
    }


    accounts[userId] = make_pair(password, 0.0);
    cout << "Thank You! Your account has been created!" << endl;
}

void login() {
    string userId, password;

    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    
    if (accounts.find(userId) != accounts.end() && accounts[userId].first == password) {
        loggedInUser = userId;
        cout << "Access Granted!" << endl;

        
        while (true) {
            printMainMenu();
            cin >> menuInput;

            switch (menuInput) {
                case 'd':
                    depositMoney();
                    break;
                case 'w':
                    withdrawMoney();
                    break;
                case 'r':
                    requestBalance();
                    break;
                case 'q':
                    cout << "Thanks for stopping by!" << endl;
                    return;
                default:
                    cout << "Invalid option. Please try again." << endl;
                    break;
            }
        }
    } else {
        cout << "******** LOGIN FAILED! ********" << endl;
    }
}

void depositMoney() {
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;
    accounts[loggedInUser].second += amount;
}

void withdrawMoney() {
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;

    if (amount <= accounts[loggedInUser].second) {
        accounts[loggedInUser].second -= amount;
    } else {
        cout << "Insufficient balance." << endl;
    }
}

void requestBalance() {
    cout << "Your balance is $" << fixed << setprecision(2) << accounts[loggedInUser].second << "." << endl;
}

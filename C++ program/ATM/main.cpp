
#include <iostream>
using namespace std;

int main() {
    int pin = 1234;          // Default PIN
    int enteredPin;
    int choice;
    double balance = 1000.0; // Starting balance
    double amount;

    cout << "===== WELCOME TO SIMPLE ATM =====" << endl;
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    // Check PIN
    if (enteredPin != pin) {
        cout << "Incorrect PIN. Access Denied!" << endl;
        return 0;
    }

    do {
        cout << "\n===== ATM MENU =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Your current balance is: $" << balance << endl;
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << "Deposit successful!" << endl;
                } else {
                    cout << "Invalid amount!" << endl;
                }
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount > balance) {
                    cout << "Insufficient funds!" << endl;
                } else if (amount <= 0) {
                    cout << "Invalid amount!" << endl;
                } else {
                    balance -= amount;
                    cout << "Withdrawal successful!" << endl;
                }
                break;

            case 4:
                cout << "Thank you for using the ATM!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}

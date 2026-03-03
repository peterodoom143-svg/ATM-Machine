 #include <iostream>

using namespace std;

class Transaction {
public:
    string type;     // Income or Expense
    string category; // Food, Rent, etc.
    double amount;

    Transaction(string t, string c, double a) {
        type = t;
        category = c;
        amount = a;
    }
};

vector<Transaction> transactions;

// Save to file
void saveToFile() {
    ofstream file("finance.txt");
    for (auto &t : transactions) {
        file << t.type << " "
             << t.category << " "
             << t.amount << endl;
    }
    file.close();
}

// Load from file
void loadFromFile() {
    ifstream file("finance.txt");
    string type, category;
    double amount;

    while (file >> type >> category >> amount) {
        transactions.push_back(Transaction(type, category, amount));
    }
    file.close();
}

// Add transaction
void addTransaction() {
    string type, category;
    double amount;

    cout << "Enter type (Income/Expense): ";
    cin >> type;

    cout << "Enter category: ";
    cin >> category;

    cout << "Enter amount: ";
    cin >> amount;

    transactions.push_back(Transaction(type, category, amount));
    saveToFile();

    cout << "Transaction added successfully!\n";
}

// Show summary
void showSummary() {
    double totalIncome = 0;
    double

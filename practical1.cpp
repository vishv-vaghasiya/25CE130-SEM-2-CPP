#include <iostream>
using namespace std;

class bank_account {
    char Account_Holder_Name[200];
    double Accn;
    long double Account_balance;

public:
    void create_account();
    void display_balance();
    int search_acc(double);
    void withdraw_money();
    void deposit_money();
};

void bank_account::create_account() {
    cin.ignore();
    cout << "Enter account holder name: ";
    cin.getline(Account_Holder_Name, 200);

    cout << "Enter account number: ";
    cin >> Accn;

    cout << "Enter initial balance: ";
    cin >> Account_balance;

    cout << "Account created successfully!\n";
}

void bank_account::display_balance() {
    cout << "Name    : " << Account_Holder_Name << endl;
    cout << "Balance : " << Account_balance << endl;
}

int bank_account::search_acc(double id) {
    return Accn == id;
}

void bank_account::withdraw_money() {
    long double amt;
    cout << "Enter withdraw amount: ";
    cin >> amt;

    if (amt > Account_balance)
        cout << "Insufficient balance\n";
    else {
        Account_balance -= amt;
        cout << "Withdraw successful\n";
    }
}

void bank_account::deposit_money() {
    long double amt;
    cout << "Enter deposit amount: ";
    cin >> amt;
    Account_balance += amt;
    cout << "Deposit successful\n";
}

int main() {
    bank_account B[50];
    int choice, account_count = 0;
    double search_id;

options:
    cout << "\n1. Deposit";
    cout << "\n2. Withdraw";
    cout << "\n3. Check Balance";
    cout << "\n4. Create Account";
    cout << "\n5. Exit";
    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {

    case 1: {
        cout << "Enter account number: ";
        cin >> search_id;
        bool found = false;

        for (int i = 0; i < account_count; i++) {
            if (B[i].search_acc(search_id)) {
                B[i].deposit_money();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Invalid Account Number\n";
        goto options;
    }

    case 2: {
        cout << "Enter account number: ";
        cin >> search_id;
        bool found = false;

        for (int i = 0; i < account_count; i++) {
            if (B[i].search_acc(search_id)) {
                B[i].withdraw_money();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Invalid Account Number\n";
        goto options;
    }

    case 3: {
        cout << "Enter account number: ";
        cin >> search_id;
        bool found = false;

        for (int i = 0; i < account_count; i++) {
            if (B[i].search_acc(search_id)) {
                B[i].display_balance();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Invalid Account Number\n";
        goto options;
    }

    case 4:
        if (account_count < 50)
            B[account_count++].create_account();
        else
            cout << "Account limit reached\n";
        goto options;

    case 5:
        cout << "Thank you!\n";
        return 0;

    default:
        cout << "Invalid choice\n";
        goto options;
    }
}

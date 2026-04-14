#include <iostream>
#include <cstring>
using namespace std;

class Account
{
private:
    int accNo;
    char name[50];
    double balance;
    static int totalAccounts;
public:

    Account()
    {
        accNo = 0;
        strcpy(name, "Unknown");
        balance = 0;
        totalAccounts++;
    }

    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accNo;

        cout << "Enter Account Holder Name: ";
        cin >> name;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void display()
    {
        cout << "\nAccount Number: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    int getAccNo()
    {
        return accNo;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    static int getTotalAccounts()
    {
        return totalAccounts;
    }
};

int Account::totalAccounts = 0;

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    Account* acc = new Account[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Account " << i + 1 << ":\n";
        acc[i].createAccount();
    }

    int fromAcc, toAcc;
    double amount;

    cout << "\nEnter Sender Account Number: ";
    cin >> fromAcc;

    cout << "Enter Receiver Account Number: ";
    cin >> toAcc;

    cout << "Enter Amount to Transfer: ";
    cin >> amount;

    int fromIndex = -1, toIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (acc[i].getAccNo() == fromAcc)
            fromIndex = i;
        if (acc[i].getAccNo() == toAcc)
            toIndex = i;
    }

    if (fromIndex == -1 || toIndex == -1)
    {
        cout << "Invalid Account Number!\n";
    }
    else
    {
        if (acc[fromIndex].withdraw(amount))
        {
            acc[toIndex].deposit(amount);
            cout << "Transfer Successful!\n";
        }
    }

    cout << "\n--- Account Summary ---\n";
    for (int i = 0; i < n; i++)
    {
        acc[i].display();
    }

    cout << "\nTotal Accounts Created: " << Account::getTotalAccounts() << endl;

    delete[] acc;

    return 0;
}

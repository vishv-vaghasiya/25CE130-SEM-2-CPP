#include <iostream>
using namespace std;

string logs[100];
int logIndex = 0;

void addLog(string msg)
{
    logs[logIndex++] = msg;
}

class BankAccount
{
    double balance;

public:
    BankAccount(double b = 0)
    {
        balance = b;
    }

    void deposit(double amount)
    {
        addLog("Entered deposit()");
        if (amount <= 0)
            throw "Invalid deposit amount";
        balance += amount;
        addLog("Deposit successful");
        addLog("Exiting deposit()");
    }

    void withdraw(double amount)
    {
        addLog("Entered withdraw()");
        if (amount <= 0)
            throw "Invalid withdraw amount";
        if (amount > balance)
            throw "Insufficient balance";
        balance -= amount;
        addLog("Withdraw successful");
        addLog("Exiting withdraw()");
    }

    double getBalance()
    {
        return balance;
    }
};

void performTransaction(BankAccount &acc)
{
    addLog("Entered performTransaction()");
    acc.deposit(500);
    acc.withdraw(2000);
    addLog("Exiting performTransaction()");
}

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    BankAccount acc(1000);

    try
    {
        addLog("Entered main try block");
        performTransaction(acc);
        addLog("Exiting main try block");
    }
    catch (const char* msg)
    {
        addLog("Exception caught in main");
        cout << "Exception: " << msg << endl;
    }

    cout << "\nTransaction Logs:\n";
    for (int i = 0; i < logIndex; i++)
    {
        cout << logs[i] << endl;
    }

    cout << "\nFinal Balance: " << acc.getBalance() << endl;

    return 0;
}

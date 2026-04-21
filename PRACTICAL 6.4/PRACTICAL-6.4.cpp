#include <iostream>
#include <vector>
using namespace std;

class Account
{
protected:
    int accNo;
    double balance;
    vector<double> transactions;

public:
    Account(int accNo, double balance)
    {
        this->accNo = accNo;
        this->balance = balance;
    }

    virtual ~Account() {}

    void deposit(double amount)
    {
        balance += amount;
        transactions.push_back(amount);
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            transactions.push_back(-amount);
            cout << "Withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }

    void undoTransaction()
    {
        if (!transactions.empty())
        {
            double last = transactions.back();
            transactions.pop_back();
            balance -= last; // reverse effect
            cout << "Last transaction undone!\n";
        }
        else
        {
            cout << "No transaction to undo!\n";
        }
    }

    virtual void display()
    {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account
{
    double interestRate;

public:
    SavingsAccount(int accNo, double balance, double rate)
        : Account(accNo, balance)
    {
        interestRate = rate;
    }

    ~SavingsAccount() {}

    void display() override
    {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CurrentAccount : public Account
{
    double overdraftLimit;

public:
    CurrentAccount(int accNo, double balance, double limit)
        : Account(accNo, balance)
    {
        overdraftLimit = limit;
    }

    ~CurrentAccount() {}

    void withdraw(double amount) override
    {
        if (balance + overdraftLimit >= amount)
        {
            balance -= amount;
            transactions.push_back(-amount);
            cout << "Withdrawn (OD allowed): " << amount << endl;
        }
        else
        {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void display() override
    {
        Account::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main()
{
    SavingsAccount sa(101, 5000, 5.0);
    CurrentAccount ca(102, 2000, 1000);

    cout << "\n--- Savings Account ---\n";
    sa.deposit(1000);
    sa.withdraw(2000);
    sa.display();
    sa.undoTransaction();
    sa.display();

    cout << "\n--- Current Account ---\n";
    ca.deposit(500);
    ca.withdraw(3000);
    ca.display();
    ca.undoTransaction();
    ca.display();

    return 0;
}

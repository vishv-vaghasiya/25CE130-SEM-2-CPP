#include<iostream>
using namespace std;

class bank_account
{
    char Account_Holder_Name[200];
    double Account_number;
    long double Account_balance;

public:
    void creat_account();
    int search_account(double);
    void display_balance();
    void widraw_money();
    void deposite_money();
};

void bank_account :: creat_account()
{
    cin.ignore();
    cout<<"Enter name : ";
    cin.getline(Account_Holder_Name,200);
    cout<<"Enter Account Number : ";
    cin>>Account_number;
    cout<<"Enter Account Balance : ";
    cin>>Account_balance;
}
int bank_account::search_account(double acn)
{
    if(acn==Account_number)
        return 1;
    else
        return 0;
}

void bank_account::deposite_money()
{
    double amount;
    cout<<"Enter amount you want deposite : ";
    cin>>amount;
    Account_balance += amount;
}

void bank_account::widraw_money()
{
    double wamount;
    cout<<"Enter Amount to widraw : ";
    cin>>wamount;
    Account_balance -= wamount;
}

void bank_account::display_balance()
{
    cout<<"Account Balance : "<<Account_balance<<endl;
}

int main()
{
    class bank_account Accounts[15];
    int choice,n=0,i;
    double accountnumber;

options:
    cout<<"1.Deposite money"<<endl<<"2.Withdraw money"<<endl<<"3.Check Balance"<<endl<<"4.Create Account"<<endl<<"5.Exit"<<endl;
    cout<<"Choose any option : ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"Enter Account Number : ";
        cin>>accountnumber;
        for(i=0; i<n; i++)
        {
            if(Accounts[i].search_account(accountnumber)==1)
            {
                Accounts[i].deposite_money();
                break;
            }
        }
        if(i==n)
        {
            cout<<"invalid account number!"<<endl;
        }
        goto options;

    case 2:
        cout<<"Enter Account Number : ";
        cin>>accountnumber;
        for(i=0; i<n; i++)
        {
            if(Accounts[i].search_account(accountnumber)==1)
            {
                Accounts[i].widraw_money();
                break;
            }
        }
        if(i==n)
        {
            cout<<"invalid account number!";
        }
        goto options;

    case 3:

        cout<<"Enter Account Number : ";
        cin>>accountnumber;
        for(i=0; i<n; i++)
        {
            if(Accounts[i].search_account(accountnumber)==1)
            {
                Accounts[i].display_balance();
                break;
            }
        }
        if(i==n)
        {
            cout<<"invalid account number!";
        }
        goto options;

    case 4:
        Accounts[n].creat_account();
        n++;
        goto options;

    case 5:
        cout<<"exiting.....";
        return 0;

    default:
        cout<<"Invalid Choice!";
    }

    return 0;
}

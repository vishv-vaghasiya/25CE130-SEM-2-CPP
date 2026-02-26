#include<iostream>
#include<string>
#include<math.h>

using namespace std;
class bank_loan
{
private:
    double loan_id;
    string applicant_name;
    double loan_amount;
    int loan_tenure;
    int interest_rate;
    double emi;

public:
    bank_loan()
    {
        loan_id = 0;
        applicant_name = "xyz";
        loan_amount = 0.0;
        loan_tenure = 0;
        interest_rate = 0;
        emi = 0.0;
    }
    void create_loan();
    void display_loan_details();
    int search(double);
    void calculate_emi();
};
int bank_loan::search(double search_id)
{
    if (loan_id == search_id)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void bank_loan::calculate_emi()
{
    emi = (loan_amount * interest_rate * pow(1 + interest_rate, loan_tenure)) / (pow(1 + interest_rate, loan_tenure) - 1);
    cout << "EMI: " << emi << endl;
}
void bank_loan::create_loan()
{
    cout << "enter loan id : ";
    cin >> loan_id;
    cout << "enter applicant name : ";
    cin.ignore();
    getline(cin, applicant_name);
    cout << "enter loan amount : ";
    cin >> loan_amount;
    cout << "enter loan tenure (in years) : ";
    cin >> loan_tenure;
    cout << "enter interest rate (in %) : ";
    cin >> interest_rate;
}
void bank_loan::display_loan_details()
{
    cout << "Loan ID: " << loan_id << endl;
    cout << "Applicant Name: " << applicant_name << endl;
    cout << "Loan Amount: " << loan_amount << endl;
    cout << "Loan Tenure: " << loan_tenure << " years" << endl;
    cout << "Interest Rate: " << interest_rate << "%" << endl;
    cout << "EMI: " << emi << endl;
}

int main()
{
    bank_loan b[10];
    int choice, t = 0, i;
    double id;
    do
    {
        cout << "1. Create Loan\n2. Display Loan Details\n3. EMI \n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            b[t].create_loan();
            t++;
            break;

        case 2:
            cout << "enter loan id : ";
            cin >> id;
            for(i = 0; i < t; i++)
            {
                if(b[i].search(id) == 1)
                {
                    b[i].display_loan_details();
                    break;
                }
            }
            if(i == t)
                cout << "loan not found\n";
            break;

        case 3:
            cout << "enter loan id : ";
            cin >> id;
            for(i = 0; i < t; i++)
            {
                if(b[i].search(id) == 1)
                {
                    b[i].calculate_emi();
                    break;
                }
            }
            if(i == t)
                cout << "loan not found\n";
            break;

        case 4:
            return 0;

        default:
            cout << "enter valid choice\n";
            break;
        }
    }
    while(1);
}


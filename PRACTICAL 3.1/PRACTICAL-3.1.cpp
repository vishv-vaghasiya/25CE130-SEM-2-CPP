#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    double basic;
    double bonus;

public:
    Employee()
    {
        name = "";
        basic = 0;
        bonus = 0;
    }

    Employee(string n, double b)
    {
        name = n;
        basic = (b >= 0) ? b : 0;
        bonus = 1000;
    }

    Employee(string n, double b, double bon)
    {
        name = n;
        basic = (b >= 0) ? b : 0;
        bonus = (bon >= 0) ? bon : 0;
    }

    inline double totalSalary()
    {
        return basic + bonus;
    }

    void updateBonus(double bon)
    {
        if (bon >= 0)
            bonus = bon;
        else
            cout << "Invalid bonus!\n";
    }

    string grade()
    {
        double total = totalSalary();
        if (total >= 50000)
            return "A";
        else if (total >= 30000)
            return "B";
        else
            return "C";
    }

    void display()
    {
        cout << "\nName: " << name;
        cout << "\nBasic Salary: " << basic;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << totalSalary();
        cout << "\nGrade: " << grade() << endl;
    }
};

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    Employee* emp = new Employee[n];

    for (int i = 0; i < n; i++)
    {
        string name;
        double basic, bonus;
        int choice;

        cout << "\nEmployee " << i + 1;

        cout << "\nEnter name: ";
        cin >> name;

        cout << "Enter basic salary: ";
        cin >> basic;

        cout << "1. Default Bonus\n2. Custom Bonus\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            emp[i] = Employee(name, basic);
        }
        else
        {
            cout << "Enter bonus: ";
            cin >> bonus;
            emp[i] = Employee(name, basic, bonus);
        }
    }

    cout << "\n--- Employee Details ---\n";
    for (int i = 0; i < n; i++)
    {
        emp[i].display();
    }

    delete[] emp;

    return 0;
}

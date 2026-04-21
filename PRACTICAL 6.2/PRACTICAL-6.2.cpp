#include <iostream>
#include <vector>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:

    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};


class Employee : public Person
{
protected:
    int empID;

public:

    Employee(string n, int a, int id) : Person(n, a)
    {
        empID = id;
    }

    void displayEmployee()
    {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }

    int getID()
    {
        return empID;
    }
};

class Manager : public Employee
{
private:
    string department;

public:

    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id)
    {
        department = dept;
    }

    void displayManager()
    {
        displayEmployee();
        cout << "Department: " << department << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n";

    vector<Manager> managers;

    int choice;

    do
    {
        cout << "\n1. Add Manager\n2. View All Managers\n3. Search by ID\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name, dept;
            int age, id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Employee ID: ";
            cin >> id;

            cout << "Enter Department: ";
            cin >> dept;

            managers.push_back(Manager(name, age, id, dept));
        }

        else if (choice == 2)
        {
            for (auto &m : managers)
            {
                m.displayManager();
            }
        }

        else if (choice == 3)
        {
            int searchID;
            cout << "Enter ID to search: ";
            cin >> searchID;

            bool found = false;
            for (auto &m : managers)
            {
                if (m.getID() == searchID)
                {
                    m.displayManager();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Manager not found!\n";
            }
        }

    }
    while (choice != 4);

    return 0;
}

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Student
{
    string name;
    int marks;
    double fees;
};

ostream& currency(ostream& output)
{
    output << "₹ ";
    return output;
}

int main()
{
    vector<Student> students =
    {
        {"Amit", 85, 15000.5},
        {"Neha", 92, 17500.75},
        {"Raj", 78, 14000.0},
        {"Priya", 88, 16000.25}
    };

    cout << setfill('=') << setw(45) << "=" << endl;
    cout << setfill(' ')
         << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(20) << "Fees" << endl;
    cout << setfill('-') << setw(45) << "-" << endl;

    for (const auto& s : students)
    {
        cout << setfill(' ')
             << left << setw(15) << s.name
             << setw(10) << s.marks
             << currency << fixed << setprecision(2)
             << s.fees << endl;
    }

    cout << setfill('=') << setw(45) << "=" << endl;

    return 0;
}

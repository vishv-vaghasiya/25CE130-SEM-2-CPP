#include <iostream>
#include <vector>
using namespace std;

class GradingSystem
{
protected:
    double marks;

public:
    GradingSystem(double m) : marks(m) {}

    virtual string computeGrade() = 0;
    virtual void display() = 0;

    virtual ~GradingSystem() {}
};

class Undergraduate : public GradingSystem
{
public:
    Undergraduate(double m) : GradingSystem(m) {}

    string computeGrade()
    {
        if (marks >= 85) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 50) return "C";
        else return "Fail";
    }

    void display()
    {
        cout << "Undergraduate Marks: " << marks
             << " | Grade: " << computeGrade() << endl;
    }
};

class Postgraduate : public GradingSystem
{
public:
    Postgraduate(double m) : GradingSystem(m) {}

    string computeGrade()
    {
        if (marks >= 90) return "A";
        else if (marks >= 75) return "B";
        else if (marks >= 60) return "C";
        else return "Fail";
    }

    void display()
    {
        cout << "Postgraduate Marks: " << marks
             << " | Grade: " << computeGrade() << endl;
    }
};

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    vector<GradingSystem*> students;

    students.push_back(new Undergraduate(82));
    students.push_back(new Undergraduate(45));
    students.push_back(new Postgraduate(88));
    students.push_back(new Postgraduate(55));

    cout << "Student Grade Report:\n";

    for (GradingSystem* s : students)
    {
        s->display();
    }

    for (GradingSystem* s : students)
    {
        delete s;
    }

    return 0;
}

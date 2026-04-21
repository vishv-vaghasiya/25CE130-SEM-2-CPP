#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Shape
{
protected:
    double radius;

public:
    void setRadius(double r)
    {
        if (r > 0)
            radius = r;
        else
        {
            cout << "Invalid radius! Setting to 1.\n";
            radius = 1;
        }
    }

    double getRadius() const
    {
        return radius;
    }
};

class Circle : public Shape
{
public:
    double getArea() const
    {
        return 3.14159 * radius * radius;
    }
};

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    int n;

    cout << "Enter number of circles: ";
    cin >> n;

    cout << "\n--- Static Method (Array) ---\n";

    Circle staticCircles[100]; // fixed size array

    for (int i = 0; i < n; i++)
    {
        double r;
        cout << "Enter radius of circle " << i + 1 << ": ";
        cin >> r;
        staticCircles[i].setRadius(r);
    }

    cout << "\nAreas (Static Array):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Circle " << i + 1
             << " (Radius = " << staticCircles[i].getRadius() << ") -> Area = "
             << fixed << setprecision(2)
             << staticCircles[i].getArea() << endl;
    }

    cout << "\n--- Dynamic Method (Vector) ---\n";

    vector<Circle> dynamicCircles;

    for (int i = 0; i < n; i++)
    {
        Circle c;
        double r;
        cout << "Enter radius of circle " << i + 1 << ": ";
        cin >> r;
        c.setRadius(r);
        dynamicCircles.push_back(c);
    }

    cout << "\nAreas (Dynamic Vector):\n";
    for (int i = 0; i < dynamicCircles.size(); i++)
    {
        cout << "Circle " << i + 1
             << " (Radius = " << dynamicCircles[i].getRadius() << ") -> Area = "
             << fixed << setprecision(2)
             << dynamicCircles[i].getArea() << endl;
    }

    return 0;
}

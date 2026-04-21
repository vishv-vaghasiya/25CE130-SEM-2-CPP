#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area()
    {
        return length * width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area()
    {
        return 3.14159 * radius * radius;
    }
};

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5, 3));
    shapes.push_back(new Circle(2.5));
    shapes.push_back(new Rectangle(4, 6));

    cout << "Dynamic Storage (Polymorphism):\n";
    for (Shape* s : shapes)
    {
        cout << "Area: " << s->area() << endl;
    }

    for (Shape* s : shapes)
    {
        delete s;
    }

    Shape* arr[3];
    arr[0] = new Rectangle(2, 7);
    arr[1] = new Circle(3);
    arr[2] = new Rectangle(3, 3);

    cout << "\nStatic Storage (Array):\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Area: " << arr[i]->area() << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete arr[i];
    }

    return 0;
}

#include<iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }

    Point& move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
        return *this;
    }

    void show()
    {
        cout << "Point is: (" << x << ", " << y << ")" << endl;
    }
};

void change(Point *p, int dx, int dy)
{
    p->move(dx, dy);
}

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    Point p(1, 2);

    cout << "Initial: ";
    p.show();

    p.move(2, 3).move(-1, 4);

    cout << "After move: ";
    p.show();

    change(&p, 5, -2);

    cout << "After change: ";
    p.show();

    return 0;
}

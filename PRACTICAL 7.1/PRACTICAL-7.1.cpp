#include <iostream>
using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    double add(int a, double b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    Calculator calc;

    int result1 = calc.add(10, 20);
    double result2 = calc.add(5.5, 4.5);
    double result3 = calc.add(10, 3.75);
    int result4 = calc.add(1, 2, 3);

    cout << "Addition of two integers: " << result1 << endl;
    cout << "Addition of two doubles: " << result2 << endl;
    cout << "Addition of int and double: " << result3 << endl;
    cout << "Addition of three integers: " << result4 << endl;

    return 0;
}

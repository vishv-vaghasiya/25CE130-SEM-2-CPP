#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException
{
public:
    void message()
    {
        cout << "Error: Negative number entered, cannot compute square root\n";
    }
};

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    double num;

    cout << "Enter a number: ";
    cin >> num;

    try
    {
        if (num < 0)
            throw NegativeNumberException();

        cout << "Square root: " << sqrt(num) << endl;
    }
    catch (NegativeNumberException e)
    {
        e.message();
    }

    return 0;
}

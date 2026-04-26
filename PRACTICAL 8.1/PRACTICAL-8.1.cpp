#include <iostream>
using namespace std;

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    int a, b;

    try
    {
        cout << "Enter numerator: ";
        if (!(cin >> a))
            throw "Invalid input for numerator";

        cout << "Enter denominator: ";
        if (!(cin >> b))
            throw "Invalid input for denominator";

        if (b == 0)
            throw "Division by zero error";

        cout << "Result: " << (a / b) << endl;
    }
    catch (const char* msg)
    {
        cout << "Error: " << msg << endl;
    }

    return 0;
}

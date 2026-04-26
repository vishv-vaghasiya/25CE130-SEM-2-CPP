#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "Base Destructor Called\n";
    }
};

class Derived : public Base
{
    int* data;

public:
    Derived()
    {
        data = new int[5];
        cout << "Derived Constructor Allocates Memory\n";
    }

    ~Derived()
    {
        delete[] data;
        cout << "Derived Destructor Called (Memory Freed)\n";
    }
};

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    Base* ptr = new Derived();
    delete ptr;
    return 0;
}

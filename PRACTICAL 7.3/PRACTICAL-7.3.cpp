#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;

class Celsius
{
private:
    double temp;

public:
    Celsius(double t = 0) : temp(t) {}

    double getTemp() const
    {
        return temp;
    }


    operator Fahrenheit();


    bool operator==(const Celsius& obj)
    {
        return temp == obj.temp;
    }
};

class Fahrenheit
{
private:
    double temp;

public:
    Fahrenheit(double t = 0) : temp(t) {}

    double getTemp() const
    {
        return temp;
    }

    operator Celsius()
    {
        return Celsius((temp - 32) * 5 / 9);
    }

    bool operator==(const Fahrenheit& obj)
    {
        return temp == obj.temp;
    }
};

Celsius::operator Fahrenheit()
{
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;
    cout << "25 Celsius = " << f1.getTemp() << " Fahrenheit" << endl;

    Fahrenheit f2(77);
    Celsius c2;

    c2 = f2;
    cout << "77 Fahrenheit = " << c2.getTemp() << " Celsius" << endl;

    Celsius c3(25);
    if (c1 == c3)
        cout << "Celsius values are equal" << endl;

    queue<Celsius> cQueue;
    cQueue.push(Celsius(10));
    cQueue.push(Celsius(20));
    cQueue.push(Celsius(30));

    cout << "\nQueue Processing (Celsius → Fahrenheit):\n";
    while (!cQueue.empty())
    {
        Fahrenheit tempF = cQueue.front();
        cout << tempF.getTemp() << " F" << endl;
        cQueue.pop();
    }

    Celsius cArray[3] = {Celsius(0), Celsius(100), Celsius(37)};

    cout << "\nArray Conversion (Celsius → Fahrenheit):\n";
    for (int i = 0; i < 3; i++)
    {
        Fahrenheit tempF = cArray[i];
        cout << tempF.getTemp() << " F" << endl;
    }

    return 0;
}

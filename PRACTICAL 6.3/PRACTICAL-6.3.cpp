#include <iostream>
#include <queue>
using namespace std;

class Fuel
{
protected:
    string fuelType;

public:
    Fuel(string f)
    {
        fuelType = f;
    }
};

class Brand
{
protected:
    string brandName;

public:
    Brand(string b)
    {
        brandName = b;
    }
};

class Car : public Fuel, public Brand
{
public:
    Car(string f, string b) : Fuel(f), Brand(b) {}

    void display()
    {
        cout << "Brand: " << brandName << ", Fuel Type: " << fuelType << endl;
    }
};


void processUsingQueue()
{
    queue<Car> q;

    q.push(Car("Petrol", "Toyota"));
    q.push(Car("Diesel", "Mahindra"));
    q.push(Car("Electric", "Tesla"));

    cout << "\nProcessing using Queue (FIFO):\n";

    while (!q.empty())
    {
        q.front().display();
        q.pop();
    }
}

void processUsingArray()
{
    Car cars[] =
    {
        Car("Petrol", "Hyundai"),
        Car("Diesel", "Tata"),
        Car("Electric", "BYD")
    };

    cout << "\nProcessing using Static Array:\n";

    for (int i = 0; i < 3; i++)
    {
        cars[i].display();
    }
}


int main()
{
    processUsingQueue();
    processUsingArray();
    return 0;
}

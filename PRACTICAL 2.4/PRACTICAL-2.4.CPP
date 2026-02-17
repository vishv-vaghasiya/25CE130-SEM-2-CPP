#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    int itemID;
    string itemName;
    float price;
    int quantity;

public:

    Item()
    {
        itemID = 0;
        itemName = "Unknown";
        price = 0.0;
        quantity = 0;
    }

    Item(int id, string name, float p, int qty)
    {
        itemID = id;
        itemName = name;
        price = p;
        quantity = qty;
    }

    void addStock(int qty)
    {
        if (qty > 0)
        {
            quantity += qty;
            cout << qty << " stock added successfully!\n";
        }
        else
        {
            cout << "Invalid stock quantity!\n";
        }
    }

    void sellItem(int qty)
    {
        if (qty <= 0)
        {
            cout << "Invalid quantity to sell!\n";
        }
        else if (qty > quantity)
        {
            cout << "Not enough stock available!\n";
        }
        else
        {
            quantity -= qty;
            cout << qty << " item(s) sold successfully!\n";
        }
    }

    void display()
    {
        cout << "\n--------------------------\n";
        cout << "Item ID   : " << itemID << endl;
        cout << "Item Name : " << itemName << endl;
        cout << "Price     : " << price << endl;
        cout << "Quantity  : " << quantity << endl;
        cout << "--------------------------\n";
    }
};

int main()
{
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    for (int i = 0; i < n; i++)
    {
        int id, qty;
        string name;
        float price;

        cout << "\nEnter details for Item " << i + 1 << ":\n";
        cout << "Enter Item ID: ";
        cin >> id;

        cout << "Enter Item Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> qty;

        items[i] = Item(id, name, price, qty);
    }

    int choice, index, qty;

    do
    {
        cout << "\n===== INVENTORY MANAGEMENT MENU =====\n";
        cout << "1. Display All Items\n";
        cout << "2. Add Stock\n";
        cout << "3. Sell Item\n";
        cout << "4. Display Single Item\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                items[i].display();
            }
            break;

        case 2:
            cout << "Enter item number (1 to " << n << "): ";
            cin >> index;

            if (index >= 1 && index <= n)
            {
                cout << "Enter quantity to add: ";
                cin >> qty;
                items[index - 1].addStock(qty);
            }
            else
            {
                cout << "Invalid item number!\n";
            }
            break;

        case 3:
            cout << "Enter item number (1 to " << n << "): ";
            cin >> index;

            if (index >= 1 && index <= n)
            {
                cout << "Enter quantity to sell: ";
                cin >> qty;
                items[index - 1].sellItem(qty);
            }
            else
            {
                cout << "Invalid item number!\n";
            }
            break;

        case 4:
            cout << "Enter item number (1 to " << n << "): ";
            cin >> index;

            if (index >= 1 && index <= n)
            {
                items[index - 1].display();
            }
            else
            {
                cout << "Invalid item number!\n";
            }
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    }
    while (choice != 5);

    return 0;
}

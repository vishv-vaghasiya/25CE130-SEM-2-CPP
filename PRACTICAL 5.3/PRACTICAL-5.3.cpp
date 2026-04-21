#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int choice;
    string name, search;
    int quantity;
    float price;
    bool found;

    do
    {
        cout<<"\n--- MENU ---\n";
        cout<<"1. Add Item\n";
        cout<<"2. View Items\n";
        cout<<"3. Search Item\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice == 1)
        {
            ofstream file("inventory.txt", ios::app);

            cout<<"Enter item name: ";
            cin>>name;
            cout<<"Enter quantity: ";
            cin>>quantity;
            cout<<"Enter price: ";
            cin>>price;

            file<<name<<" "<<quantity<<" "<<price<<endl;
            file.close();

            cout<<"Item added successfully!\n";
        }

        else if(choice == 2)
        {
            ifstream file("inventory.txt");

            cout<<"\n--- Inventory ---\n";
            while(file>>name>>quantity>>price)
            {
                cout<<"Name: "<<name
                    <<" Quantity: "<<quantity
                    <<" Price: "<<price<<endl;
            }

            file.close();
        }

        else if(choice == 3)
        {
            ifstream file("inventory.txt");

            cout<<"Enter item name to search: ";
            cin>>search;

            found = false;

            while(file>>name>>quantity>>price)
            {
                if(name == search)
                {
                    cout<<"Item Found:\n";
                    cout<<"Name: "<<name
                        <<" Quantity: "<<quantity
                        <<" Price: "<<price<<endl;
                    found = true;
                }
            }

            if(!found)
                cout<<"Item not found!\n";

            file.close();
        }

    } while(choice != 4);

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n";

    int *arr = NULL;
    int size = 0;
    int choice, value, pos;

    do
    {
        cout << "\n--- Dynamic Array Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display Array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;


            {
                int *newArr = new int[size + 1];


                for(int i = 0; i < size; i++)
                {
                    newArr[i] = arr[i];
                }


                newArr[size] = value;


                delete[] arr;


                arr = newArr;
                size++;

                cout << "Element inserted successfully.\n";
            }
            break;

        case 2:
            if(size == 0)
            {
                cout << "Array is empty.\n";
                break;
            }

            cout << "Enter position to delete (0 to " << size-1 << "): ";
            cin >> pos;

            if(pos < 0 || pos >= size)
            {
                cout << "Invalid position!\n";
                break;
            }

            {
                int *newArr = new int[size - 1];


                for(int i = 0, j = 0; i < size; i++)
                {
                    if(i != pos)
                    {
                        newArr[j++] = arr[i];
                    }
                }

                delete[] arr;
                arr = newArr;
                size--;

                cout << "Element deleted successfully.\n";
            }
            break;

        case 3:
            if(size == 0)
            {
                cout << "Array is empty.\n";
            }
            else
            {
                cout << "Array elements: ";
                for(int i = 0; i < size; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    }
    while(choice != 4);


    delete[] arr;

    return 0;
}

#include <iostream>
using namespace std;

template <typename T>
void display(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
T findMax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

template <typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

template <typename T>
void findLeaders(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        bool isLeader = true;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[i]) {
                isLeader = false;
                break;
            }
        }

        if (isLeader) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int choice, size;

    cout << "Select data type:\n1. Integer\n2. Float\n3. Character\nEnter choice: ";
    cin >> choice;

    cout << "Enter size of array: ";
    cin >> size;

    if (choice == 1) {
        int arr[100];
        cout << "Enter elements:\n";
        for (int i = 0; i < size; i++) cin >> arr[i];

        display(arr, size);
        cout << findMax(arr, size) << endl;
        reverseArray(arr, size);
        display(arr, size);
        findLeaders(arr, size);
    }

    else if (choice == 2) {
        float arr[100];
        cout << "Enter elements:\n";
        for (int i = 0; i < size; i++) cin >> arr[i];

        display(arr, size);
        cout << findMax(arr, size) << endl;
        reverseArray(arr, size);
        display(arr, size);
        findLeaders(arr, size);
    }

    else if (choice == 3) {
        char arr[100];
        cout << "Enter elements:\n";
        for (int i = 0; i < size; i++) cin >> arr[i];

        display(arr, size);
        cout << findMax(arr, size) << endl;
        reverseArray(arr, size);
        display(arr, size);
        findLeaders(arr, size);
    }

    else {
        cout << "Invalid choice";
    }

    return 0;
}

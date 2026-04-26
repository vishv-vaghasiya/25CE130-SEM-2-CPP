#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    set<int> s;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }

    cout << "\nUnique elements (sorted) using iterators:\n";
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v(s.begin(), s.end());

    cout << "\nConverted to vector:\n";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

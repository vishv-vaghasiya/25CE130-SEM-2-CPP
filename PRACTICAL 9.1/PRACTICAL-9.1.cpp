#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    vector<int> v;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    cout << "\nOriginal Vector:\n";
    display(v);

    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());

    cout << "\nReversed using std::reverse():\n";
    display(v1);

    vector<int> v2 = v;
    vector<int>::iterator start = v2.begin();
    vector<int>::iterator end = v2.end() - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }

    cout << "\nReversed manually using iterators:\n";
    display(v2);

    return 0;
}

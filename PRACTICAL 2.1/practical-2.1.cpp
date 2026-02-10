#include<iostream>
#include<string>

using namespace std;

class rect
{

private :
    float len ;
    float wid;

public :
    rect()
    {
        len=0;
        wid=0;
    }
    rect(float l, float w)
    {
        len = l;
        wid = w;
    }

    void set(float l, float w)
    {
        len = l;
        wid = w;
    }

    float area()
    {
        return len * wid;
    }

    float perimeter()
    {
        return 2 * (len + wid);
    }
    void display()
    {

        cout<<"\n Length   :"<<len;
        cout<<"\n Width    :"<<wid;
        cout<<"\n Area     :"<<area();
        cout<<"\n Permeter :"<<perimeter();
    }

};
int main()
{

    int n;
    cout<<"\nEnter number of rectangles : ";
    cin>>n;

    rect r[100];
    for (int i = 0; i < n; i++)
    {
        float l, w;
        cout << "\n Enter dimensions for Rectangle : " << i + 1 << endl;
        cout << " Length : ";
        cin >> l;
        cout << " Width : ";
        cin >> w;

        r[i].set(l, w);
    }

    cout << " \nDetails :\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n Rectangle :" << i + 1;
        r[i].display();
    }

    return 0;
}

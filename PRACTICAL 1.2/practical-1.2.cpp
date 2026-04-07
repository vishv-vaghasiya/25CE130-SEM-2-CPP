#include <iostream>
using namespace std;

class library
{
    int book_id;
    char book_title[100];
    char book_author[100];
    int NoOfCopies;

public:
    void addBook();
    void issueBook();
    void returnBook();
    void displayBook();
};

void library :: addBook()
{
    cout<<"Enter Book ID : ";
    cin>>book_id;
    cout<<"Enter Book Name : ";
    fflush(stdin);
    cin.getline(book_title,100);
    cout<<"Enter Book Author Name : ";
    cin.getline(book_author,100);
    cout<<"Enter Book Quantity : ";
    cin>>NoOfCopies;
}

void library ::issueBook()
{
    if(NoOfCopies>0)
    {
        NoOfCopies--;
        cout<<"Book sucessfully issued!"<<endl;
    }

    else
    {
        cout<<"Sorry Book is not available"<<endl;
    }
}

void library ::returnBook()
{
    NoOfCopies++;
    cout<<"Book sucessfully returned!"<<endl;
}

void library::displayBook()
{
    cout<<"Book Name : "<<book_title<<endl;
    cout<<"Book ID : "<<book_id<<endl;
    cout<<"Book Author : "<<book_author<<endl;
    cout<<"No. Of Copies Available : "<<NoOfCopies<<endl;
}
int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130";

    int n;
    library book1;
menu:
    cout<<endl<<endl<<"1.Add Book"<<endl<<"2.Issue book"<<endl<<"3.Return Book"<<endl<<"4.Display Book"<<endl<<"5.Exit Programm"<<endl;
    cout<<"Enter Your choice : ";
    cin>>n;

    switch(n)
    {
    case 1:
        book1.addBook();
        goto menu;

    case 2:
        book1.issueBook();
        goto menu;

    case 3:
        book1.returnBook();
        goto menu;

    case 4:
        book1.displayBook();
        goto menu;

    case 5:
        cout<<"Exiting......";
        return 0;
    }
    return 0;
}

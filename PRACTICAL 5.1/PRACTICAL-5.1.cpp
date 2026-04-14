#include <iostream>
#include <string>
using namespace std;

class WordFrequency
{
private:
    string paragraph;
    string words[100];
    int freq[100];
    int count;

public:

    WordFrequency()
    {
        count = 0;
    }


    void inputParagraph()
    {
        cout << "Enter a paragraph:\n";
        getline(cin, paragraph);
    }


    string toLowerCase(string str)
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + 32;
            }
        }
        return str;
    }


    void countWords()
    {
        string temp = "";

        for (int i = 0; i <= paragraph.length(); i++)
        {
            if (paragraph[i] == ' ' || paragraph[i] == '\0')
            {

                if (temp != "")
                {
                    temp = toLowerCase(temp);

                    int found = 0;

                    for (int j = 0; j < count; j++)
                    {
                        if (words[j] == temp)
                        {
                            freq[j]++;
                            found = 1;
                            break;
                        }
                    }

                    if (found == 0)
                    {
                        words[count] = temp;
                        freq[count] = 1;
                        count++;
                    }

                    temp = "";
                }
            }
            else
            {
                temp += paragraph[i];
            }
        }
    }


    void display()
    {
        cout << "\nWord Frequencies:\n";
        for (int i = 0; i < count; i++)
        {
            cout << words[i] << " : " << freq[i] << endl;
        }
    }
};

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    WordFrequency obj;

    obj.inputParagraph();
    obj.countWords();
    obj.display();

    return 0;
}

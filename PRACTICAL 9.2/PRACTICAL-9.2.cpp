#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    string sentence, word;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    map<string, int> freq;

    stringstream ss(sentence);

    while (ss >> word)
    {
        freq[word]++;
    }

    cout << "\nWord Frequencies:\n";
    for (map<string, int>::iterator it = freq.begin(); it != freq.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}

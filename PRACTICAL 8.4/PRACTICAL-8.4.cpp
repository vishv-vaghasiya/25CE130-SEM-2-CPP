#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    cout<<"NAME :-VISHV VAGHASIYA\n";
    cout<<"ID NO:-25CE130\n\n";

    string filename;

    while (true)
    {
        cout << "Enter file path (or type exit): ";
        cin >> filename;

        if (filename == "exit")
            return 0;

        ifstream file(filename);

        if (!file)
        {
            cout << "Error: File cannot be opened. Try again.\n";
            continue;
        }

        cout << "\nProcessing file...\n";

        string line;
        int lineNumber = 0;

        while (getline(file, line))
        {
            lineNumber++;

            stringstream ss(line);
            double num, sum = 0;
            int count = 0;
            bool valid = true;

            while (ss >> num)
            {
                sum += num;
                count++;
            }

            if (!ss.eof())
            {
                valid = false;
            }

            if (valid && count > 0)
            {
                cout << "Line " << lineNumber
                     << " -> Sum: " << sum
                     << ", Avg: " << (sum / count) << endl;
            }
            else
            {
                cout << "Line " << lineNumber
                     << " -> Invalid data, skipped\n";
            }
        }

        file.close();
        break;
    }

    return 0;
}

//Dabin Jang
//djang12@bu.edu

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int StringSearch(string, string);

int main(int argv, char **argc)
{
    int number = StringSearch(argc[1], argc[2] /*"Textfile.txt", "file "*/); //argc[1] reads file name argc[1]+1 reads string
    cout << "Number of occurences is " << number << ".\n";
}

int StringSearch(string filename, string pattern)
{
    int count = 0;               //used to count number of occurences of the string pattern
    string line;                 //used to read lines from text file
    ifstream file(filename); // open ifstream
    if (file.good())
    {
        while (getline(file, line).good())
        {

            size_t occurence = line.find(pattern); //returns first occruence of string pattern in line
            while (occurence != string::npos)      //while loop used to recurringly find more occurneces
            {                                      //by continuing to split string after finding occurence
                count++;
                line = line.substr(occurence + pattern.length(), line.length());
                occurence = line.find(pattern);
            }
        }
        file.close();
    }
    return count;
}


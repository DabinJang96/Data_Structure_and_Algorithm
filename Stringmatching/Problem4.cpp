#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include <cctype>
#include <algorithm>

using namespace std;

//below is a function that will take take a line, then return a vector of substrings of the line with a 
//delimiter of a white space in that specific line
vector<string> string_split(const string& line) {
	vector<string> vector_of_words;
	istringstream word(line);
	for (string each_word; word >> each_word;)
	{
		vector_of_words.push_back(each_word);
	}
	return vector_of_words;
}

int fourA(){
	char character;
	int len = 0;
    int max = 0;
	ifstream openfile ("BigData.txt");
	if(openfile.is_open()) // checks if the file is open
    {	
        while (!openfile.eof()) // iterates through the file until it reaches the end
        {
            openfile.get(character);
            if (character != ' ' && character != '\t' && character != '\n')
            {
                len++;
            }
            else
            {
                if(max < len)
                {
                    max = len;
                    len = 0;
                }
                else
                {
                    len = 0;
                }
            }
        }
    } 
    else 
    {
		cout << "error: file not open" << '\n';
	}
	return max;
}

int fourB()
{
	fstream myfile;
	string line;
	int counter = 0;
	myfile.open("TinyData.txt", fstream::in);
	while(myfile.is_open())
	{
		getline(myfile,line);
		//cout<< '\n' << line << endl;
		if (myfile.eof()) {myfile.close();}

		vector <string> split_strings = string_split(line);
		int numel = split_strings.size();
		for(int i = 0; i < numel ; i++)
		{
			string word = split_strings[i];
			//counter++; //check how many words there are
			//cout << '\n' << word << endl; // used to check if words from "line" are printing out correctly
			if(any_of(word.begin(), word.end(), ::isdigit) && 
				any_of(word.begin(), word.end(), ::islower) && 
				any_of(word.begin(), word.end(), ::isupper) && 
				(word.length() >= 8) && (word.length() <= 20) )
			{
				counter++;
			}
		}
	}
	return counter;
}

class Node {
public:
    Node() { 
        mContent = ' '; 
        mMarker = false; 
    }
    ~Node();
    char content(){ 
        return mContent; 
    }
    void setContent(char c) { 
        mContent = c; 
    }
    bool wordMarker() { 
        return mMarker; 
    }
    void setWordMarker() {
        mMarker = true; 
    }
    Node* findChild(char c);
    void appendChild(Node* child) { 
        mChildren.push_back(child); 
    }
    vector<Node*> children() {
        return mChildren; 
    }

private:
    char mContent;
    bool mMarker;
    vector<Node*> mChildren;
};

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    int searchWord(string s);
    void deleteWord(string s);
private:
    Node* root;
};

Node* Node::findChild(char c)
{
    for(int i = 0; i < mChildren.size(); i++){
        Node* tmp = mChildren.at(i);
        if(tmp->content() == c){
            return tmp;
        }
    }
    return NULL;
}

Trie::Trie(){
    root = new Node();
}

Trie::~Trie(){
    // Free memory
}

void Trie::addWord(string s){
    Node* current = root;

    if(s.length() == 0){
        current->setWordMarker(); // an empty word
        return;
    }

    for(int i = 0; i < s.length(); i++){        
        Node* child = current->findChild(s[i]);
        if(child != NULL){
            current = child;
        }
        else{
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 ){
            current->setWordMarker();
        }
    }
}


int Trie::searchWord(string s){
    Node* current = root;

    while(current != NULL){
        for(int i = 0; i < s.length(); i++){
            Node* tmp = current->findChild(s[i]);
            if (tmp == NULL){
                return 1;
            }
            current = tmp;
        }

        if(current->wordMarker()){
            return 2;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int fourC(){
    Trie* trie = new Trie();
    string line;

    char first_letter = 'C';
    char second_letter = 'S';
    char third_letter = 'B';
    ifstream dictionary("dictionary.txt");
    while(getline(dictionary, line)){
        for(int i = 0; i < line.length(); i++){
            if(line[i] == first_letter || line[i] == (first_letter + 32)){
                continue;
            }
            if(line[i] == second_letter || line[i] == (second_letter + 32)){
                continue;
            }
            if(line[i] == third_letter || line[i] == (third_letter + 32)){
                continue;
            }
            else{
                trie -> addWord(line);
            }
        }
    }
    dictionary.close();

    int num_of_words = 0;
    ifstream data("BigData.txt");
    while(getline(data, line, ' ')){
        
	// starting from the start of your string text, you iterate through to find any word
        for(int i = 0; i < line.length(); i++){
		    // this for loop allows you to make substrings 
            for(int j = 1; j < line.length() - i + 1; j++){
                string testing = line.substr(i,j);

                int number = trie->searchWord(testing);
		        // number equals 2 when 
                if(number == 2){
		            num_of_words++;  
                } 
                else if(number == 1){
                    break;
                }
            }
        }
    }
    delete trie;
    return num_of_words;
}



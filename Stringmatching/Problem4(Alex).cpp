#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

std::vector<std::string> string_split(const std::string& line);

int fourA()
{
	fstream myfile;
	string line;
	int longest = 0;
	myfile.open("BigData.txt", fstream::in);
	while(myfile.is_open())
	{
		getline(myfile,line);
		//cout<< '\n' << line << endl;
		if (myfile.eof()) {myfile.close();}
		
		vector <std::string> split_strings = string_split(line);
		int numel = split_strings.size();
		for(int i = 0; i < numel ; i++)
		{
			string word = split_strings[i];
			//cout << '\n' << word << endl; // used to check if words from "line" are printing out correctly
			if (word.length() > longest)
			{
				longest = word.length();
			}
		}
	}
	return longest;
}


// int fourB()
// {
// 	fstream myfile;
// 	string line;
// 	int counter = 0;
// 	myfile.open("TinyData.txt", fstream::in);
// 	while(myfile.is_open())
// 	{
// 		getline(myfile,line);
// 		//cout<< '\n' << line << endl;
// 		if (myfile.eof()) {myfile.close();}

// 		vector <std::string> split_strings = string_split(line);
// 		int numel = split_strings.size();
// 		for(int i = 0; i < numel ; i++)
// 		{
// 			string word = split_strings[i];
// 			//counter++; //check how many words there are
// 			//cout << '\n' << word << endl; // used to check if words from "line" are printing out correctly
// 			if(std::any_of(word.begin(), word.end(), ::isdigit) && 
// 				std::any_of(word.begin(), word.end(), ::islower) && 
// 				std::any_of(word.begin(), word.end(), ::isupper) && 
// 				(word.length() >= 8) && (word.length() <= 20) )
// 			{
// 				counter++;
// 			}
// 		}
// 	}
// 	return counter;
// }


// int fourC()
// {
// 	//first you want to organize unordered map
// 	//first key --> (type:string )the word from dictionary.txt , second key --> (type:int) 1 for valid, 0 for invalid

// 	/* traverse dictionary and make an unordered map */
// 	fstream myfile;
// 	fstream randomfile;
// 	string dictionary_word;
// 	unordered_map<string, int> correct_map;

// 	int dis = 0;

// 	myfile.open("dictionary.txt",fstream::in);

// 	//below will separate valid and invalid words: 7 words cannot have combination of {b,o,r,B,O,R}
// 	while(myfile.is_open())
// 	{
// 		getline(myfile,dictionary_word);
// 		if (myfile.eof()) {myfile.close();}

// 		//if (dictionary_word.find_first_of("bB") != std::string::npos &&
// 		//	dictionary_word.find_first_of("oO") != std::string::npos &&
// 		//	dictionary_word.find_first_of("rR") != std::string::npos) {
// 		//	correctword_map[dictionary_word] = 0;
// 		}
// 		//else {
// 		//	correctword_map[dictionary_word] = 1;
// 		//}
// 	}

// 	randomfile.open("BigData.txt",fstream::in);
// 	randomfile.close();
// 	//now we will find dictionary words
// 	return dis;

// }



//below is a function that will take take a line, then return a vector of substrings of the line with a 
// delimiter of a white space in that specific line
std::vector<std::string> string_split(const std::string& line) {
	std::vector<std::string> vector_of_words;
	std::istringstream word(line);
	for (std::string each_word; word >> each_word;)
	{
		vector_of_words.push_back(each_word);
	}
	return vector_of_words;
}

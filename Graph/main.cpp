//Alex Lee alee23@bu.edu
//Collaborators: Dabin Jang djang12@bu.edu

#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Undir_Graph{
public:
	Undir_Graph(const char*);
	void distThreeNeighbors(string);

private: 
	map <string,list<string>*> graphAdjList;
	int numvertex;
	int numedge;
	void add_allneighbors(list<string>* list1, list<string>* list2, list<string>* list3, list<string>* totallist);
};

int main(int argc, const char* argv[]){
	//takes in arguements: 1) filename   2) vertext name
	//if not then
	if (argc != 3){
        cout << "Please supply a filename AND vertex name\n";
        return 0;
	}
	
	//make Undir_Graph
	Undir_Graph graph(argv[1]); 
	string vertex;
	vertex = std::string(argv[2]);
	//cout<< vertex << endl;

	//call function to find 1st to 3rd Neighbors
	graph.distThreeNeighbors(vertex);
}
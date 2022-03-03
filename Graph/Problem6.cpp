//Alex Lee alee23@bu.edu
//Collaborators: Dabin Jang djang12@bu.edu

//References:
// list: https://www.cplusplus.com/reference/list/list/
// istream ignore(): https://www.cplusplus.com/reference/istream/istream/ignore/
// numericlimits: https://en.cppreference.com/w/cpp/types/numeric_limits/max

#include <iostream>
#include <list>
#include <string>
#include <map>
#include <fstream>
#include <limits>

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

Undir_Graph::Undir_Graph(const char* filename){
	

	std::ifstream myfile;
	myfile.open(filename);
	string vertex, neighbors;

	//istringstream line;

	//read first line to get 1) number of vertices and 2)number of edges
	myfile >> this->numvertex >> this->numedge;
	
	// add vertices to map -> graphAdjList
	for (int i = 0; i < this->numvertex ; i++){
		myfile.ignore(numeric_limits<streamsize>::max(),'\n');
		myfile >> vertex;
		//cout<< vertex <<endl;

		this->graphAdjList[vertex] = new list<string>;
	}

	myfile.ignore(numeric_limits<streamsize>::max(), '\n');

	// add edges to the map (these are neighbors of the vertices)
	// neighbors will be places in STL data structure list
	for (int i = 0; i < this->numedge; i++){
		myfile.ignore(numeric_limits<streamsize>::max(), ' ');
		myfile >> vertex >> neighbors;
		//cout<< vertex << " " << neighbors << endl;
		this->graphAdjList[vertex]->push_back(neighbors);
		this->graphAdjList[neighbors]->push_back(vertex);
		myfile.ignore(numeric_limits<streamsize>::max(), '\n');

	}

	myfile.close();
}

void Undir_Graph::distThreeNeighbors(string vertex){
	list<string>* totalneighborlist = new list<string>;
	list<string>* listneighbor1 = new list<string>;
	list<string>* listneighbor2 = new list<string>;
	list<string>* listneighbor3 = new list<string>;

	for (auto neighbor1 : *(this->graphAdjList[vertex])) {
		//cout << neighbor1 <<endl;
		listneighbor1->push_back(neighbor1);
	}

	for (auto neighbor1 : *(listneighbor1)) {
		//if (!this->graphAdjList[neighbor1]->empty()){
			for (auto neighbor2 : *(this->graphAdjList[neighbor1])){
				listneighbor2->push_back(neighbor2);
			}
		//}
	}

	for (auto neighbor2 : *(listneighbor2)) {
		//if (!this->graphAdjList[neighbor2]->empty()){
			for (auto neighbor3 : *(this->graphAdjList[neighbor2])){
				listneighbor3->push_back(neighbor3);
			}
		//}
	}

	//write new function to add listneighbor(x) to totalneighborlist
	add_allneighbors(listneighbor1, listneighbor2, listneighbor3, totalneighborlist);

	if (!totalneighborlist->empty()){
		totalneighborlist->sort();
		totalneighborlist->unique();
		totalneighborlist->remove(vertex);
		//cout << vertex << endl;
		for (auto neighbors : *(totalneighborlist)){
			cout << neighbors << endl;
		}
	}

	else{
		cout<< "NO NEIGHBORS!" << endl;
	}

}

//add all 1st to 3rd neighbors into one neighbor list
void Undir_Graph::add_allneighbors(list<string>* list1, list<string>* list2, list<string>* list3, list<string>* totallist){
	for (auto neighbor1 : *(list1)) {
		totallist->push_back(neighbor1);
	}

	for (auto neighbor2 : *(list2)) {
		totallist->push_back(neighbor2);
	}

	for (auto neighbor3 : *(list3)) {
		totallist->push_back(neighbor3);
	}
}





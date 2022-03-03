//
//  SkipList.h
//  Skip_List
//
//  Copyright Â© Tali Moreshet. All rights reserved.
//
//
//  This is an implementation of a Skip List class, consisting of Linked Lists, which are made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef SkipList_h
#define SkipList_h

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

template<class T>
class Node {
public:
    Node(const T& data);                            // constructor
    T data;                                         // node data, doubles as key
    Node<T> *next;                                  // node next pointer
    Node<T> *prev;                                  // node previous pointer
    Node<T> *up;                                    // node above pointer
    Node<T> *down;                                  // node below pointer
    void printData();                               // prints data value
    void print();                                   // prints entire node object content
};

template <class T>
class LinkedList {
public:
    LinkedList(T minVal, T maxVal);                 // constructor: accepts -infinity, +infinity values,
                                                    //  creates linked list with two corresponding nodes
    ~LinkedList();                                  // destructor
    Node<T>* search(Node<T>* location, T data);     // search for data starting at location, return node <= data
    Node<T>* insert(Node<T>* location, T data);     // insert node with data at new node to be placed directly 
                                                    //  after node with povided location, return new node
    void printData();                               // prints linked list data
    void print();                                   // prints linked list with all nodes pointers
    Node<T>* head;                                  // head of list
    Node<T>* tail;                                  // tail of list
};

template <class T>
class SkipList {
public:
    SkipList(T minVal, T maxVal);                   // constructor: accepts -infinity, +infinity values,
                                                    //  creates skip list with top-level only
    ~SkipList();                                    // destructor
    Node<T>* search(T data);                        // search for data, return node <= data (existing node, or location
                                                    //  where new node should be inserted in the bottom-most list)
    Node<T>* insert(T data);                        // insert node with data, return pointer if inserted, NULL if error
    void printData();                               // prints skip list data
    void print();                                   // prints skip list with all nodes pointers
    LinkedList<T> *topList;                         // pointer to the top-most list
    int randSeed = 330;                             // to be used as seed for the getRand() function
};

//returns 0 or 1 with a 50% chance 
//When it returns 1, insert the node to next level of the skiplist
int getRand(){
    return rand()%2;
}

/********************** From here down is the content of the LinkedList.cpp file: ***********************/

/****** Implementation of Node ******/

// Constructor
template<class T>
Node<T>::Node(const T& data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

// Print node's data value
template <class T>
void Node<T>::printData()
{
    cout << data << " ";
}

// Print entire node object content (data value, object's address, and all pointers)
template <class T>
void Node<T>::print()
{
    cout << " * " << data << ": [addr: " << this << " next: " << this->next << " prev: " << this->prev << " up: " << this->up << " down: " << this->down << "]  ";
}


/****** Implementation of linked list ******/

/*** TO BE COMPLETED ***/

template <class T>
LinkedList<T>::LinkedList(T minVal, T maxVal) {
    
    Node<T>* NewHead = new Node<T>(minVal);             // New Head pointer
    Node<T>* NewTail = new Node<T>(maxVal);             // New Tail pointer

    NewTail->prev = NewHead;                            // Tail points back to Head
    this->head = NewHead;                               // Head in LinkedList points to NewHead
    this->head->next = NewTail;                         // Head points to Tail
    
    /*
    this->head = (Node<T>*) malloc(sizeof(Node<T>));

    *(this->head) = Node<T>(minVal);

    this->head->next = (Node<T>*) malloc(sizeof(Node<T>));
    *(this->head->next) = Node<T>(maxVal);

    this->head->next->prev = (Node<T>*) malloc(sizeof(Node<T>));
    this->head->next->prev = this->head;

    this->tail = (Node<T>*) malloc(sizeof(Node<T>));
    *(this->tail) = *(this -> head -> next);
    */
}

//Destructor
template <class T>
LinkedList<T>::~LinkedList(){
    Node<T>* destructor = this->head;                   // create a pointer that points Head
    Node<T>* destructor2 = this->head;                  // create another pointer that points Head
    while((*destructor).next != nullptr) {              // Check if next pointer points nothing = end of linkedlist
        destructor2 = (*destructor).next;
        delete destructor;
        destructor = destructor2;
    }
}

//Search
template <class T>
Node<T>* LinkedList<T>::search(Node<T>* location, T data) {
    Node<T>* finalloc;

    while(location != nullptr) {
        if(data == location -> data) {
            finalloc = location;
            return finalloc;
        }
        else if (data < location -> data) {
            finalloc = location -> prev;
            return finalloc;
        }
        location = location -> next;
    }
    return finalloc;                                     
}

//Insert
template <class T>
Node<T>* LinkedList<T>::insert(Node<T>* location, T data) {
    Node<T>* createnode = new Node<T>(data);
    Node<T>* insertloc = location;

    if(insertloc == nullptr) {
        cout << "cannot be NULL Pointer" << endl;
        return insertloc;
    }
    
    //(*createnode).data = data;
    createnode -> next = insertloc -> next;
    insertloc -> next = createnode;
    createnode -> prev = insertloc;

    if (createnode -> next != nullptr) {
        createnode->next->prev = createnode;
    }

    return createnode;
}

//PrintData
template <class T>
void LinkedList<T>::printData(){
    Node<T>* Dataprinter = this -> head;
    while(Dataprinter != nullptr){
        (*Dataprinter).printData();
        Dataprinter = (*Dataprinter).next;
    }
}
//Print
template <class T>
void LinkedList<T>::print(){
    Node<T>* AllPrinter = this -> head;
    while(AllPrinter != nullptr){
        (*AllPrinter).print();
        AllPrinter = (*AllPrinter).next;
    }
}


/****** Skip List Implementation ******/

   /*** TO BE COMPLETED ***/

template <class T>
SkipList<T>::SkipList(T minVal, T maxVal) {
    LinkedList<T> * LevelZero = new LinkedList<T>(minVal, maxVal);
    this -> topList = LevelZero;
}

template <class T>
SkipList<T>::~SkipList() {
    Node<T>* row = this->topList->head;
    Node<T>* row2 = this->topList->head;
    Node<T>* column = this->topList->head;

    do {
        do {
            row2 = row -> next;
            delete row;
            row = row2;
        } while (row != nullptr);
        column = column -> down;
    } while (column != nullptr);
}

    /*
    Node<T>* eraser = topList->head;                   
    Node<T>* eraser2 = topList->head;
    Node<T>* eraser3 = topList->head;
    Node<T>* eraser4 = topList->head;

    //When there is only a toplist
    if(eraser -> down == nullptr){
        while(eraser->next != nullptr){
            eraser2 = eraser -> next;
            delete eraser;
            eraser = eraser2;
        }
    }
    
    //When there are multiple lists (delete all the list except toplist)
    else{
        while(eraser->down != nullptr){
            eraser = eraser3 -> down;
            eraser2 = eraser;
            eraser3 = eraser3 -> down;
            while(eraser->next != nullptr){
                eraser2 = eraser->next;
                delete eraser;
                eraser = eraser2;
            }
        }
    // delete the toplist
    eraser = topList -> head;
    while(eraser->next != nullptr){
            eraser2 = eraser -> next;
            delete eraser;
            eraser = eraser2;
        }
    }
    */

template <class T>
Node<T> *SkipList<T>::search(T data)
{
    Node<T>* topHead = topList -> head;

    // When there is only topList
    if (topHead -> down == nullptr){
        while (data > topHead -> next -> data){
            topHead = topHead -> next;
        }
        return topHead;
    }

    // When there is more than one list
    else {
        while (topHead -> down != nullptr){
            topHead = topHead -> down;
            while (data > topHead -> next -> data) {
                topHead = topHead -> next;
            }
        }
        return topHead;
    }
}

template <class T>
Node<T>* SkipList<T>::insert(T data)
{
    /*
    Node<T>* createnode, *temp;
    temp = this->search(data);
    Node<T>* topHead = this->topList->head;
    */

    Node<T> *newNode, *temp;
    temp = this -> search(data);

    if (temp->next->data == data) {
        return NULL;
    }

    if (temp->next != nullptr) {
        // insert element at the bottom of the list

        newNode = this -> topList -> insert(temp, data);
        int flip = 0;
        //will index upwards until flip is 0 or has index until the top level list
        do { 
            Node<T>* e = temp;

            //go to -inf to go up
            while (e->prev != nullptr) {
                e = e->prev;
            }
            //index upwards
            temp = e->up;
           
            if (temp == nullptr)
                break;

            newNode -> up = this -> topList -> insert(temp, data);
            newNode -> up -> down = newNode;
            // flip the coin
            flip = getRand();
        } while (flip == 1);
    }
    /*
    if (temp->next->data == data) {
        return NULL;
    }
    */
    /*
    else {
        Node<T> *createNode = new Node<T>(data);
        
        if((topHead->down == nullptr) && (topHead->up == nullptr)){
            createNode -> next = temp -> next;
            createNode -> prev = temp;
            temp -> next -> prev = createNode;
            temp -> next = createNode;
        }
    }
    */
}

template<class T>
void SkipList<T>::printData(){

    Node<T>* row = this -> topList -> head;
    Node<T>* column = this -> topList -> head;

    do {
        do {
            row -> printData();
            row = row -> next;
        } while (row != nullptr);
        column = column -> down;
    } while (column != nullptr);
}

template<class T>
void SkipList<T>::print()
{

}

#endif /* SkipList_h */
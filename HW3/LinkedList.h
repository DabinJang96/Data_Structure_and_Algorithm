//
// djang12@bu.edu
// Dabin Jang
//
//  LinkedList.h
//  Linked_List
//
//  Copyright Â© Tali Moreshet. All rights reserved.
//
//  This is an implementation of an ordered Linked List class, which is made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <cstdlib>
#include <time.h>

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
};

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

//Constructor
template <class T>
LinkedList<T>::LinkedList(T minVal, T maxVal) {
    Node<T>* NewHead = new Node<T>(minVal);             // New Head pointer
    Node<T>* NewTail = new Node<T>(maxVal);             // New Tail pointer
    (*NewTail).prev = NewHead;                          // Tail points back to Head
    this->head = NewHead;                               // Head in LinkedList points to NewHead
    this->head->next = NewTail;                         // Head points to Tail
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
    Node<T>* createnode = new Node(data);
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

#endif /* LinkedList_h */

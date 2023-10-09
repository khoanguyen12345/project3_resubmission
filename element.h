#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
template <class T> 
class Element
{
    public:
        bool empty;
        T data;
        Element* prev;
        Element* next;
        int key;
        Element(void); //constructor
        ~Element(void); //destructor
        Element(const Element<T> &copied_element); //copy constructor from another element
        Element(T inputData, int inputKey); //copy constructor by inserting in data and a key value
        int get_key() const; //returns numeric value stored inside element
        T get_data() const; //returns data stored inside element
};  
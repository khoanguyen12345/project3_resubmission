// ================================================
// element.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-09-2023
// Implementation file of class template Element
// ================================================

#include <optional>
#include "element.h"
using namespace std;


// ================================================
// Element
// ================================================

template <class T>
Element<T>::Element(void) {                                 //constructor
    empty = true;
}

// ================================================
// Element
// ================================================


template <class T>
Element<T>::Element(const Element<T> &copied_element) {     //constructor using sep. element
    empty = copied_element.empty;
    prev = copied_element.prev;
    next = copied_element.next; 
    key = copied_element.key;
    data = copied_element.data;
}

// ================================================
// Element
// ================================================

template <class T>
Element<T>::Element(T inputData,int inputKey) { 
    empty = false;
    prev = NULL;
    next = NULL; 
    key = inputKey;
    data = inputData;
}

// ================================================
// ~Element
// ================================================

template <class T>
Element<T>::~Element(void) {                                 //destructor
    prev = NULL;
    next = NULL; 
}

// ================================================
// get_data
// ================================================

template <class T>
T Element<T>::get_data() const { 
    if (empty == true){
        return 0;
    }
    return data;
}

// ================================================
// get_key
// ================================================

template <class T>
int Element<T>::get_key() const { 
    if (empty == true){
        return -1;
    }
    return key;
}
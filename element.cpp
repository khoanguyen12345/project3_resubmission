#include <optional>
#include "element.h"
using namespace std;

template <class T>
Element<T>::Element(void) { //constructor
    empty = true;
}

template <class T>
Element<T>::Element(const Element<T> &copied_element) { //constructor using sep. element
    empty = copied_element.empty;
    prev = copied_element.prev;
    next = copied_element.next; 
    key = copied_element.key;
    data = copied_element.data;
}


template <class T>
Element<T>::Element(T inputData,int inputKey) { 
    empty = false;
    prev = NULL;
    next = NULL; 
    key = inputKey;
    data = inputData;
}

template <class T>
Element<T>::~Element(void) { //destructor
    prev = NULL;
    next = NULL; 
}

template <class T>
T Element<T>::get_data() const { 
    if (empty == true){
        return 0;
    }
    return data;
}

template <class T>
int Element<T>::get_key() const { 
    if (empty == true){
        return -1;
    }
    return key;
}
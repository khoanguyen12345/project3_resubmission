#include <element.h>

template <class T>
Element<T>::Element(void){ //constructor
    data = NULL;
    key = NULL;
    prev = NULL;
    next = NULL; 
}

template <class T>
Element<T>::~Element(void){ //destructor
    prev = NULL;
    next = NULL; 
}

template <class T>
Element<T>::Element(const Element<T> &copied_element){ //destructor
    prev = copied_element.prev;
    next = copied_element.next; 
    key = copied_element.key;
    data = copied_element.data;
}

template <class T>
Element<T>::Element(T data,int key){ 
    
}
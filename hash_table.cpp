#include <iostream>
#include "hash_table.h"
using namespace std;

template <class T>
int HashTable<T>::h(int k) {
    return k%size;
}

template <class T>
HashTable<T>::HashTable() {
    hashtable = new T[10];
    size = 10;
}
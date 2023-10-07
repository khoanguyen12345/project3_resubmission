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

template <class T>
HashTable<T>::HashTable(int len) {
    if (len < 0) {
        throw std::runtime_error("Negative size for hash table not allowed")
    }
    hashtable = new T[len];
    size = len;
}
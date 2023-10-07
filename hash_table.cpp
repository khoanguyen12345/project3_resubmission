#include <iostream>
#include "hash_table.h"
#include "element.h"
using namespace std;

template <class T>
int HashTable<T>::h(int k) {
    return k%size;
    //should we check if our hash value is negative?
    //would we throw an error or just take the mod?
}

template <class T>
HashTable<T>::HashTable() {
    hashtable = new Element[10];
    size = 10;
}

template <class T>
HashTable<T>::HashTable(int len) {
    if (len < 0) {
        throw std::runtime_error("Negative size for hash table not allowed.")
    }
    hashtable = new Element[len];
    size = len;
}

template <class T>
void HashTable<T>::insert(T data, int key) {
    int hashVal = h(key);
    if (hashVal < 0) {
        throw std::runtime_error("Please choose a non-negative key!")
    }
    if (hashVal > size) {
        throw std::runtime_error("Hash function output is invalid.")
    }
    node = Element(data, key);
}
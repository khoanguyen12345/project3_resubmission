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
    hashTable = new Element<T>[10];
    size = 10;
}

template <class T>
HashTable<T>::HashTable(int len) {
    if (len < 0) {
        throw std::runtime_error("Negative size for hash table not allowed.")
    }
    hashTable = new Element<T>[len];
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
    Element<T> node = Element<T>(data, key);
    node.next = hashTable[hashVal];
    node.prev = nullptr;
    hashTable[hashVal] = node;
    size++;
}

template <class T>
void HashTable<T>::remove(int key) {

}

template <class T>
bool HashTable<T>::member(T data, int key) {

}

template <class T>
string HashTable<T>::to_string() {
    for (int i = 0; i < size; i++) {
        string out = "";
        Element<T> curr = hashTable[i];
        while (!curr.empty) {
            out = out + " (" + curr.get_data() + ", " + curr.get_key() + ")";
        }
        out = out + "\n";
        cout << i + ":" + out;
    }
}


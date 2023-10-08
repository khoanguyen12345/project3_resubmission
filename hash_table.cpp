#include <iostream>
#include <typeinfo>
#include <sstream>
#include "hash_table.h"
#include "element.h"
using namespace std;

template <class T>
void HashTable<T>::validIndex(int i) {
    if (i < 0 || i >= size) {
        throw std::runtime_error("Hash function output is an invalid index.");
    }
}

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
        throw std::runtime_error("Negative size for hash table not allowed.");
    }
    hashTable = new Element<T>[len];
    size = len;
}

template <class T>
void HashTable<T>::insert(T data, int key) {
    int hashVal = h(key);
    validIndex(hashVal);
    Element<T> node = Element<T>(data, key);
    node.next = &hashTable[hashVal];
    node.prev = nullptr;
    hashTable[hashVal] = node;
    size++;
}

template <class T>
void HashTable<T>::remove(int key) {
    int hashVal = h(key);
    validIndex(hashVal);
    Element<T> *tempNode = &hashTable[hashVal];
    while (tempNode->key != key){
        tempNode = tempNode->next;
    }
    Element<T> *prevNode = tempNode->prev;
    Element<T> *nextNode = tempNode->next;
    prevNode->next = tempNode->next;
    nextNode->prev = tempNode->prev;
    delete tempNode;
}

template <class T>
bool HashTable<T>::member(T data, int key) {
    int hashVal = h(key);
    validIndex(hashVal);
    bool ret = false;
    Element<T> *curr = &hashTable[hashVal];
    while (!curr->empty) {
        if (curr->data == data && curr->key == key) {
            ret = true;
            break;
        }
        curr = curr->next;
    }
    return ret;
}

template <class T>
string HashTable<T>::to_string() {
    if (size == 0) return "";
    stringstream out;
    for (int i = 0; i < size; i++) {
        Element<T> *curr = &hashTable[i];
        while (!curr->empty) {
            out << i << ": " << " (" << curr->get_data() << "," << curr->get_key() << ")";
            curr = curr->next;
        }
        out << endl;
    }
    return out.str();
}


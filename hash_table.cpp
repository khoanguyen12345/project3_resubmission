// ================================================
// hash_table.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-09-2023
// Implementation file of class template Hashtable
// ================================================

#include <iostream>
#include <typeinfo>
#include <sstream>
#include "hash_table.h"
#include "element.h"
using namespace std;

// ================================================
// validIndex
// ================================================

template <class T>
bool HashTable<T>::validIndex(int i) {
    return (i >= 0 && i < size); 
}

// ================================================
// h
// ================================================

template <class T>
int HashTable<T>::h(int k) {
    if (size == 0) {
        return -1;
    }
    else {
        return k%size;
    }
}

// ================================================
// HashTable
// ================================================

template <class T>
HashTable<T>::HashTable() {
    hashTable = new Element<T>*[10];
    size = 10;
    for (int i = 0; i < size; i++) {
        Element<T>* item = new Element<T>();
        hashTable[i] = item;
    }
}

// ================================================
// HashTable
// ================================================

template <class T>
HashTable<T>::HashTable(int len) {
    if (len < 0) {
        throw std::runtime_error("Negative size for hash table not allowed.");
    }
    hashTable = new Element<T>*[len];
    size = len;
    for (int i = 0; i < size; i++) {
        Element<T>* item = new Element<T>();
        hashTable[i] = item;
    }
}

// ================================================
// insert
// ================================================

template <class T>
void HashTable<T>::insert(T data, int key) {
    int hashVal = h(key);
    if (validIndex(hashVal)) {
        Element<T>* node = new Element<T>(data, key);
        node->next = hashTable[hashVal];
        node->prev = nullptr;
        hashTable[hashVal]->prev = node;
        hashTable[hashVal] = node;
    }
}

// ================================================
// remove
// ================================================

template <class T>
void HashTable<T>::remove(int key) {
    if (size == 0){
        return;
    }
    int hashVal = h(key);
    if (validIndex(hashVal) && hashTable[hashVal]->empty != true) {
        Element<T>* tempNode = hashTable[hashVal];
        while (tempNode->key != key){
            if (tempNode->next == nullptr){
                return;
            }
            tempNode = tempNode->next;
        }
        if (hashTable[hashVal] == tempNode){ //remove at the start of linked list
            Element<T>* nextNode = tempNode->next;
            hashTable[hashVal] = nextNode;
            nextNode->prev = NULL;
        }else if (tempNode->next == nullptr){ //remove at the end of linked list
            Element<T>* prevNode = tempNode->prev;
            prevNode->next = NULL;
        }
        else if (tempNode->next != NULL && tempNode->prev != NULL) { //remove at the middle of linked list
            Element<T>* prevNode = tempNode->prev;
            Element<T>* nextNode = tempNode->next;
            prevNode->next = tempNode->next;
            nextNode->prev = tempNode->prev;
        } 
        delete tempNode;
        }
    return;
}

// ================================================
// member
// ================================================

template <class T>
bool HashTable<T>::member(T data, int key) {
    int hashVal = h(key);
    bool ret = false;
    if (validIndex(hashVal)) {
        Element<T>* curr = hashTable[hashVal];
        while (!curr->empty) {
            if (curr->data == data && curr->key == key) {
                ret = true;
                break;
            }
            curr = curr->next;
        }
    }
    return ret;
}

// ================================================
// to_string
// ================================================

template <class T>
string HashTable<T>::to_string() {
    if (size == 0) return "";
    stringstream out;
    for (int i = 0; i < size; i++) {
        Element<T>* curr = hashTable[i];
        out << i << ": ";
        while (!curr->empty) {
            out << "(" << curr->get_data() << "," << curr->get_key() << ") ";
            curr = curr->next;
        }
        out << endl;
    }
    return out.str();
}


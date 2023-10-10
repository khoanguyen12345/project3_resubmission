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
// HashTable
// Create an instance of class HashTable
// Pre-condition: None
// Post-condiiton: A new hash table
// Parameter: None
// Return: None
// ================================================

template <class T>
HashTable<T>::HashTable() {
    hashTable = new Element<T>*[10];                   //initialize an array of pointers of class template Element
    size = 10;                                         //set the size of the array
    for (int i = 0; i < size; i++) {
        Element<T>* item = new Element<T>();           //initialize an element of class template Element
        hashTable[i] = item;                           //pointer at index i points to the newly initilized element
    }
}

// ================================================
// HashTable
// Create an instance of class HashTable with 'len' slots
// Pre-condition: None
// Post-condiiton: A new hash table with 'len' slots
// Parameter: len - number of slots that the hash table will have
// Return: None
// ================================================

template <class T>
HashTable<T>::HashTable(int len) {
    if (len < 0) {                                                              //check if len is valid
        throw std::runtime_error("Negative size for hash table not allowed.");  //if len is not valid then throw error
    }
    hashTable = new Element<T>*[len];                                           //initialize an array of pointers
    size = len;                                                                 //set the hash table's number of slots
    for (int i = 0; i < size; i++) {
        Element<T>* item = new Element<T>();                                    //initialize an element of class template Element
        hashTable[i] = item;                                                    //pointer at index i points to newly initilized element
    }
}

// ================================================
// insert
// Pre-condition:
// Post-condiiton:
// Parameter:
// Return:
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
// Pre-condition:
// Post-condiiton:
// Parameter:
// Return:
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
        if (hashTable[hashVal] == tempNode){                            //remove at the start of linked list
            Element<T>* nextNode = tempNode->next;
            hashTable[hashVal] = nextNode;
            nextNode->prev = NULL;
        }else if (tempNode->next == nullptr){                           //remove at the end of linked list
            Element<T>* prevNode = tempNode->prev;
            prevNode->next = NULL;
        }
        else if (tempNode->next != NULL && tempNode->prev != NULL) {    //remove at the middle of linked list
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
// validIndex
// Pre-condition: Exists a hash table
// Post-condiiton: Return the index
// Parameter: int i - the index to be check if 
//                    it is in the hash table
// Return: the index if it is in the hash table
// ================================================

template <class T>
bool HashTable<T>::validIndex(int i) {
    return (i >= 0 && i < size);                    //if i is larger thab 0 and smaller than array's size, then return i
}

// ================================================
// member
// Pre-condition:
// Post-condiiton:
// Parameter:
// Return:
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
// h
// Pre-condition:
// Post-condiiton:
// Parameter:
// Return:
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
// to_string
// Pre-condition:
// Post-condiiton:
// Parameter:
// Return:
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


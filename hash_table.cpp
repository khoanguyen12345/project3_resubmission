#include <iostream>
#include <typeinfo>
#include <sstream>
#include "hash_table.h"
#include "element.h"
using namespace std;

template <class T>
bool HashTable<T>::validIndex(int i) {
    return (i >= 0 && i < size); 
}

template <class T>
int HashTable<T>::h(int k) {
    if (size == 0) {
        return -1;
    }
    else {
        return k%size;
    }
}

template <class T>
HashTable<T>::HashTable() {
    hashTable = new Element<T>[10];
    size = 10;
    for (int i = 0; i < size; i++) {
        Element<T>* item = new Element<T>();
        hashTable[i] = item;
    }
}

template <class T>
HashTable<T>::HashTable(int len) {
    if (len < 0) {
        throw std::runtime_error("Negative size for hash table not allowed.");
    }
    hashTable = new Element<T>[len];
    size = len;
    for (int i = 0; i < size; i++) {
        Element<T>* item = new Element<T>();
        hashTable[i] = item;
    }
}

template <class T>
void HashTable<T>::insert(T data, int key) {
    int hashVal = h(key);
    if (validIndex(hashVal)) {
        Element<T> node = Element<T>(data, key);
        node.next = hashTable[hashVal];
        node.prev = nullptr;
        hashTable[hashVal]->prev = &node;
        hashTable[hashVal] = &node;
        size++;
    }
}

template <class T>
void HashTable<T>::remove(int key) {
    int hashVal = h(key);
    if (validIndex(hashVal)) {
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
}

template <class T>
bool HashTable<T>::member(T data, int key) {
    int hashVal = h(key);
    bool ret = false;
    if (validIndex(hashVal)) {
        Element<T> *curr = &hashTable[hashVal];
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

template <class T>
string HashTable<T>::to_string() {
    cout << "lol" << endl;
    if (size == 0) return "";
    stringstream out;
    cout << "lol" << endl;
    for (int i = 0; i < size; i++) {
        cout << "1inside" << i << endl;
        Element<T> *curr = &hashTable[i];
        cout << "2inside" << endl;
        while (!curr->empty) {
            cout << "3inside" << endl;
            out << i << ": " << " (" << curr->get_data() << "," << curr->get_key() << ")";
            cout << "4inside" << endl;
            curr = curr->next;
            cout << curr->empty << " " << curr->get_data() << " " << curr->get_key() << curr->next << " help" << endl;
        }
        out << endl;
    }
    return out.str();
}


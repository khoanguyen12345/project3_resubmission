#pragma once
#include <string>
#include "element.h"
using namespace std;

template <class T> 
class HashTable
{
    private:
        Element* hashTable;
        int size;
        int h(int k);             //hash function
    public:
        HashTable();          //constructor
        HashTable(int len);      //constructor 2
        void insert(T data, int key);
        void remove(int key);
        bool member(T data, int key);
        string to_string();
};
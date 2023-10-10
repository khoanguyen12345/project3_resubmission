// ================================================
// hash_table.h
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-09-2023
// Header file for class template HashTable
// ================================================

#pragma once
#include <string>
#include "element.h"
using namespace std;

template <class T> 
class HashTable
{
    private:
        Element<T>** hashTable;
        int size;                 
    public:
        HashTable();                    //constructor
        HashTable(int len);             //constructor 2
        void insert(T data, int key);   //
        void remove(int key);
        bool validIndex(int i);
        bool member(T data, int key);
        int h(int k);                   //hash function
        string to_string();
};
#pragma once
#include <string>
using namespace std;

template <class T> 
class HashTable
{
    private:
        T* hashtable;
        int size;
        int h(int k);             //hash function
    public:
        HashTable();          //constructor
        HashTable(int len);      //constructor 2
        void insert(T data, int key);
        void remove(int key);
        void member(T data, int key);
        string to_string();
};
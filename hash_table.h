#pragma once
#include <string>
using namespace std;

template <class T> 
class HashTable
{
    private:
        T* hashtable;
        int size;   
    public:
        HashTable(void); //constructor
        HashTable(int size);
        void insert(T data, int key);
        void remove(int key);
        void member(T data, int key);
        string to_string();
};
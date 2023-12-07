// ================================================
// hash_table.h
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-10-2023
// Header file for class template HashTable
// ================================================

#pragma once
#include <string>
#include "element.h"
using namespace std;

template <class T> 
class HashTable
{                 
    public:
        HashTable();                                                            //default constructor
        HashTable(int len);       
        ~HashTable();                                                           //constructor initialize hash table with 'len' slots
        
        void insert(T data, int key); 
        void insert_login(T data, long key);                                           //insert element
        void remove(int key);                                                   //remove element
        bool validIndex(int i);                                                 //check if index is within the hash table
        bool member(T data, int key);                                           //check if element is in the hash table
        bool member_login(T data, long key);
        int h(int k);  
        int h_login(long k);                                                           //hash function
        
        int h_most_significant(int k);                                          
        void insert_most_significant(T data, int key);                          //convert data into string
        bool member_most_significant(T data, int key);
        
        int h_cormen_multiplication(int k);              
        void insert_cormen_multiplication(T data, int key);                         
        bool member_cormen_multiplication(T data, int key);
        string to_string();                                                     //convert data into string

        float loadFactor();
        int size;

    private:
        Element<T>** hashTable;
}; 
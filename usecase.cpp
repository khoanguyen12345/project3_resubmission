// ================================================
// usecase.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-09-2023
// 
// ================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "hash_table.h"
#include "element.h"

using namespace std;

template <class T>
HashTable<T>* create_table(string fname, int m) {
    fstream f;
    fname = fname + ".csv";            //is this really needed?
    f.open(fname, ios::in);
}

template <class T>
bool login(HashTable<T>* ht, T username, string password) {
}

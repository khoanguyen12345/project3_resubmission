// ================================================
// usecase.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// ================================================

#include <iostream>
#include <fstream>
#include <string>
#include "hash_table.h"
#include "element.h"

using namespace std;

template <class T>
HashTable<T>* create_table(string fname, int m) {
    ifstream f;           
    f.open(fname, ios::in);
    HashTable<T> ht(m);
    while (f.good()) {
        string user;
        string pass;
        getline(f, user, ',');
        getline(f, pass, '\n');
        if (user == "") continue;
        if (pass != "") pass.erase(0,1);
        ht.insert(user, h(pass));    
    }
}

template <class T>
bool login(HashTable<T>* ht, T username, string password) {
    return ht.member(username, h(stoi(password)));
}

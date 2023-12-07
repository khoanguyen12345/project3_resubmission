// ================================================
// usecase.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-10-2023
// ================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "hash_table.h"
#include "element.h"

using namespace std;

template <class T>
HashTable<T>* create_table(string fname, int m) {
    ifstream f;           
    f.open(fname, ios::in);
    HashTable<T>* ht = new HashTable<T>(m);
    while (f.good()) {
        string user ;
        string pass;
        getline(f, user, ',');
        getline(f, pass, '\n');
        if (user == "") continue;
        if (pass != "") pass.erase(0,1);
        long p = 0;
        stringstream temp;
        temp << pass;
        temp >> p;
        ht->insert_login(user, p);  
    }
    return ht;
}

template <class T>
bool login(HashTable<T>* ht, T username, string password) {
    long p = 0;
    stringstream temp;
    temp << password;
    temp >> p; 
    return ht->member_login(username, p);
}

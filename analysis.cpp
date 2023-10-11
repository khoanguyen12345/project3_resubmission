// ================================================
// analysis.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-11-2023
// ================================================

#include "hash_table.cpp"
#include "element.cpp"
#include <string>
#include <iostream>


float testCormen(int numbers[], int arraySize) {
    HashTable<int>* ht1 = new HashTable<int>(20);
    for (int i = 0; i < arraySize; i++) {
        ht1->insert_cormen_multiplication(0, numbers[i]);
    }
    cout << ht1->loadFactor() << endl;
    return ht1->loadFactor();
}

float testSigbits(int numbers[], int arraySize) {
    HashTable<int>* ht2 = new HashTable<int>(20);
    for (int i = 0; i < arraySize; i++) {
        ht2->insert_most_significant(0, numbers[i]);
    }
    cout << ht2->loadFactor() << endl;
    return ht2->loadFactor();
}

int main() {

    srand(time(NULL));
    int numbers[100000];

    for (int i = 0; i < 100000; i++) {
        numbers[i] = i* (rand() % 100 + 1 );
    }

    float cormen = 0;
    for (int i = 0; i < 2; i++) {
        float val = testCormen(numbers,100000);
        cormen = cormen + val;
    }
    cormen = cormen/2;

    float sigBits = 0;
    for (int i = 0; i < 2; i++) {
        float val = testSigbits(numbers,100000);
        sigBits = sigBits + val;
    }
    sigBits = sigBits/2;

    cout << "Over 1 run of tests where we used srand to generate an array of 100000 numbers and inserted everything in it to hash tables using both hash functions," << endl;
    cout << "We obtain a load factor using the significant bits function of " << sigBits << " elements in one slot of our HashTable of length 20 and " << cormen << " using the cormen method instead." << endl; 
}
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

//size of linked lists for use of analysis
int sizeList(Element<int> x){
     Element<int>* curr = &x;
     int counter = 0;
    while (!curr->empty) {                                                
        curr = curr->next;  
        counter++;                                                
    }
    return counter;
}

//testing to find the minimum elements, maximum elements, and difference between min and max value
void test(int numbers[],int array_size){
    int load_factor;
    int ht_size = 5;
    HashTable<int> ht1(ht_size);
    for (int i=0;i<array_size;i++){
        cout << numbers[i];
        ht1.insert_cormen_multiplication(0,numbers[i]);
        
    }
    int max = 0;
    int min = 2147483647;
    int range = 0;
    for (int i=0;i<ht_size;i++){
        int sizeCurr = sizeList(*ht1.hashTable[i]);
        if (sizeCurr > max){
            max = sizeCurr;
        }else if (sizeCurr < min){
            min = sizeCurr;
        }
    }
    range = max - min;
    cout << "minmum elements in a linked list is: " << min << endl;
    cout << "maximum elements in a linked list is: " << max << endl;
    cout << "range of elements between the lrgest and smallest linked list is: " << range << endl;

}

float testCormen(int numbers[], int arraySize) {
    HashTable<int>* ht1 = new HashTable<int>(20);
    for (int i = 0; i < arraySize; i++) {
        ht1->insert_cormen_multiplication(0, numbers[i]);
    }
    float loadFactor = ht1->loadFactor();
    delete ht1;
    return loadFactor;
}

float testSigbits(int numbers[], int arraySize) {
    HashTable<int>* ht2 = new HashTable<int>(20);
    for (int i = 0; i < arraySize; i++) {
        ht2->insert_most_significant(0, numbers[i]);
    }
    float loadFactor = ht2->loadFactor();
    delete ht2;
    return loadFactor;
}

int main() {
    srand(time(NULL));
    int numbers[100000];
    for(int i = 0; i < 100000; i++) {
        numbers[i] = rand();
    }
    cout << 1 << endl;
    cout << testCormen(numbers,100000) << endl;
    cout << 2 << endl;
    cout << testSigbits(numbers, 100000) << endl;
    return 0;
}
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

void test(int numbers[],int array_size){
    int load_factor;
    int ht_size = 5;
    HashTable<int> ht1(ht_size);
    for (int i=0;i<array_size;i++){
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

int main(){
    int numbers[10] = {1,2,3,4,5,6,7,8,9,10};
    test(numbers,10);
}
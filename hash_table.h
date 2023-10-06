#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define INITIAL_HEAP_SIZE 20

using namespace std;
template <class T> 
class MinQueue
{
    public:
        MinQueue(void); //constructor
        ~MinQueue(void); //destructor
        MinQueue(T* myMinQueue, int n); //copy constructor into array
        void insert (const T &element); //inserting element into end of queue
        T min (void); //returns minimum value in array 
        T extract_min (void); //return and remove minimum value
        void decrease_key (int i,T v); //decreasing the value at index in the heap (not index in the array) to be equal to new value
        void min_heapify(int i); //heapifies min heap from i using priv function heapify
        void build_heap(); //build min-heap from unordered values in original class using priv function build_min_heap
        void sort(T myMinQueue[]); //sorts MinQueue using priv function heapsort      
        void resize(int n);
        void set(int i, T v); //set index i to specific value
        void allocate(int size); //set heap_size to specific value
        string to_string (void) const;
        string sliding_window(int arr[], int len, int window);
        void debug ();



    private:
        vector<T> heap;
        int heap_size;   
};
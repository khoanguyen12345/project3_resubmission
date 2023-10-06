template <class T>
MinQueue<T>::MinQueue(void){ //constructor
    heap_size = 0;
}

template <class T>
MinQueue<T>::~MinQueue(void){ //destructor
    heap.resize(0);
    heap_size = 0;
}

template <class T>
MinQueue<T>::MinQueue(T* myMinQueue, int n){ //copy constructor
/*
    Pre-condition:
    - n must match the size of myMinQueue
    - elements in myMinqueue must match data type declared in original minqueue declaration

    Post-condition:
    - returns a vector that follows min-heap properties, implemented as a MinQueue object
    - all elements in myMinQueue are in the returned heap.

    Purpose: 
    - copies elements from an array into a minqueue, following max heap proerties

    Return: returns a vector that follows min-heap properties, implemented as a MinQueue object
*/
    if (n<1){ 
        return;
    }
    heap.resize(n); 
    heap_size = n; 
    for (int i = 0; i < heap_size; i++)
    {
        heap[i] = myMinQueue[i];
    }
    build_heap();
    return;
}
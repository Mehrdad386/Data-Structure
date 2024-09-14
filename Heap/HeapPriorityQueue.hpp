#include"Heap.hpp"

class HeapPriorityQueue{

public:

    void enqueue( int item){
        heap.insert(item); 
    }

    int dequeue(){
        return heap.remove() ;
    }

private:

    Heap heap = Heap(10) ;

};
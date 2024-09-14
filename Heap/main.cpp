
#include"MaxHeap.hpp"
void sortByHeap(int* numbers , int size) ; 

int main(){
    int* numbers  = new int[6] {5,3,10,1,4,2} ;
    MaxHeap maxHeap ;
    std::cout<<maxHeap.getKlargest(numbers , 6 , 2)  ;

    delete[] numbers ;
    return 0 ;
}



void sortByHeap(int* numbers , int size){
    Heap heap(size) ;
    for(int i {} ; i<size ; i++){
        heap.insert(numbers[i]) ;
    }
    for(int i{} ; i<size ; i++){
        numbers[i] = heap.remove() ;
    }
    
}




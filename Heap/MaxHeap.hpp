#include<algorithm>
#include"Heap.hpp"

class MaxHeap {
public:
    static void heapify(int *numbers, int size) {

        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyHelper(numbers, i, size);
        }
    }

    static int getKlargest(int* numbers , int size , int k){
        Heap heap = Heap(size) ;
        for(int i{} ; i<size ; i++){
            heap.insert(numbers[i]) ;
        }
        for(int i{} ; i<k-1 ; i++){
            heap.remove() ;
        }
        return heap.max() ;
    }

private:
    static void heapifyHelper(int* numbers, int index, int size) {
        int largerIndex = index;
        int leftIndex = index * 2 + 1;
        if(leftIndex < size && numbers[leftIndex] > numbers[largerIndex]) {
            largerIndex = leftIndex;
        }
        
        int rightIndex = index * 2 + 2;
        if(rightIndex < size && numbers[rightIndex] > numbers[largerIndex]) {
            largerIndex = rightIndex;
        }
        
        
        if(index != largerIndex) {
            std::swap(numbers[index], numbers[largerIndex]);
     
            heapifyHelper(numbers, largerIndex, size);
        }
    }
};
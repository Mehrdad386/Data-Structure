#include<algorithm>
#include<iostream>

class Heap{

public:

    Heap(int size) : size(size), index(0) {
        items = new int[size];
    }

    ~Heap() { 
        delete[] items; 
    }
    
    void insert( int item ){
        if(index == size){
            std::__throw_length_error("heap overflow") ;
        }
        items[index++] = item ;
        int currentIndex = index - 1 ;
        bubbleUp(currentIndex) ;
    }

    int remove(){
        if(index == 0){
            std::__throw_logic_error("no element to remove") ;
        }
        int root = items[0] ;
        items[0] = items[--index] ;
        bubbleDown(0) ;
        return root ;
    }

    bool isEmpty(){ return index == 0 ; }


    void toString(){
        for(int i{} ; i< index ; i++){
            std::cout<<items[i]<<'\t' ;
        }
    }

    int max(){
        if(isEmpty()){
            std::__throw_range_error("no element") ;
        }
        return items[0] ;
    }


private:

    int* items ;
    int size ;
    int index ;

    void bubbleUp( int currentIndex ){
        int ParentIndex = this->ParentIndex(currentIndex) ;
        while( currentIndex>0 && items[currentIndex] > items[ParentIndex] ){
            std::swap(items[currentIndex] , items[ParentIndex]) ;
            currentIndex = ParentIndex;
            ParentIndex = this->ParentIndex(currentIndex);
        }
        
    }

    void bubbleDown(int index){
        while(index <= this->index && !isValidParent(index)){
            int largerChildIndex = this->largerChildIndex(index) ;
            std::swap(items[index] , items[largerChildIndex]) ;
            index = largerChildIndex ;
        }
    }

    int largerChildIndex(int index){
        if(!hasLeftChild(index)){
            return index ;
        }  
        if(!hasRightChild(index)){
            return leftChildIndex(index) ;
        }
        return (leftChild(index) > RightChild(index))? leftChildIndex(index) : RightChildIndex(index) ;
    }

    bool hasLeftChild(int index){ return leftChildIndex(index) < this->index ;}
    bool hasRightChild(int index){ return RightChildIndex(index) < this->index ;}

    bool isValidParent(int index){
        if(!hasLeftChild(index)){
            return true ;
        }
        if(!hasRightChild(index)){
            return items[index] >= leftChild(index) ;
        }
        return items[index] >=  leftChild(index) && items[index] >= RightChild(index) ;
    }

    int leftChildIndex(int index){ return index*2 + 1 ; }
    int RightChildIndex(int index){ return index*2 + 2 ; }
    int ParentIndex(int index){ return (index-1)/2 ; }
    int leftChild(int index){ return items[this->leftChildIndex(index)] ; }
    int RightChild(int index){ return items[this->RightChildIndex(index)] ; }
};
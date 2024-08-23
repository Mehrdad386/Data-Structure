#include<iostream>
class PriorityQueue{

public:
    PriorityQueue() : size(10) , counter(0) {}

    void add( int item ){
        if(counter == 0){
            items[0] = item ;
            counter++ ;
        }else{
            int i{} ;
            for( i = counter - 1 ; i>= 0; i--){
                if(items[i] > item){
                    items[i+1] = items[i] ;
                }else{
                    break;
                }
                    
            }
            items[i+1] = item ;
            counter++ ;        }

    }

    //bigger number has higher priority
    void remove(){
        items[counter] = 0 ;
        counter-- ;
    }

    int peek(){
        return items[counter] ;
    }

    bool isEmpty(){
        return counter == 0 ;
    }

    void toString(){
        for(int i{} ; i<counter ; i++){
            std::cout<<items[i]<<' ' ;
        }
    }
    

private:

    int* items = new int[size] ;
    int size ;
    int counter ;

};
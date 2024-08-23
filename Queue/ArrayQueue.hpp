#include<iostream>

class ArrayQueue{

public:

    ArrayQueue() : front(0) , rear(0) , size(5) , count(0) {}

    void enqueue( int input ){
        if(count<size){
            items[rear] = input ;
            rear = (rear+1) % size ;
            count++ ;
        }
        else
            std::__throw_length_error("queue overflow") ;
    }

    void dequeue(){
        if(count > 0){
            items[front] = 0 ;
            front = (front+1)%size ;
            count-- ;
        }
        else
            std::__throw_length_error("queue overflow") ;
    }

    bool isEmpty(){
        return count == 0 ;
    }

    bool isFull(){
        return count == size ;
    }

    int peek(){
        return items[front] ;
    }

    void toString(){
        int temp = rear ;
        for(int i{} ; i<size ; i++){
            std::cout<<items[rear%size]<<' ' ;
            rear++ ;
        }
        rear = temp ;
    }

    ~ArrayQueue(){ delete[] items ;}

private:

    int size ;
    int* items = new int[size] ;
    int front ;
    int rear ;
    int count ;

};
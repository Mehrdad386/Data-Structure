#include<iostream>
class Stack{

public:
    Stack() : count(0) {}

    void push( int item ){
        if(count == 5)
            std::cerr<<"stack overflow occured" ;
        else
            items[count++] = item ;
    }
    
    int pop(){
        if(count == 0){
            std::cerr<<"stack is empty" ;
            return -1 ;
        }else
            return items[--count] ;
    }

    int peek(){
        if(count == 0){
            std::cerr<<"stack is empty" ;
            return -1 ;
        }else
            return items[count - 1] ;
    }

    bool empty(){
        return count>0 ;
    }

    void toString(){
        for(int i{} ; i<count ; i++)
            std::cout<<items[i]<<' ' ;
    }

    ~Stack(){ delete[] items ; }

private:

    int* items = new int[5] ;
    int count ;

};
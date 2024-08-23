#include<iostream>
#include<queue>
#include<stack>
#include"ArrayQueue.hpp"
#include"StackQueue.hpp"
#include"PriorityQueue.hpp"

void reverse(std::queue<int>&) ;
void print( std::queue<int>) ;
void print( std::priority_queue<int>) ;

int main(){

    PriorityQueue queue ;
    queue.add(7) ;
    queue.add(3) ;
    queue.add(1) ;
    queue.add(9) ;
    queue.add(34) ;
    queue.add(-1) ;
    queue.toString() ;
    return 0  ;
}

//for reversing a queue
void reverse( std::queue<int>& queue){
    std::stack<int> stack ;
    while(!queue.empty()){
        stack.push(queue.front()) ;
        queue.pop() ;
    }
    while(!stack.empty()){
        queue.push(stack.top()) ;
        stack.pop() ;
    }
}

void print( std::queue<int> queue){
    while(!queue.empty()){
        std::cout<<queue.front()<<' ' ;
        queue.pop() ;    
    }
}
void print( std::priority_queue<int> queue){
    while(!queue.empty()){
        std::cout<<queue.top()<<' ' ;
        queue.pop() ;    
    }
}
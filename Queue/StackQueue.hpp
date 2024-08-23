#include<iostream>
#include<stack>

class StackQueue{

public:

    void enqueue(int input){
        mainStack->push(input) ;
    }

    void dequeue() {
        if (reversedStack->empty()) {
            reverse();
        }
        if (reversedStack->empty()) {
            throw std::runtime_error("Queue is empty");
        }
        reversedStack->pop();
    }

    int peek() {
        if (reversedStack->empty()) {
            reverse();
        }
        if (reversedStack->empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return reversedStack->top();
    }

    bool isEmpty(){
            return (reversedStack->empty() && mainStack->empty()) ;
    }

    void reverse(){
        if(reversedStack->empty()){
            while (!mainStack->empty())
            {
                reversedStack->push(mainStack->top()) ;
                mainStack->pop() ;
            }  
        }
    }

    ~StackQueue(){
        delete mainStack ;
        delete reversedStack ;
    }

private:

    std::stack<int>* mainStack = new std::stack<int> ;
    std::stack<int>* reversedStack = new std::stack<int> ;

};
#include<string>
#include<stack>


class StringReverser{

public:

    std::string reverse( std::string input){
        std::stack<char>* stc = new std::stack<char> ;
        for(char index : input){
            stc->push(index) ;
        }
        std::string reversed{} ;
        while(!stc->empty()){
            reversed += stc->top() ;
            stc->pop() ;
        }
        delete stc ;
        return reversed ;
    }
    

private:



};
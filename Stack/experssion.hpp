#include<string>
#include<stack>
class Experssion{

public:

    bool isBallanced( std:: string input ){
        std::stack<char>* stc = new std::stack<char> ;
       
        for(char index : input){
            if(isLeftBracket(index)){
                stc->push(index) ;
            }
            if(isRightBracket(index)){
                if(stc->empty()){
                    delete stc ;
                    return false ;
                }
                if(bracketsMatch(stc->top() , index)){
                    stc->pop() ;
                }
                else
                    return false ;
            }
        }
        if(stc->empty()){
            delete stc ;
            return true ;
        }else{
            delete stc ;
            return false ;
        }

    }

private:

    bool isLeftBracket(char index){
        if(index == '(' || index == '{' || index == '[' || index =='<')
            return true ;
        else
            return false ;
    }

    bool isRightBracket( char index ){
        if(index == ')' || index =='}' || index =='>' || index ==']')
            return true ;
        else 
            return false ;
    }

    bool bracketsMatch( char left , char right ){
        return (right == '}' && left == '{') || 
        (right == ')' && left == '(') || 
        (right == '>' && left == '<') || 
        (right == ']' && left == '[') ;
    }

};
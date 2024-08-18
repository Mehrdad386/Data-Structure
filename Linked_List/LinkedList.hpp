#include"Node.hpp"

class LinkedList{

public:

    LinkedList() : size(0) , head(nullptr) , tail(nullptr) {}

    void addLast(int number){
        Node* node = new Node(number) ;
        if(isEmpty()){
            head = node ;
            tail = node ;
        }else{
            tail->next = node ;
            tail = node ;
        }
        size++ ;
    }

    void addFirst( int number ){
        Node* node = new Node(number) ;
        if(isEmpty()){
            head = node ; 
            tail = node ;
        }
        else{
            node->next = head ;
            head = node ;
        }
        size++ ;
    }

    int indexOf( int number ){
        Node* node = head ;
        int index = 0 ;
        while(true){
            if(node->value == number){
                return index ;
            }
            else if(node->next == nullptr){
               break ;
            }
            else{
                index++ ;
                node = node->next ;
            }
        }
        return -1 ;
    }

    bool contains( int number ){
        if(indexOf(number) != -1){
            return true ;
        }
        else{
            return false ;
        }
    }

    void removeFirst(){
        if(head == tail){
            head = nullptr ;
            tail = nullptr ;
        }
        else if(isEmpty()){
            std::__throw_length_error("no elements") ;  
        }
        else{
            Node* second = head->next ;
            head = nullptr ; 
            head = second ;
        }
        size-- ;
    }
    void removeLast(){
        
        if(head == tail){
            head = nullptr ;
            tail = nullptr ;
        }
        else if (isEmpty()){
            std::__throw_length_error("no elements") ;  
        }
        else{
            Node* previous = getPrevious();
            tail = previous ;
            tail->next = nullptr ;
        }
        size-- ;
    }

    Node* getPrevious(){
        Node* previous = head ;
        while(previous->next != tail){
            previous = previous->next ;
        }
        return previous ;
    }

    int getSize(){ return size ;}

    void reverse(){

        Node* previous = head ;
        Node* current = head->next ;
        tail = head ;
        tail->next= nullptr ;
        Node* next = new Node(0) ;
        while(current !=nullptr){
            next = current->next;
            current->next = previous ;
            previous = current ;
            current = next ;
        }
        head = previous ;
    }

    int indexFromLast( int index ){
        Node* first = head ;
        Node* second = head ;
        for(int i{} ; i<index ; i++){
            second = second->next ;
        }

        while(second != tail){
            first = first->next ;
            second = second->next ;
        }
        return first->value ;
    }

private:

    int size ;
    Node* head ;
    Node* tail ;
    bool isEmpty(){ return head == nullptr; }

};
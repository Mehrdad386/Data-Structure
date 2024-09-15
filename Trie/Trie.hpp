#include"Node.hpp"
class Trie{

public:

    Trie(){
        root = new Node ;
    }

    void insert(std::string word) {
        Node* current = root;
        for (char ch : word) {
            // If the node does not exist, create a new one
            if (!current->hasChild(ch)) {
                current->addChild(ch) ;
            }
            current = current->getChild(ch); // Move to the child node
        }
        current->isEndOfWord = true; // Mark the end of the word
    }

    bool contains(std::string word){
        Node* current = root ;
        for(char ch : word){
            if (!current->hasChild(ch)) {
                return false ;
            }
            current = current->getChild(ch) ;
        }
        return current->isEndOfWord ;
    }

    void remove(std::string word){
        remove(root , word , 0) ;
    }

    void preOrderTraverse(){
        preOrderTraverse(root) ;
    }

    void postOrderTraverse(){
        postOrderTraverse(root) ;
    }


private:

    Node* root ;


    void remove(Node* node , std::string word , int index){
        if(index == word.length()){
            node->isEndOfWord = false ;
        }
        char ch = word[index] ;
        Node*  child = node->getChild(ch) ;
        if(child == nullptr)
            return ;
        remove(child , word , index+1) ;

        if(!child->hasChildren() && !child->isEndOfWord){
            node->removeChild(ch) ;
        }
    }

    void preOrderTraverse(Node* node){
        std::cout<<node->value<<' ' ;

        for(Node* child : node->getChildren()){
            preOrderTraverse(child) ;
        }
    }

    void postOrderTraverse(Node* node){

        for(Node* child : node->getChildren()){
            postOrderTraverse(child) ;
        }
        std::cout<<node->value<<' ' ;
    }



};
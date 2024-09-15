#include<string>
#include<unordered_map>
#include<iostream>
#include<vector>
#define ALPHABET_SIZE 26

struct Node{
    char value;
    std::unordered_map<char , Node*> children ;
    bool isEndOfWord;

    Node(char value) : value(value), isEndOfWord(false) {}
    
    Node() : value('\0'), isEndOfWord(false) {}

    std::string toString() {
        return "value: " + std::string(1, value);
    }

    //to check is a children exist
    bool hasChild(char ch){
        return children.find(ch) != children.end() ;
    }

    //to add a new child
    void addChild(char ch){
        children[ch] = new Node(ch) ;
    }

    //to return the given child
    Node* getChild(char ch){
        return children[ch] ;
    }

    std::vector<Node*> getChildren() {
        std::vector<Node*> childrenList;
        for (auto& pair : children) {
            childrenList.push_back(pair.second); // Add children to the list
        }
        return childrenList; // Return the list of children
    }

    bool hasChildren(){
        return !(children.empty()) ;
    }

    void removeChild(char ch){
        children.erase(ch) ;
    }

};
#include"Node.hpp"
#include"algorithm"
#include<iostream>

class AVLTree{

public:

    AVLTree() : root(nullptr) {}

    void insert( int value ){
        root = insert(root, value) ;
    }

private:

    Node* root ;

    Node* insert(Node* node , int value){
        if(node == nullptr){
            return new Node(value) ;
        }
        else if (value > node->value){
            node->rightChild = insert(node->rightChild , value) ;
        }else{
            node->leftChild = insert(node->leftChild , value) ;
        }
        setHeight(node) ;

        return balace(node);
    }

    int height(Node* node){
       return (node == nullptr)? -1 : node->height ;
    }

    int getBalanceFactor(Node* node) {
        return (node == nullptr) ? 0 : height(node->leftChild) - height(node->rightChild) ;
    }

    bool isLeftHeavy(Node* node){
        return getBalanceFactor(node)  > 1 ;
    }

    bool isRightHeavy(Node* node){
        return getBalanceFactor(node)  < -1 ;
    }

    Node* balace(Node* node){
        if(isLeftHeavy(node)){
            if(getBalanceFactor(node->leftChild) > 0){
                node->leftChild = rotateLeft(node->leftChild) ;
            }
            return rotateRight(node) ;
        }
        else if(isRightHeavy(node)){
            if(getBalanceFactor(node->rightChild) > 0){
                node->rightChild = rotateRight(node->rightChild) ;
            }
            return rotateLeft(node) ;
        }

        return node ;
    }

    Node* rotateLeft(Node* node){
        Node* newRoot = node->rightChild ;
        node->rightChild = newRoot->leftChild ;
        newRoot->leftChild = node ;
        setHeight(node) ;
        setHeight(newRoot) ;
        return newRoot ;
    }

    Node* rotateRight(Node* node){
        Node* newRoot = node->leftChild ;
        node->leftChild = newRoot->rightChild ;
        newRoot->rightChild = node ;
        setHeight(node) ;
        setHeight(newRoot) ;
        return newRoot ;
    }

    void setHeight(Node* node){
        node->height = std::max(height(node->leftChild) , height(node->rightChild)) + 1 ;
    }

};
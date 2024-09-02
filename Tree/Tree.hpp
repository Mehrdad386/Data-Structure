#include "Node.hpp"
#include <iostream>
#include<algorithm>
#include<limits>

// binary search tree -> left sub_tree is smaller and right sub tree is bigger
class Tree
{

public:
    Tree() : root(nullptr) {}

    void insert(int input)
    {
        if (root == nullptr)
        {
            root = new Node(input);
        }
        else
        {
            Node *current = root;
            while (true)
            {
                if (input <= current->value)
                {
                    if (current->leftChild == nullptr)
                    {
                        current->leftChild = new Node(input);
                        break;
                    }
                    else
                    {
                        current = current->leftChild;
                    }
                }
                else if (input > current->value)
                {
                    if (current->rightChild == nullptr)
                    {
                        current->rightChild = new Node(input);
                        break;
                    }
                    else
                    {
                        current = current->rightChild;
                    }
                }
            }
        }

    }

    bool find(int input)
    {
        Node *current = root;
        bool flag = false;
        while (current != nullptr)
        {
            if (input == current->value)
            {
                flag = true;
                break;
            }
            else
            {
                if (input > current->value)
                    current = current->rightChild;
                else if (input < current->value)
                    current = current->leftChild;
            }
        }
        return flag;
    }

    void inOrder()
    {
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    void preOrder()
    {
        preOrderTraversal(root);
        std::cout << std::endl;
    }

    void postOrder()
    {
        postOrderTraversal(root);
        std::cout << std::endl;
    }

    int height(){ return height(root) ; }

    int min(){ return min(root) ; }

    bool operator==( Tree tree ){
        return equals(root , tree.root) ;
    }

    bool isBinary(){
        double posInf = std::numeric_limits<double>::infinity();  // +∞
        double negInf = -std::numeric_limits<double>::infinity();
        return isBinary(root , negInf , posInf ) ;
    }

    void printNodeAtDistance(int distance){
        printNodeAtDistance(root , distance) ;
    }

    void LevelOrderTreversal(){
        for(int i {} ; i<height() ; i++){
            printNodeAtDistance(i) ;
            std::cout<<std::endl ;
        }
    }



private:
    Node *root;

    void inOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversal(node->leftChild);
        std::cout << node->value << ' ';
        inOrderTraversal(node->rightChild);
    }
    void preOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->value << ' ';
        preOrderTraversal(node->leftChild);
        preOrderTraversal(node->rightChild);
    }
    void postOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrderTraversal(node->leftChild);
        postOrderTraversal(node->rightChild);
        std::cout << node->value << ' ';
    }

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        
        return 1 + std::max(height(node->leftChild), height(node->rightChild));
    }

    int min(Node* node) {
        if (node == nullptr) {
            throw std::runtime_error("Tree is empty");
        }

        
        if (node->leftChild != nullptr) {
            return min(node->leftChild);
        }

        return node->value;
    }

    bool equals(Node* first , Node* second){
        if(first == nullptr && second == nullptr){
            return true ;
        }else if (first != nullptr && second != nullptr){
            return 
            first->value == second->value 
            && equals(first->leftChild , second->leftChild) 
            && equals(first->rightChild , second->rightChild);
        }else{
            return false ;
        }
    }

    bool isBinary(Node* node , double min , double max){
        if(node == nullptr)
            return true ;
        else if(node->value < min || node->value > max)
            return false ;
        else{
            return isBinary(node->leftChild , min , node->value - 1)
            && isBinary(node->rightChild , node->value+1 , max) ;
        }
    }
        void printNodeAtDistance(Node* node ,int distance){
            if(node == nullptr){
                return ;
            }
            if(distance== 0){
                std::cout<<node->value<<'\t' ;
                return ;
            }
            printNodeAtDistance(node->leftChild , distance - 1 ) ;
            printNodeAtDistance(node->rightChild , distance - 1 ) ;

        }

};
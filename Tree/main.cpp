#include<iostream>
#include"Tree.hpp"

int main(){

    Tree tree ;
    Tree tree2 ;
    tree.insert(7) ;
    tree.insert(4) ;
    tree.insert(9) ;
    tree.insert(1) ;
    tree.insert(0) ;
    tree.insert(-1) ;
    tree.insert(6) ;
    tree.insert(8) ;
    tree.insert(10) ;

   tree.LevelOrderTreversal() ;
    
    return 0 ;
}
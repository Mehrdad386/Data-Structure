#include<iostream>
#include"Search.hpp"

int main(){

    std::vector<int> array{3,5,6,7,8,9,11} ;
    Search search ;
    std::cout<<search.ternarySearch(array , 1) ;
    return 0 ;
}
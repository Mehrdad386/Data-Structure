#include<iostream>
#include"Sort.hpp"


int main(){

    std::vector<int> array {3,4,6,10,0,1} ;
    Sort sort ;
    sort.quickSort(array) ;
    for(int i {} ; i<array.size() ; i++){
        std::cout<<array.at(i)<<' ' ;
    }

    return 0 ;
}
#include"CharFinder.hpp"
#include"HashTable.hpp"


int main(){
    HashTable hash ;
    hash.put(1, "ali") ;
    hash.put(2, "reza") ;
    hash.put(3, "matin") ;
    std::cout<<hash.get(2)<<' ' ;
    hash.remove(2) ;
    std::cout<<hash.get(2)<<' ' ;


    return 0 ; 
}


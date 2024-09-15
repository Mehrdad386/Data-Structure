#include"Trie.hpp"

int main(){

    Trie trie ;
    trie.insert("car") ;
    trie.insert("care") ;
    trie.remove("car") ;
    std::cout<<trie.contains("car")<<' '<<trie.contains("care") ;
    return 0 ;
}
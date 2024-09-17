#include"Graph.hpp"


int main(){

    Graph graph ;
    graph.addNode("Mahdi") ;
    graph.addNode("Mehrdad") ;
    graph.addNode("Sina") ;
    graph.addNode("Matin") ;
    graph.addEdge("Sina" , "Mahdi") ;
    graph.addEdge("Mehrdad" , "Mahdi") ;
    graph.addEdge("Mehrdad" , "Matin") ;
    graph.addEdge("Mehrdad" , "Sina") ;
    std::cout<<graph.hasCycle() ;
    return 0 ;
}
#include"WeightedGraph.hpp"


int main(){

    WeightedGraph Graph ;
    Graph.addNode("A") ;
    Graph.addNode("B") ;
    Graph.addNode("C") ;
    Graph.addEdge("A" , "B" , 3) ;
    Graph.addEdge("C" , "B" , 4) ;
    Graph.addEdge("A" , "C" , 2) ;
    Graph.print() ;
    return 0 ;
}
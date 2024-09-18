#include"Node.hpp"

struct Edge
{
    Node from ;
    Node to ;
    int weight ;

    Edge(Node from , Node to , int weight) : from(from) , to(to) , weight(weight){}

    std::string toString(){ return from.label + " -> " + to.label ; }
};

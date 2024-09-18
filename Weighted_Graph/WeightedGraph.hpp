#include"Edge.hpp"
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<limits>
#include<unordered_set>

namespace std {
    template<>
    struct hash<Node> {
        std::size_t operator()(const Node& n) const {
            return std::hash<std::string>()(n.label);
        }
    };
}

class WeightedGraph{

public:

    void addNode(std::string label){
        nodes.emplace(label, Node(label));
        adjacencyList.emplace(Node(label) , std::list<Edge>()) ;
    }

    void addEdge(std::string from , std::string to , int weight){
        Node fromNode(from) ;
        Node toNode(to) ;
        if(nodes.find(from) == nodes.end()){
            std::__throw_invalid_argument("illegal argument") ;
        }
        if(nodes.find(to) == nodes.end()){
            std::__throw_invalid_argument("illegal argument") ;
        }
        adjacencyList.at(fromNode).push_back(Edge(fromNode , toNode , weight)) ;
        adjacencyList.at(toNode).push_back(Edge(toNode , fromNode , weight)) ;
    }
    int intShortestDistance(std::string from, std::string target) {
        
        if (nodes.find(from) == nodes.end() || nodes.find(target) == nodes.end()) {
            throw std::invalid_argument("Node not found in the graph");
        }

        
        std::priority_queue<std::pair<int, Node>, 
                            std::vector<std::pair<int, Node>>, 
                            std::greater<std::pair<int, Node>>> queue;

        // فاصله‌ها
        std::unordered_map<Node, int> distances;
        for (const auto& pair : nodes) {
            distances[pair.second] = std::numeric_limits<int>::max(); // default value must be infinity
        }
        distances[nodes[from]] = 0; // node's distance of itself is 0 

        queue.push({0, nodes[from]}); // add from node to queue

        while (!queue.empty()) {
            auto [currentDistance, currentNode] = queue.top();
            queue.pop();

            
            if (currentNode.label == target) {
                return currentDistance;
            }

            
            if (currentDistance > distances[currentNode]) {
                continue;
            }

            
            for (const auto& edge : adjacencyList[currentNode]) {
                Node neighbor = edge.to;
                int newDist = currentDistance + edge.weight;

                
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    queue.push({newDist, neighbor});
                }
            }
        }

        return -1;
    }

    void print() {
        for (const auto& pair : adjacencyList) {
            std::cout << pair.first.label << " is connected to: ";
            for (const auto& edge : pair.second) {
                std::cout << edge.to.label << " with weight: "<<edge.weight<<' ';
            }
            std::cout << std::endl;
        }
    }

    WeightedGraph getMinSpanningTree() {
        WeightedGraph mst;
        if (nodes.empty()) {
            return mst;
        }

       
        std::unordered_set<Node> addedNodes;
        
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> edgeQueue;

        
        Node startingNode = nodes.begin()->second;
        addedNodes.insert(startingNode);
        
        
        for (const auto& edge : adjacencyList[startingNode]) {
            edgeQueue.push(edge);
        }

        
        while (!edgeQueue.empty() && mst.adjacencyList.size() < nodes.size()) {
            Edge currentEdge = edgeQueue.top();
            edgeQueue.pop();

            
            if (addedNodes.find(currentEdge.to) == addedNodes.end()) {
                
                mst.addEdge(currentEdge.from.label, currentEdge.to.label, currentEdge.weight);
                addedNodes.insert(currentEdge.to);

                
                for (const auto& edge : adjacencyList[currentEdge.to]) {
                    edgeQueue.push(edge);
                }
            }
        }

        return mst;
    }

private:

    std::unordered_map<std::string , Node> nodes ; 
    std::unordered_map<Node , std::list<Edge>> adjacencyList ; 

};
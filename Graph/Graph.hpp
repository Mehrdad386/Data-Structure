#include<iostream>
#include"Node.hpp"
#include<unordered_map>
#include<list>
#include<set>
#include<stack>
#include<queue>
#include<vector>


class Graph{

public:


    void addNode(std::string label){
        nodes.emplace(label, Node(label));
        adjacencyList.emplace(label , std::list<std::string>()) ;
    }

    void addEdge(std::string from , std::string to){
        if(nodes.find(from) == nodes.end()){
            std::__throw_invalid_argument("illegal argument") ;
        }
        if(nodes.find(to) == nodes.end()){
            std::__throw_invalid_argument("illegal argument") ;
        }
        adjacencyList.at(from).push_back(to) ;
        adjacencyList.at(to).push_back(from) ;
    }

    void print() {
        for (const auto& pair : adjacencyList) {
            std::cout << pair.first << " is connected to: ";
            for (const auto& neighbor : pair.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void removeNode(std::string label){
        if(nodes.find(label) == nodes.end()){
            std::__throw_invalid_argument("illegal argument") ;
        }
        nodes.erase(label);
        adjacencyList.erase(label) ;
        for(auto& pair : adjacencyList){
            if(pair.first == label){
            }
            auto& neighbors = pair.second;
            for (auto it = neighbors.begin(); it != neighbors.end();) {
                if (*it == label) {
                    it = neighbors.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }

    void removeEdge(const std::string& from, const std::string& to) {
      
        if (nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end()) {
            throw std::invalid_argument("Illegal argument: One or both nodes do not exist");
        }

    
        auto& fromNeighbors = adjacencyList[from];
        fromNeighbors.remove(to);

   
        auto& toNeighbors = adjacencyList[to];
        toNeighbors.remove(from);
    }

    //recursive method
    void traverseDepthFirst(std::string root){
        std::set<Node> visited;
        traverseDepthFirst(nodes.at(root) , visited ) ;
    }

    //iterative method
    void traverseDepthFirstIte(std::string root){
        if (nodes.find(root) == nodes.end()) {
            throw std::invalid_argument("Illegal argument: Node does not exist");
        }
        Node node (root) ;
        std::stack<Node> stack ;
        std::set<Node> visited ;
        stack.push(node) ;
        while (!stack.empty())
        {
            Node current = stack.top() ;
            stack.pop() ;
            if(visited.find(current) != visited.end()){
                continue;
            }
            std::cout<<current.label<<std::endl ;
            visited.insert(current) ;
            for(auto& n : adjacencyList.at(current.label)){
                Node temp(n) ;
                if(visited.find(temp) == visited.end()){
                    stack.push(temp) ;
                }
            }
        }
        
    }

    void traverseBredthFirst(std::string root){
        if (nodes.find(root) == nodes.end()) {
            throw std::invalid_argument("Illegal argument: Node does not exist");
        }
        std::set<Node> visited ;
        std::queue<Node> queue ;
        queue.push(root) ;
        while(!queue.empty()){
            Node current = queue.front() ;
            queue.pop() ;
            if(visited.find(current) != visited.end()){
                continue;
            }
        std::cout<<current.label<<std::endl ;
        visited.insert(current) ;

        for(auto& n : adjacencyList.at(current.label)){
            Node temp(n) ;
            if(visited.find(temp) == visited.end()){
                queue.push(temp) ;
                }
            }
        }
    }

    bool hasCycle() {
        std::set<Node> all;
        std::set<Node> visiting;
        std::set<Node> visited;

       
        for (const auto& pair : nodes) {
            all.insert(pair.second);
        }

        // بررسی تمام گره‌ها
        while (!all.empty()) {
            Node currentNode = *all.begin();
            all.erase(all.begin());

            if (hasCycle(currentNode, all, visiting, visited)) {
                return true;
            }
        }
        return false;
    }


private:

    std::unordered_map<std::string , Node> nodes ;
    std::unordered_map<std::string , std::list<std::string>> adjacencyList ;

    void traverseDepthFirst(const Node& node, std::set<Node>& visited) {
        std::cout << node.label << std::endl; 
        visited.insert(node);
        
        for (const auto& n : adjacencyList.at(node.label)) {
            Node neighbor(n); 
            if (visited.find(neighbor) == visited.end()) {
                traverseDepthFirst(neighbor, visited);
            }
        }
    }

    bool hasCycle(Node node, std::set<Node>& all, std::set<Node>& visiting, std::set<Node>& visited) {
        if (visited.find(node) != visited.end()) {
            return false;
        }

        if (visiting.find(node) != visiting.end()) {
            return true;
        }

        visiting.insert(node);
        for (const auto& neighbor : adjacencyList.at(node.label)) {
            Node n(neighbor);
            if (hasCycle(n, all, visiting, visited)) {
                return true;
            }
        }

        visiting.erase(node); 
        visited.insert(node); 
        return false;
    }
};
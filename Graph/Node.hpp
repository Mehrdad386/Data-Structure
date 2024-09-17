#include<string>

struct Node{
    std::string label ;

    Node(std::string label) : label(label) {}

    bool operator<(const Node& other) const {
    return label < other.label;
    }
};
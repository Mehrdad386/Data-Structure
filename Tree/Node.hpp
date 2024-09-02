struct  Node
{
    int value ;
    Node* leftChild ;
    Node* rightChild ;

    Node(int value) : value(value) , rightChild(nullptr) , leftChild(nullptr)  {}
};

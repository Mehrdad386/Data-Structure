struct  Node
{
    int value ;
    int height ;
    Node* leftChild ;
    Node* rightChild ;

    Node(int value) : value(value) , rightChild(nullptr) , leftChild(nullptr) , height(0) {}
};

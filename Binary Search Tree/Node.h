#ifndef NODE_H
#define NODE_H
template<typename T>
class treeNode
{
public:
    T data;
    treeNode* leftChild;
    treeNode* rightChild;
    treeNode(T d) : data(d), leftChild(nullptr), rightChild(nullptr) 
    {}
};
#endif // !NODE_H

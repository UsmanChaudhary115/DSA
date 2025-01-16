#ifndef BST_H
#define BST_H
#include"Node.h"
#include<stack>
template<typename T>
class BST
{
    treeNode<T>* root;  
    treeNode<T>* findMin(treeNode<T>* node)
    {
        treeNode<T>* current = node;
        while (current && current->leftChild != nullptr)
        {
            current = current->leftChild;
        }
        return current;
    }
public:
    BST() :root(nullptr)
    {}
    bool search(T item)
    {
        treeNode<T>* temp = root;
        bool status = false;
        while (temp != nullptr && !status)
        {
            if (item < temp->data)
            {
                temp = temp->leftChild;
            }
            else if (item > temp->data)
            {
                temp = temp->rightChild;
            }
            else
            {
                status = true;
            }
        }
        return status;
    }
    void insertItem(T item)
    {
        if (root == nullptr)
        {
            root = new treeNode<T>(item);
            return;
        }
        treeNode<T>* ptr = root;
        treeNode<T>* parent = nullptr;
        while (ptr != nullptr)
        {
            parent = ptr;
            if (item < ptr->data)
            {
                ptr = ptr->leftChild;
            }
            else if (item > ptr->data)
            {
                ptr = ptr->rightChild;
            }
            else
            {
                return; //Already exist
            }
        }
        ptr = new treeNode<T>(item);
        if (item < parent->data)
        {
            parent->leftChild = ptr;
        }
        else
        {
            parent->rightChild = ptr;
        }
    }
    void deleteItem(T key) 
    {
        treeNode<T>* parent = nullptr;
        treeNode<T>* current = root;
        while (current != nullptr && current->data != key) 
        {
            parent = current;
            if (key < current->data) 
            {
                current = current->leftChild;
            }
            else 
            {
                current = current->rightChild;
            }
        }
        if (current == nullptr) 
        {
            return;
        }
        if (current->leftChild == nullptr && current->rightChild == nullptr) // in case it is a leaf node
        {
            if (current != root) 
            {
                if (parent->leftChild == current) 
                {
                    parent->leftChild = nullptr;
                }
                else 
                {
                    parent->rightChild = nullptr;
                }
            }
            else 
            {
                root = nullptr;
            }
            delete current;
        }
        else if (current->leftChild && current->rightChild) // Node to be deleted has two children
        {
            treeNode<T>* successor = findMin(current->rightChild);
            T successorValue = successor->data;
            deleteItem(successorValue);
            current->data = successorValue; 
        }
        else        // Node to be deleted has only one child
        {
            treeNode<T>* child = (current->leftChild) ? current->leftChild : current->rightChild;
            if (current != root) 
            {
                if (current == parent->leftChild) 
                {
                    parent->leftChild = child;
                }
                else 
                {
                    parent->rightChild = child;
                }
            }
            else 
            {
                root = child;
            }
            delete current;
        }
    }
    treeNode<T>* findLCA(T p, T q) 
    {
        treeNode<T>* current = root;
        while (current != nullptr) 
        {
            if (p < current->data && q < current->data) 
            {
                current = current->leftChild;
            }
            else if (p > current->data && q > current->data) 
            {
                current = current->rightChild;
            }
            else 
            {
                return current;
            }
        }
        return current;
    }
    bool findTarget(int k) 
    {
        if (root == nullptr) 
        {
            return false;
        }
        stack<treeNode<T>*> leftStack;
        stack<treeNode<T>*> rightStack;
        treeNode<T>* left = root;
        treeNode<T>* right = root;
        while (left != nullptr) 
        {
            leftStack.push(left);
            left = left->leftChild;
        }
        while (right != nullptr) 
        {
            rightStack.push(right);
            right = right->rightChild;
        }
        while (!leftStack.empty() && !rightStack.empty()) 
        {
            treeNode<T>* leftNode = leftStack.top();
            treeNode<T>* rightNode = rightStack.top();
            if (leftNode == rightNode) 
            {
                break;
            }
            int leftVal = leftNode->data;
            int rightVal = rightNode->data;
            int sum = leftVal + rightVal;
            if (sum == k) 
            {
                return true;
            }
            else if (sum < k) 
            {
                leftStack.pop();
                treeNode<T>* node = leftNode->rightChild;
                while (node != nullptr) 
                {
                    leftStack.push(node);
                    node = node->leftChild;
                }
            }
            else 
            {
                rightStack.pop();
                treeNode<T>* node = rightNode->leftChild;
                while (node != nullptr) 
                {
                    rightStack.push(node);
                    node = node->rightChild;
                }
            }
        }
        return false;
    }
};
#endif // !BST_H

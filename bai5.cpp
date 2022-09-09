#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Node
{
    int data;
    Node* left;
    Node* right;
public:
    Node(): data(0), left(nullptr), right(nullptr){}

    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node* getLeft()
    {
        return this->left;
    }

    void setLeft(Node* left)
    {
        this->left = left;
    }

     Node* getRight()
    {
        return this->right;
    }

    void setRight(Node* right)
    {
        this->right = right;
    }
};

//Ham phu viet o day
int findMax(Node* node){
    if (node == NULL)
        return -9;
    int max= node->getData();
    int maxLeft = findMax(node->getLeft());
    int maxRight = findMax(node->getRight());
    if (maxLeft > max ){
        max = maxLeft;
    }
    if (maxRight > max ){
        max=maxRight;
    }
    return max;
}
int findMin(Node* node){
    if (node == NULL)
        return 9999;
    int min = node->getData();
    int minLeft = findMin(node->getLeft());
    int minRight = findMin(node->getRight());
    if (minLeft < min)
        min = minLeft;
    if (minRight < min)
        min = minRight;
    return min;
}

int findS(Node* root)
{
    Node*   node=root;
    return findMax(node) - findMin(node);
}

int main(){
    Node* node1 = new Node(5, nullptr, nullptr);
Node* node2 = new Node(2, nullptr, nullptr);
Node* node3 = new Node(1, node1, node2);
Node* node4 = new Node(2, node3, nullptr);
Node* root = new Node(7, node4, nullptr);
cout << findS(root);
}
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Node
{
    int data;
    Node* next;
public:
    Node(): data(0), next(nullptr){}
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
    int getData()
    {
        return this->data;
    }
    void setData(int data)
    {
        this->data = data;
    }
    Node* getNext()
    {
        return this->next;
    }
    void setNext(Node* next)
    {
        this->next = next;
    }
};

void printList(Node* root)
{
    cout << "HEAD -> ";
    while (root)
    {
        cout << root->getData() << " -> ";
        root = root->getNext();
    }
    cout << "NULL" << endl;
}

//Ham phu viet o day
void reduceDuplicate(Node* &root)
{
    if(root==NULL)  return;
    stack<Node*> q;
    q.push(root);
    root=root->getNext();
    while(root!=NULL){
        if(q.top()->getData() == root->getData()){
            q.pop();
        }
        q.push(root);
        root=root->getNext();
    }
    Node* ptr=NULL;
    while(!q.empty()){
        Node* newNode=new Node(q.top()->getData(), ptr);
        ptr=newNode;
        q.pop();
    }
    root=ptr;
}

int main(){
   Node* node1 = new Node(1, nullptr);
Node* node2 = new Node(1, node1);
Node* node3 = new Node(1, node2);
Node* node4 = new Node(1, node3);
Node* node5 = new Node(1, node4);
printList(node5);
reduceDuplicate(node5);
printList(node5);
}
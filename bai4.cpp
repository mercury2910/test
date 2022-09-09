#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
    Node(int x, Node* next): val(x), next(next) {}
};
void print(Node* root){
    while(root!=NULL){
        cout << root->val << "->";
        root = root->next;
    }
    cout << "NULL";
}


//Ham phu viet o day

Node* reverse(Node* node){
    Node* tmp = node;
    Node *prev = NULL, *next = NULL;
 
    while (tmp != NULL) {
        next = tmp->next; 
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    return prev;
}

int LLToInt(Node* node){
    int kq=0;
    while(node!=NULL){
        kq=kq*10+node->val;
        node=node->next;
    }
    return kq;
}

Node* plusNum(Node* num1, Node* num2, Node* num3){
    //TODO
    int sum = LLToInt(reverse(num1)) + LLToInt(reverse(num2)) + LLToInt(reverse(num3));
    Node* pHead=NULL;
    while(sum > 0){
        Node* curr=new Node(sum%10, pHead);
        pHead=curr;
        sum=sum/10;
    }
    return reverse(pHead);
}

int main(){
    Node* l1 = new Node(9);
Node* l2 = new Node(2);
Node* l3 = new Node(3);
print(plusNum(l1, l2, l3));
}
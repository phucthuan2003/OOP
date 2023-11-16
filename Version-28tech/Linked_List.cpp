#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node node;

node* makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void duyet(node *head){
    while(head != nullptr){
        cout << head->data << " "; 
        head = head->next;
    }
}

int main (){

}
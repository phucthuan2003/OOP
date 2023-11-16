#include <bits/stdc++.h>

#ifndef ___Stack_for_Node____cpp____
#define ___Stack_for_Node____cpp____

using namespace std;

template <class T>

class Node{
    private:    
        T elem;
        Node<T> *next;
    public:
        Node<T> (T x , Node<T> *N = nullptr){
            elem = x;
            next = N;
        }
        Node<T> *getNext(){
            return next;
        }
        T &getElem(){
            return elem;
        }
};

template <class T>

class LinkedStack{
    private:
        unsigned num;
        Node<T> *head;
    public:
        LinkedStack(){
            num = 0 ;
            head = nullptr;
        }
        unsigned size(){
            return num;
        }
        bool empty(){
            return num == 0;
        }
        T &top(){
            return head->getElem();
        }
        void pop(){
            if(num <= 1 ){
                delete head;
                head = nullptr;
            }else{
                Node<T> *temp = head;
                head = head->getNext();
                delete temp;
            }
            num--;
        }
        void push(T x){
            head = new Node<T>(x , head);
            num++;
        }
        ~LinkedStack(){
            while(!empty()){
                pop();
            }
        }
};  
#endif
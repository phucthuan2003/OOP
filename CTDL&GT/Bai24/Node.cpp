#include <bits/stdc++.h>
#ifndef ___Node__cpp__
#define ___Node__cpp__

using namespace std;
// Định nghĩa lớp Node
template <class T>
class Node{
    private:
        T elem;
        Node <T> *next;
        Node <T> *prev;
    public:
        Node(){
            next = nullptr;
            prev = nullptr;
        }
        Node(T elem){
            this->elem = elem;
            next = nullptr;
            prev = nullptr;
        }
        Node(T x , Node<T> *Left=0 , Node<T> *Right=0){
            elem = x;
            prev = Left;
            next = Right;
        }
        T &getElem(){
            return elem;
        }
        Node<T> *&getPrev(){
            return prev;
        }
        Node<T> *&getNext(){
            return next;
        }
        void setElem(T x){
            elem = x;
        }
        void setPrev(Node<T> *p = nullptr){
            prev = p;
        }
        void setNext(Node<T> *p = nullptr){
            next = p;
        }
};
#endif
#include <bits/stdc++.h>

#ifndef ___Node___cpp___
#define ___Node___cpp___

using namespace std;

template <class T>
class Node{
    private:
        T elem;
        Node <T> *prev;
        Node <T> *next;
    public:
        Node(T x , Node<T> *L=0 , Node<T> *R=0){
            elem = x;
            prev = L;
            next = R;
        }
        T &getelem(){
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
        void setPrev(Node<T> *p=nullptr){
            prev = p;
        }
        void setNext(Node<T> *p=nullptr){
            next = p;
        }
};
#endif
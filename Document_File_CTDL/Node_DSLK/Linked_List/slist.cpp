#include <bits/stdc++.h>
#include "Node.cpp"
#include "slist_iterator.cpp"
#ifndef ___slist___cpp___
#define ___slist___cpp___

using namespace std;

template<class T>
class slist{
    private:
        Node<T> *head;
        Node<T> *tail;
        unsigned int num; // so phan tu hien tai trong list ->size
    public:
        typedef slist_iterator<T> iterator;
        slist(){
            head = tail = nullptr;
            num = 0;
        }
        slist(int k , T x){
            head = tail = nullptr;
            num = 0;
            for(int i=1 ; i<=k ; i++){
                push_back(x);
            }
        }
        iterator begin(){
            return head;
        }
        iterator end(){
            return nullptr;
        }

        unsigned size(){
            return num;
        }
        bool empty(){
            return num == 0;
        }
        T &front(){
            return head ->getelem();
        }
        T &back(){
            return tail ->getelem();
        }
        void push_front(T x){
            head = new Node<T>(x,head);
            if(num == 0)
                tail = head;
            num++;
        }
        void push_back(T x){
            if(num == 0) 
                push_front(x);
            else{
                tail->setNext(new Node<T>(x,nullptr));
                tail = tail->getNext();
                num++;
            }
        }
        void pop_front(){
            if(num == 0) 
                return ;
            if(num == 1){
                head = tail = nullptr;
            } 
            else{
                head = head ->getNext();
            }
            num--;
        }
        void pop_back(){
            if(num == 0) 
                return ;
            if(num == 1){
                head = tail = nullptr;
                num--;
                return;
            }
            Node<T> *p = head;
            while(p->getNext() != tail)
                p = p->getNext();
            p->setNext(nullptr);
            tail = p;
            num--;
        }
};
#endif
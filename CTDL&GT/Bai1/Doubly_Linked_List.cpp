#include <bits/stdc++.h>
#include "Node.cpp"
#include "Iterator_List.cpp"

#ifndef ___Doubly_Linked_List___cpp___
#define ___Doubly_Linked_List___cpp___

using namespace std;

template<class T>

class Doubly_Linked_List{
    private:
        Node<T> *head;
        Node<T> *tail;
        unsigned int num; // số phần tử hiện tại trong list (size)
    public:
        typedef Iterator_List<T> iterator;
        Doubly_Linked_List(){
            head = nullptr;
            tail = nullptr;
            num = 0;
        }
        Doubly_Linked_List(int k , T x){
            head = nullptr;
            tail = nullptr;
            num = 0 ; 
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
            return num == 0 ;
        }
        T &front(){
            return head ->getElem();
        }
        T &back(){
            return tail ->getElem();
        }
        void push_front(T x){
            Node<T> *newNode = new Node<T>(x , nullptr , head);
            if(num == 0 ){
                head = tail = newNode;
            }else{
                head->setPrev(newNode);
                head = newNode;
            }
            num++;
        }
        void push_back(T x){
            Node<T> *newNode = new Node<T>(x , tail , nullptr);
            if(num == 0){
                push_front(x);
            } else{
                tail->setNext(newNode);
                tail = newNode;
                num++;
            }
        }
        void pop_front(){
            if(num == 0){
                return ;
            }
            if(num == 1){
                head = tail = nullptr;
            } else{
                head = head ->getNext();
            }
            num --;
        }
        void pop_back(){
            if(num == 0){
                return ;
            }
            if(num == 1){
                head = tail = nullptr;
                num--;
                return;
            }
            Node<T> *p = head;
            while(p->getNext() != tail){
                p = p->getNext();
            }
            p->setNext(nullptr);
            tail = p;
            num--;
        }
        iterator remove(iterator it) {
            Node<T>* toRemove = it.getCurr();
            if (toRemove == nullptr) {
                return iterator(nullptr);
            }
            Node<T>* prev = toRemove->getPrev();
            Node<T>* next = toRemove->getNext();
            if (prev != nullptr) {
                prev->setNext(next);
            } else {
                head = next;
            }
            if (next != nullptr) {
                next->setPrev(prev);
            } else {
                tail = prev;
            }
            Node<T>* nextNode = (next != nullptr) ? next : prev;
            delete toRemove;
            num--;
            return iterator(nextNode);
        }
        void traverse(){
            Node<T> *current = head;
            while(current != nullptr){
                cout << current->getElem() << "  " ;
                current = current->getNext();
                cout << endl;
            }
        } 
};
#endif
#include <bits/stdc++.h>
#include "Node.cpp"

#ifndef ___Iterator_List___cpp___
#define ___Iterator_List___cpp___

using namespace std;

template<class T>
class Iterator_List{
    private:    
        Node<T> *curr; // con trỏ trỏ vào node hiện tại
    public: 
        Iterator_List(){
            curr = nullptr;
        }
        Iterator_List(Node<T> *p){
            curr = p;
        }
        Node<T> *getCurr(){
            return curr;
        }
        Iterator_List<T> &operator = (Iterator_List<T> p){
            this->curr = p.getCurr();
            return *this;
        }
        bool operator != (Iterator_List<T> p){
            return curr != p.getCurr();
        }
        void remove() {
            if (curr == nullptr) {
                return;
            }
            Node<T>* prev = curr->getPrev();
            Node<T>* next = curr->getNext();

            if (prev != nullptr) {
                prev->setNext(next);
            }
            if (next != nullptr) {
                next->setPrev(prev);
            }
            delete curr;
        }
        // Bộ duyệt xuôi
        Iterator_List<T> operator++(){
            curr = curr->getNext();
            return curr; // tự động ép kiểu thành iterator vì có hàm tạo có đối
        }
        // Bộ duyệt ngược 
        Iterator_List<T> operator--(){
            curr = curr->getPrev();
            return *this;
        }
        Iterator_List<T> operator++(int){
            Node<T> *temp = curr;
            curr = curr->getNext();
            return temp;
        }
        T &operator*(){
            return curr->getElem();
        }
        // Thêm vào đầu danh sách
        void addFront(T x , Node<T>*& head){
            Node<T> *newNode = new Node<T>(x , nullptr , head);
            if(head != nullptr){
                head->setPrev(newNode);
            }
            head = newNode;
        }
        // Thêm vào cuối danh sách
        void addBack(T x , Node<T>*& tail){
            Node<T> *newNode = new Node<T>(x , tail , nullptr);
            if(tail != nullptr){
                tail->setNext(newNode);
            }
            tail = newNode;
        }
        // Xóa khỏi đầu danh sach
        Node<T>* removeFront(Node<T>*& head){
            if(head == nullptr){
                return nullptr; 
            }
            Node<T> *removed = head;
            head = head->getNext();
            if(head != nullptr){
                head->setPrev(nullptr);
            }
            return removed;
        }
        // Xoa khoi cuoi danh sach
        Node<T>* removeBack(Node<T>*& tail){
            if(tail == nullptr){
                return nullptr;
            }
            Node<T>* removed = tail;
            tail = tail->getPrev();
            if(tail != nullptr){
                tail->setNext(nullptr);
            }
            return removed;
        }
};
#endif
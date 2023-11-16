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
        Iterator_List<T> operator++(){
            curr = curr->getNext();
            return curr; // tự động ép kiểu thành iterator vì có hàm tạo có đối
        }
        Iterator_List<T> operator++(int){
            Node<T> *temp = curr;
            curr = curr->getNext();
            return temp;
        }
        T &operator*(){
            return curr->getElem();
        }
};
#endif
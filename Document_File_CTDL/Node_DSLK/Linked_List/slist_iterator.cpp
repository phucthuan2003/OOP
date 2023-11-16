#include <bits/stdc++.h>
#include "Node.cpp"
#ifndef ___slist_iterator___cpp___
#define ___slist_iterator___cpp___

using namespace std;
template<class T>
class slist_iterator{
    private:
        Node<T> *curr ; // con trỏ trỏ vào node hiện tại 
    public:
        slist_iterator(){
            curr = nullptr;
        }
        slist_iterator(Node<T> *p){
            curr = p ;
        }
        Node<T> *getcurr(){
            return curr;
        }
        slist_iterator<T> &operator = (slist_iterator<T> p){
            this->curr = p.getcurr();
            return *this;
        }
        bool operator != (slist_iterator<T> p){
            return curr != p.getcurr();
        } 
        slist_iterator<T> operator++() // ++curr
        {
            curr = curr->getNext();
            return curr; // tự động ép kiểu thành iterator vì có hàm tạo có đối
        }
        slist_iterator<T> operator++(int) // ++curr
        {
            Node<T> *temp = curr;
            curr = curr->getNext();
            return temp;
        }
        T &operator*(){
            return curr->getelem();
        }
};
#endif
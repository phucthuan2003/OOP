//Cai dat stack bang node
#include <bits/stdc++.h>
using namespace std;
#ifndef __nodestack__cpp
#define __nodestack__cpp
template <class T>
class node{
    private:
        T elem;
        node<T> *next;
	public:
        node<T> (T x,node<T> *N=nullptr){
            elem = x;
            next = N;
        }
        node<T> &getnext(){ 
            return next;
        }
        T &getelem(){
            return elem;
        }
};
template<class T>
class STACK{
    private:
        unsigned num;
        node<T> *H;//head
	public:
		STACK(){
            num=0;
            H=nullptr;
        }
		unsigned size(){
            return num;
        }
		bool empty(){
            return num==0;
        }
		T &top(){
            return H->elem;
        }
		void pop(){
			if(num<=1){
                num=0;
                H=nullptr;
                return;
            }
			H=H->getnext();
			num--;
		}
		void push(T x){
			H = new node<T>(x,H);
			num++;
		}
};
#endif
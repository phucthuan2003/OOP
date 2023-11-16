#include <bits/stdc++.h>

#ifndef ___Stack_for_Array___cpp___
#define ___Stack_for_Array___cpp___

using namespace std;

template <class T>

class ArrayStack{
    private:
        int num , cap; // cap: sức chứa ; num: size hiện tại
        T *elem;
    public:
        ArrayStack(){
            num = cap = 0;
            elem = nullptr;
        }
        int size(){
            return num;
        }
        bool empty(){
            return num == 0;
        }
        T &top(){
            return elem[num - 1];
        }
        void pop(){
            num--;
        }
        void push(T x){
            if(cap == num){
                cap = cap?cap*2:1;
                T *temp = new T[cap];
                for(int i=0 ; i<num ; i++){
                    temp[i] = elem[i];
                }
                if(elem){
                    delete []elem;
                }
                elem = temp;
            }
            elem[num++] = x;
        }
        void clear(){
            num = 0 ;
            if(elem){
                delete [] elem;
                elem = nullptr;
            }
        }
        ~ArrayStack(){
            clear();
        }
};
#endif

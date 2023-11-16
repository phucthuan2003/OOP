//cai dat stack bang mang
#include<bits/stdc++.h>
using namespace std;
#ifndef stack__cpp
#define stack__cpp
template <class T>
class Stack
{
	int num,cap; //cap-suc chua, num-size hien tai
	T *elem;
	public:
		Stack() {
            num=cap=0; 
            elem=NULL;
        }
		int size() {
            return num;
        }
		bool empty() {
            return num==0;
        }
		T &top() {
            return elem[num-1];
        }
		void pop() {
            num--;
        }
		void push(T x)
		{
			if(cap==num)
			{
				cap=cap?cap*2:1;
				T *tem=new T[cap]; 
				for(int i=0;i<num;i++) 
                    tem[i]=elem[i];
				if(elem) 
                    delete []elem;
				elem=tem;
			}
			elem[num++] = x; 
		}
		void clear() {num=0;}
};
#endif
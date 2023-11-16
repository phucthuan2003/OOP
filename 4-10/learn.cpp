#include <bits/stdc++.h>

using namespace std;

class A{
    private:
        int a1 ; 
        int *a2;
    public:
        A(){
            a2 = new int ;
            a1 = *a2 = 0;
        }
        A(int x , int y ){
            a1 = x;
            a2 = new int ;
            *a2 = y;
        }
        A(const A &x){
            a1 = x.a1;
            a2 = new int;
            *a2 = *(x.a2);
        }
        A &operator = (const A&x){
            a1 = x.a1;
            a2 = new int;
            *a2 = *(x.a2);
            return *this;
        }
        void display(){
            cout << a1 << "  " << *a2;
        }
        ~A(){
            delete a2;
        }
};
class B : public A{
    private:
        int b;
    public:
        B() : A() {
            b = 1;
        }
        B(int x ) : A(){
            b = x;
        }
        B(int a , int b , int c) : A(a , b){
            this->b = c;
        }
        ~B(){}
        B(const B &x) : A((A)x){
            b = x.b;
        }
        B &operator = (const B &x){
            b = x.b;
            A :: operator = ((A)x);
            return *this;
        }
        void display(){
            A :: display();
            cout << "  " << b << " ";
        }
};

int main (){
    A a(1 ,2);
    a.display();
    B b(5,4,4);
    cout << endl;
    b.display();
    cout << endl;
    
}

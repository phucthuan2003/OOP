#include <bits/stdc++.h> 

using namespace std;

class A{
    private:
        int a1, a2 , *a3;
    public:
        A(){
            a3 = new int ;
            a1 = a2 = *a3 = 0;
        }
        ~A(){
            delete a3;
        }
        A(int x , int y , int z){
            a1 = x;
            a2 = y;
            a3 = new int;
            *a3 = z;
        }
        A(const A &x){
            a1 = x.a1;
            a2 = x.a2;
            a3 = new int ;
            *a3 = *(x.a3);
        }
        A &operator = (const A &x){
            a1 = x.a1;
            a2 = x.a2;
            a3 = new int ;
            *a3 = *(x.a3);
            return *this;
        }
        void display (){
            cout << a1 << "  " << a2 << "  " << *a3 ;
        }
};

class B : public A{
    private:
        int *b1 , *b2;
    public:
        B() : A(){
            b1 = new int ;
            b2 = new int ;
            *b1 = *b2 = 1;
        }
        B(int x , int y) : A(){
            b1 = new int ;
            b2 = new int ;
            *b1 = x;
            *b2 = y;
        }
        B(int a , int b , int c , int d , int e) : A(a , b , c){
            b1 = new int ;
            b2 = new int ;
            *b1 = d;
            *b2 = e;

        }
    ~B(){}
    B(const B &x) : A((A)x){
        b1 = new int ;
        b2 = new int ;
        *b1 = *(x.b1);
        *b2 = *(x.b2);
    }
    B &operator = (const B &x){
        b1 = new int ;
        b2 = new int ;
        *b1 = *(x.b1);
        *b2 = *(x.b2);
        A :: operator=((A)x);
        return *this;
    }
    void display(){
        A :: display();
        cout << " " << *b1 << " " << *b2 << " ";
    }
};

int main (){
    A a(1 , 2 , 3);
    a.display();
    B b(4,5,6,7,8);
    cout << endl;
    b.display();
    cout << endl;
}
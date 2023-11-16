#include <bits/stdc++.h>

using namespace std;

class Dathuc{
    private:
        int bac;
        int *heso;
    public:
        Dathuc(){
            bac = 0;
            heso = nullptr;
        }
        Dathuc(int bac , int *heso){
            this->bac = bac;
            heso = new int[bac+1];
            for(int i=0 ; i<=bac ; i++){
                this->heso[i] = heso[i];
            }
        }
        void input(){
            cout << "Nhap bac cua da thuc:";
            cin >> bac;
            heso = new int[bac+1];
            for(int i=0 ; i<=bac ; i++ ){
                cin >> heso[i];
            }
        }
        void output(){
            for(int i=0 ; i<=bac ; i++){
                if(i == 0 ){
                    cout << heso[i] << "+";
                }else if(i == bac ){
                    cout << heso[i]<< "X^" << i ;
                } else{
                    cout << heso[i] << "X^" << i << "+";
                }
            }
        }
        long long daoham(){
            long long s=0;
            int x;
            cout << "Nhap X= ";
            cin >> x;
            for(int i=0 ; i<=bac ; i++){
                if(i==0){
                    s=0;
                }else {
                    s+= heso[i]*i*pow(x,i-1);
                }
            }
            return s;
        }
};

int main (){
    Dathuc a;
    a.input();
    a.output();
    cout << endl;
    long long k = a.daoham();
    cout << "S=" << k ;
}
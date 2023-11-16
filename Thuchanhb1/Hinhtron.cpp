#include <bits/stdc++.h>
using namespace std;

class HT{
    private:    
        float x , y ,r;
    public:
        HT(float x=0 , float y=0 , float r=1){
            this->x = x;
            this->y = y;
            (*this).r = r;
        }
        void nhap(){
            cout << "Nhap toa do tam: ";
            cin >> x >> y;
            do{
                cout << "Nhap ban kinh (r > 0) : ";
                cin >> r;
            }while (r<=0);
        }
        friend ostream &operator << (ostream &out , const HT &h){
            cout << "(" << h.x << ";" << h.y << ")" << "R: " << h.r ;
            return cout;
        }
        friend float dientich(const HT &t){
            return M_PI*t.r*t.r;
        }
        float getX(){ return x; }
        float getY(){ return y; }
        float getR(){ return r; }
};

class Hinhtron : public HT{
    private:
        int mau;
    public:
        Hinhtron(){
            mau = 0;
        }
        Hinhtron(float x , float y , float r , int mau) : HT(x , y , r){
            this->mau = mau;
        }
        int getMau(){
            return mau;
        }
        void nhap(){
            HT::nhap();
            do{
                cout << "Nhap mau(1:đỏ , 2:xanh , 3:vàng): ";
                cin >> mau;
            }while(mau != 1 && mau != 2 && mau != 3);
        }
        friend ostream &operator << (ostream &out ,Hinhtron h){
            cout << "(" << h.getX() << " ; " << h.getY() << ")" << "||  R: " << h.getR(); 
            cout << "  Mau: " << h.mau;
            return cout;
        }

};
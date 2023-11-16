#include <bits/stdc++.h>

using namespace std;

class Date{
    private:
        int day, month , year;
    public:
        Date(int d = 11 , int m = 10 , int y = 2023){
            day = d;
            month = m ;
            year = y ;
        }
        friend istream &operator >> (istream &cin , Date &d){
            cout << "Import Day: " ; cin >> d.day;
            cout << "Import Month: "; cin >> d.month;
            cout << "Import Year: "; cin >> d.year;
            return cin;
        }
        friend ostream& operator << (ostream &cout , Date d){
            cout << d.day << " / " << d.month << " / " << d.year << endl;
            return cout;
        }
};

class Nguoi{
    protected:
        string hoten;
        Date ngaysinh;
        string diachi;
    public: 
        Nguoi(string ht = "" , Date ngaysinh = Date(11,10,2023) , string dc=""){
            hoten = ht ;
            this->ngaysinh = ngaysinh;
            diachi = dc;
        }
        void nhap(){
            cout << "Nhap Ho Ten: " ; getline(cin , hoten);
            cout << "Nhap Ngay Sinh: " ; cin >> ngaysinh;
            cout << "Nhap Dia Chi: " ; getline(cin , diachi);
        }
        void xuat(){
            cout << hoten << " || " << ngaysinh << " || " << diachi << endl;
        }
        string getHoten(){
            return hoten;
        }

};

class KhachHang : public Nguoi{
    private:    
        string makhach;
        int csTruoc , csSau;
    public:
        KhachHang(string ma="" , string ht="" , Date ngaysinh=Date(1,1,2003) , string dc="" , int truoc=0 , int sau=0) : Nguoi(ht , ngaysinh , dc){
            makhach = ma;
            csTruoc = truoc;
            csSau = sau;
        }
        double tinhten(){
            int sodien = csSau - csTruoc;
            double tien = 0; 
            if(sodien <=50 ) tien = sodien*1678;
            else if(sodien <=100 ) tien = 500*1678 + (sodien - 50 )*1738;
            else if(sodien <=200) tien = 50*1678 + 50*1738 + (sodien - 100 )*2014;
            else if(sodien <=300) tien = 50*1678 + 50*1738 + 100*2014 + (sodien - 200)*2536;
            else tien = 50*1678 + 50*1738 + 100*2014 +(sodien - 300)*2834;
            return tien;
        }
        void xuat(){
            cout << makhach ;
            Nguoi::xuat();
            cout << " " << tinhten() << endl;
        }
        void nhap(){
            cout << "Nhap ma khac: " ; cin.ignore() ; getline(cin , makhach);
            Nguoi::nhap() ; cout << "Nhao so truoc , so sau: " ; cin >> csTruoc >> csSau;
        }
        
};
int main(){
    KhachHang a;
    a.nhap();
    a.xuat();
}
#include <bits/stdc++.h>

using namespace std;

class Customer{
private:
    string ID ;
    string Name;
    int soTruoc;
    int soSau;
public:
    Customer(){
        
    }
    Customer(string ID , string Name , int soTruoc , int soSau){
        this -> ID = ID;
        this -> Name = Name;
        this -> soTruoc = soTruoc;
        this -> soSau = soSau;
    }
    void input(){
        cout << "Nhap ID khach hang: " ;
        cin >> ID;
        cin.ignore();
        cout << "Nhap Ho va Ten: ";
        getline(cin , Name);
        cout << "Nhap so thang truoc: ";
        cin >> soTruoc;
        cout << "Nhap so thang sau: ";
        cin >> soSau;
    }
    void output(){
        cout << "ID: " << ID << " || " << "Ho va Ten: " << Name << " || " << "So Thang Truoc: " << soTruoc << " || " << "So Thang Sau: " << soSau;
    }
    double bill(){
        long long so = soSau - soTruoc;
        double Bill = 1 ;
        return  Bill = so*3000;
    }
    string getid(){
        return ID;
    }
    string getName(){
        return Name;
    }
    int getSotruoc(){
        return soTruoc;
    }
    int getSoSau(){
        return soSau;
    }
};
class KhachHang : public Customer{
private:
    int uutien;
public:
    KhachHang(string ID , string Name , int soSau , int soTruoc , int uutien) : Customer(ID , Name , soSau , soTruoc){
        this -> uutien = uutien;
    }
    KhachHang(){
        
    }
    void input(){
        Customer::input();
        do{
            cout << "Nhap Uu Tien: "; cin >> uutien;
        }while(uutien != 0 && uutien != 1 && uutien != 2); 
    }
    void output(){
        Customer::output();
    }
    long long bill(){
        long long BIll=1;
        if(uutien == 0) BIll = Customer::bill();
        if(uutien == 1) BIll = Customer::bill()*0.95;
        if(uutien == 2) BIll = Customer::bill()*0.9;
        return 1.0*BIll;
    }
    int getUutien(){
        return uutien;
    }
};
bool cmp(KhachHang a , KhachHang b){
    return a.bill() > b.bill();
}
class List : public KhachHang{
private:
    vector<KhachHang> list; 
public:
    void add_list(KhachHang add){
        list.push_back(add);
    }
    void SearchCustomer(string name){
        for(int i = 0 ; i < list.size() ; i++){
            if(list[i].getName() == name){
                list[i].output();
                cout << " || " << "Uu Tien: " << list[i].getUutien() << " || " << "BILL " << i + 1 << ":" << list[i].bill() << endl;
                return ;
            }
        }
        cout << "Not Found !" << endl;
    }
};

int main(){
    List list;
    KhachHang *a;
    int n;
    cout << "Nhap list:" ;
    cin >> n;
    cin.ignore();
    a = new KhachHang[n];
    for(int i=0 ; i<n ; i++ ){
        a[i].input();
        list.add_list(a[i]);
    }
    sort(a , a+n , cmp);
    cout << "Danh Sach Khach Hang Theo Thu Tu Giam Dan Tien Nop !\n";
    for(int i=0 ; i<n ; i++){
        a[i].output();
        cout << " || " << "Uu Tien: " << a[i].getUutien() << " || " << "BILL " << i + 1 << ":" << a[i].bill() << endl; 
    }
    string check;
    cin.ignore();
    cout << "Nhap Check: " ;
    getline(cin , check);  
    list.SearchCustomer(check);
}

#include <bits/stdc++.h>

using namespace std;

class Staff{
    private:
        string id , name , date;
    public: 
        Staff(){
        
        }
        
        Staff(string id , string name , string date){
            this->id = id;
            this->name = name;
            this->date = date;
        }
        // bool isValidDate(const string &inputDate) {
        //     if (inputDate.length() != 10) // Ngày tháng năm đúng 10 ký tự
        //         return false;

        //     for (int i = 0; i < 10; i++) {
        //         if ((i == 2 || i == 5) && inputDate[i] != '/')
        //             return false;
        //         else if (i != 2 && i != 5 && !isdigit(inputDate[i]))
        //             return false;
        //     }

        //     return true;
        // }

        void Input(){
            cout << "Import ID Staff: ";
            cin >> id;
            cin.ignore();
            cout << "Import Name Staff: ";
            getline(cin , name);
            // do{
            //     cout << "Import Date Staff (dd/mm/yyyy): ";
            //     getline(cin, date);
            // }while(!isValidDate(date));
            cout << "Import Date Staff (dd/mm/yyyy): ";
            getline(cin, date);
            
        }
        void Output(){
            cout << "ID: " << id << " || Name: " << name << " || Date: " << date << endl;
        }
        string getID(){
            return id;
        }
        string getName(){
            return name;
        }
        string getDate(){
            return date;
        }
        void setID(string id){
            this->id = id;
        }
        void setName(string name){
            this->name = name;
        }
        void setDate(string date){
            this->date = date;
        }
};

class Contracts : public Staff{
    private: 
        long tiencong;
        int ngaycong;
    public:
        Contracts(){

        }
        Contracts(string id , string name , string date , long tiencong , int ngaycong) : Staff(id , name , date){
            this->tiencong = tiencong;
            this->ngaycong = ngaycong;
        }
        void Input(){
            Staff::Input();
            cout << "Nhap Tien Cong: " ; cin >> tiencong;
            cout << "Nhap Ngay Cong: " ; cin >> ngaycong;
        }
        void Output(){
            cout << "ID: " << Staff::getID() << " || Name: " << Staff::getName() << " || Date: " << Staff::getDate()  << " || Tien Cong: " 
            << tiencong << " || Ngay Cong: " << ngaycong  << " || Tinh Luong :" << tinhluong()<< endl;
        }
        float tinhluong(){
            return tiencong*ngaycong;
        }
        int getAge(){
            int brith = stoi(Staff::getDate().substr(6 , 4));
            int hientai = 2023;
            return hientai - brith;
        }
};

bool cmp(Contracts a , Contracts b){
    return a.tinhluong() > b.tinhluong();
}

int main (){
    int n ;
    cout << "Import List Contracts: "; cin >> n;
    Contracts *a = new Contracts[n];
    for(int i=0 ; i<n ; i++){
        a[i].Input();
    }
    for(int i=0 ; i<n ; i++){
        a[i].Output();
    }
    int flags = 0;
    string check;
    cin.ignore();
    long long S=0;
    for(int i=0 ; i<n ; i++ ){
        S+= a[i].tinhluong();
    }
    cout << "Import Check: " ; getline(cin ,check);
    for(int i=0 ; i<n ; i++){
        if(a[i].getName() == check){
            a[i].Output();
            flags = 1;
        }
    }
    if(flags == 0) cout << "Not Found!" << endl;

    int check1 = -1;
    int minAge = INT_MAX;
    for (int i = 1; i < n; ++i) {
        if (a[i].getAge() < minAge) {
            minAge = a[i].getAge();
            check1 = i;
        }
    }
    if (check1 != -1) {
        cout << "Nhan Vien Tre Nhat: ";
        a[check1].Output();
    }
    else {
        cout << "Not Found\n" << endl;
    }
    sort(a , a+n , cmp);
    cout << "List End!" << endl;
    for(int i=0 ; i<n ; i++){
        a[i].Output();
    }
    cout << endl;
    cout << "Tong Tien Luong: \n" << (double)S ;

}
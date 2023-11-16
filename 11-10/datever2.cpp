#include <bits/stdc++.h>

using namespace std;

class Date{
    private:
        int day ;
        int month;
        int year;
    public:
        Date(){}
        Date(int day , int month , int year){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        void input(){
            cout << "Import Day: " ; cin >> day;
            cout << "Import Month: " ; cin >> month;
            cout << "Import Year: " ; cin >> year;
        }
        string output(){
            return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        }
};
class People {
    private:
        string FullName;
        Date date;
        string address;
    public: 
        People(string FullName , Date date , string address){
            this->FullName = FullName;
            this->date = date;
            this->address = address;
        }
        People(){}
        void input(){
            cout << "Import Full Name: "; 
            getline(cin , FullName);
            cout << "Import Date! \n";
            date.input();
            cout << "Import Address: " ;
            cin.ignore();
            getline(cin , address);
        }
        void output(){
            cout << "Full Name: " << FullName << " || "  << "Date: " << date.output() << " || " << "Address: " << address << " || ";
        }
        string getFull_Name(){
            return FullName;
        }
};

class Customer : public People{
    private:
        string ID_Customer;
        int previous_number;
        int next_number;
    public:
        Customer(string ID_Customer , string FullName , Date date , string address, int previous_number , int next_number) : People (FullName , date , address) {
            this->ID_Customer = ID_Customer;
            this->previous_number = previous_number;
            this->next_number = next_number;
        } 
        Customer(){}
        double bill(){
            int electricity_number = previous_number - next_number;
            double money = 0 ;
            if(electricity_number <= 50 ) money = electricity_number*1678;
            else if(electricity_number <= 100) money = 50*1678 + (electricity_number - 50 )*1738;
            else if(electricity_number <= 200) money = 50*1678 + 100*1738 + (electricity_number - 100)*2014;
            else if(electricity_number <= 300) money = 50*1678 + 100*1738 + 200*2014 + (electricity_number - 200)*2536;
            else money = 50*1678 + 100*1738 + 200*2014 + (electricity_number - 300 )*2834;
            return money;
        }
        void input(){
            cout << "Import ID Customer: ";
            cin.ignore();
            getline(cin , ID_Customer);
            People::input();
            cout << "Import Previous Number: ";  cin >> previous_number;
            cout << "Import Next Number: "; cin >> next_number;
        }
        void output(){
            cout << "ID Customer: " << ID_Customer << " || " ; 
            People::output();
            cout << "BILL: " << bill() << endl;
        }
        bool Search_Name(string name){
            if(getFull_Name() == name){
                return 1;
            }
            return 0;
        }
        void Statistical(){
            int electricity_number = previous_number - next_number;
            if(electricity_number > 0 && electricity_number <=50){
                cout << "Bac 1: " ;
                output();
            }
            if(electricity_number >50 && electricity_number <=100){
                cout << "Bac 2: " ;
                output();
            }
            if(electricity_number > 100 && electricity_number <= 200){
                cout << "Bac 3: " ;
                output();
            }
            if(electricity_number > 200 && electricity_number <=300){
                cout << "Bac 4: " ;
                output();
            }
            if(electricity_number > 300 ){
                cout << "Bac 5: " ;
                output();
            }
        }
};

int main (){
    Customer *a;
    int n;
    cout << "Import List Customer: " ; cin >> n;
    a = new Customer[n];
    for(int i=0 ; i<n ; i++){
        a[i].input();
    }
    for(int i=0 ; i<n ; i++){
        a[i].output();
    }
    string check;
    cin.ignore();
    cout << "Import Name Check: " ; getline(cin , check);
    int flag = 1;
    for(int i=0 ; i<n ; i++){
        if(a[i].Search_Name(check)){
            a[i].output();
            flag = 0;
        }
    }
    if(flag == 1) cout << "Not Found Name! \n";
    cout << "List Statistical !\n";
    for(int i=0 ; i<n ; i++){
        a[i].Statistical();
    }
}
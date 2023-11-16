#include<bits/stdc++.h>
#include "myvector.cpp"

#ifndef __Contact__cpp__
#define __Contact__cpp__

using namespace std;

class Contact{
private:
   string name;
   string phoneNumber;
   string email;
public:
   Contact(string name , string phoneNumber , string email){
       this -> name = name;
       this -> phoneNumber = phoneNumber;
       this -> email = email;
   }
   Contact(){

   }
   string getName(){
       return name;
   }
   string getPhoneNumber(){
       return phoneNumber;
   }
   string getEmail(){
       return email;
   }
   void input(){
       cout << "Import Name: " ;
       getline(cin , name);
       cout << "Import PhoneNumber: " ;
       cin >> phoneNumber;
       cout << "Import Email: ";
       cin.ignore();
       getline(cin , email);
   }
   void display(){
       cout << "Name: " << name << endl;
       cout << "Phone number: " << phoneNumber << endl;
       cout << "Email: " << email << endl;
   }
};
#endif
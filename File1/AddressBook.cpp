#include<bits/stdc++.h>
#include "myvector.cpp"
#include "Contact.cpp"
using namespace std;

class AddressBook : public Contact{
   vector<Contact> contacts;
public :
   void input(){
       Contact::input();
   }
   void display(){
       Contact::display();
   }
   void addContact(Contact contact){
       contacts.push_back(contact);
   }
   void removeContact(string phone){
       for(int i=0 ; i < contacts.size() ; i++ ){
           if(contacts[i].getPhoneNumber() == phone){
               contacts.erase(contacts.begin() + i);
               cout << "Contact removed successfully." <<endl;
               return;
           }
       }
   }
   void searchContact(string phone){
       for(int i=0 ; i < contacts.size() ; i++){
           if(contacts[i].getPhoneNumber() == phone ){
               contacts[i].display();
               return;
           }
       }
       cout << "Contact not found." <<endl;
   }
   void displayAllContacts() {
       for (int i = 0; i < contacts.size(); i++) {
           contacts[i].display();
           cout << endl;
       }
   }
};
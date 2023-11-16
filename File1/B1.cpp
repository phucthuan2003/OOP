#include<bits/stdc++.h>
#include "Contact.cpp"
#include "AddressBook.cpp"
using namespace std;

int main(){
   AddressBook addressbook;
   int n;
   cout << "Import List: ";
   cin >> n;
   cin.ignore();
   Contact *a;
   a = new Contact[n];
   for(int i=0 ; i<n ; i++){
       a[i].input();
       addressbook.addContact(a[i]);
   }
   string check;
   cout << "Import Check: ";
   getline(cin , check);
   addressbook.searchContact(check);
   addressbook.removeContact(check);
   addressbook.displayAllContacts();
}

#include <bits/stdc++.h>
#include "Node.cpp"
#include "Doubly_Linked_List.cpp"
#include "Iterator_List.cpp"

#ifndef ___Student___cpp___
#define ___Student___cpp___

using namespace std ;

class Student{
    private:
        string Id , Name , Date , Class;
        int Gender ;
    public :
        Student& operator = (const Student& other){
            if(this != &other){
                this->Id = other.Id;
                this->Name = other.Name;
                this->Date = other.Date;
                this->Class = other.Class;
                this->Gender = other.Gender;
            }
            return *this;
        }
        
        friend ostream& operator<<(ostream& os,  Student student){
            os << "Student ID: " << student.getID() << " ||  Name: " << student.getName() << " || Date: "  << student.getDate()
            << " || Class: " << student.getClass() << " || Gender: " << student.getGender() << endl;
            return os;
        }
        string getID(){
            return Id;
        }
        string getName(){
            return Name;
        }
        string getDate(){
            return Date;
        }
        string getClass(){
            return Class;
        }
        int getGender(){
            return Gender;
        }
        void setID(string Id){
            this->Id = Id;
        }
        void setName(string Name){
            this->Name = Name;
        }
        void setDate(string Date){
            this->Date = Date;
        }
        void setClass(string Class){
            this->Class = Class;
        }
        void setGender(int Gender){
            this->Gender = Gender;
        }
};
#endif

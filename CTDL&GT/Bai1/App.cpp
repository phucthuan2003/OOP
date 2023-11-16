#include <bits/stdc++.h>
#include "Node.cpp"
#include "Doubly_Linked_List.cpp"
#include "Iterator_List.cpp"
#include "Student.cpp"


#ifndef ___App___cpp___
#define ___App___cpp___

using namespace std;

class App{
    private:
        Doubly_Linked_List<Student> studentList;
    public:
        void runMenu();
        void size(){
            int k = studentList.size();
            cout << "Số Lượng:" << k;
        }
        void readStudentFromFile(const string& filename){
            ifstream inputFile(filename);
            if(inputFile.is_open()){
                string id, name, date, className;
                int gender;
                while (getline(inputFile, id)) {
                    getline(inputFile, name);
                    getline(inputFile, date);
                    getline(inputFile, className);
                    inputFile >> gender;
                    inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
                    Student newStudent;
                    newStudent.setID(id);
                    newStudent.setName(name);
                    newStudent.setDate(date);
                    newStudent.setClass(className);
                    newStudent.setGender(gender);
                    studentList.push_back(newStudent);
                }
                inputFile.close();
                cout << "File '" << filename << "' successfully read and students added to the list." << endl;
            } else {
                cout << "Unable to open file!" << endl;
            }
        }
        void input() {
            int numberOfStudents;
            cout << "Enter the number of students you want to input: ";
            cin >> numberOfStudents;
            for (int i = 0; i < numberOfStudents; i++) {
                string id, name, date, className;
                int gender;
                cout << "Enter Student " << (i + 1) << endl;
                cout << "\tImport Student ID: " ; cin >> id;
                cin.ignore();
                cout << "\tImport Student Name: " ;
                getline(cin , name);
                cout << "\tImport Student Date: " ;
                getline(cin , date);
                cout << "\tImport Student ClassName: " ;
                getline(cin , className);
                cout << "\tImport Student Gender: " ;
                cin >> gender; 
                Student newStudent;
                newStudent.setID(id);
                newStudent.setName(name);
                newStudent.setDate(date);
                newStudent.setClass(className);
                newStudent.setGender(gender);
                // Thêm sinh viên
                addStudent(newStudent);
            }
            cout << "Input of " << numberOfStudents << " students completed." << endl;
        }
        void writeStudentToFile(const string& filename){
            ofstream outputFile(filename);
            if(outputFile.is_open()){
                Doubly_Linked_List<Student>::iterator it = studentList.begin();
                while(it != studentList.end()){
                    outputFile << "Student ID: " << it.getCurr()->getElem().getID() << " || Student Name:  " << it.getCurr()->getElem().getName() << " || Student Date: " << it.getCurr()->getElem().getDate()
                    << " || Student Class: " << it.getCurr()->getElem().getClass() << " || Student Gender:  " << it.getCurr()->getElem().getGender();
                    outputFile << endl; 
                    ++it;
                }
                outputFile.close();
                cout << "Student data written to file '" << filename << "'." << endl;
            } else{
                cout << "Unable to create File !" << endl;
            }
        }
        // Nhập thêm 1 sinh viên vào cuối danh sách
        void addStudent(const Student& newStudent){
            studentList.push_back(newStudent);
        }
        void deleteStudent(const string& studentID){
            Doubly_Linked_List<Student>::iterator it = studentList.begin();
            bool found = false;
            while (it != studentList.end()) {
                if (it.getCurr()->getElem().getID().find(studentID) != string::npos) {
                    it = studentList.remove(it);
                    found = true;
                    cout << "Student with ID " << studentID << " deleted successfully!" << endl;
                    break;
                } else {
                    ++it;
                }
            }
            if (!found) {
                cout << "Student with ID " << studentID << " not found in the file!" << endl;
            }
        }
        void displayStudent(){
            studentList.traverse();
        }
        // Cập nhật thông tin của sinh viên 
        void updateStudentInfo(const string& studentID , Student updateInfo){
            bool studentFound = false;
            Doubly_Linked_List<Student>::iterator it = studentList.begin();
            while(it != studentList.end()){
                if(it.getCurr()->getElem().getID().find(studentID) != string::npos){
                    cout << "Updating student with ID: " << studentID << endl;
                    it.getCurr()->getElem().setName(updateInfo.getName());
                    it.getCurr()->getElem().setDate(updateInfo.getDate());
                    it.getCurr()->getElem().setClass(updateInfo.getClass());
                    it.getCurr()->getElem().setGender(updateInfo.getGender());
                    studentFound = true;
                    cout << "Student information after update: \n" << "Name: "<< it.getCurr()->getElem().getName()
                    << " || Date: " << it.getCurr()->getElem().getDate() << " || Class:" << it.getCurr()->getElem().getClass() 
                    << " || Gender: " << it.getCurr()->getElem().getGender() << endl;
                    break;
                }
                ++it;
            }
            if (!studentFound) {
                cout << "Student with ID " << studentID << " not found in the list!" << endl;
            }
        }
        bool isStudentExists(App& app, const string& studentID) {
            Doubly_Linked_List<Student>::iterator it = app.studentList.begin();
            while (it != app.studentList.end()) {
                if (it.getCurr()->getElem().getID() == studentID) {
                    return true; // Sinh viên tồn tại trong danh sách
                }
                ++it;
            }
            return false; // Sinh viên không tồn tại trong danh sách
        }
        // Tìm sinh viên theo họ và tên 
        void searchStudentByName(const string& name){
            Doubly_Linked_List<Student>::iterator it = studentList.begin();
            bool found = false;
            while(it != studentList.end()){
                if(it.getCurr()->getElem().getName()  == name){
                    cout << "Student Found: " << it.getCurr()->getElem().getID() << " || Name: " << it.getCurr()->getElem().getName() << " || Date: " << it.getCurr()->getElem().getDate() 
                        << " || Class: " << it.getCurr()->getElem().getClass() << " || Gender: " << it.getCurr()->getElem().getGender() << endl;
                    found = true;
                }
                ++it;
            }
            if(!found){
                cout << "Student with name " << name << " Not Found" << endl;
            }
        }
};

void App::runMenu(){
    int choice;
    string filename , id , name , date , className;
    int gender;
    do{
        cout << "\n================== MENU =================" << endl;
        cout << "1. Read student list from file" << endl;
        cout << "2. Record the student list into the file" << endl;
        cout << "3. Add a student to the end of the list" << endl;
        cout << "4. Delete a student by student ID" << endl;
        cout << "5. Displays all List" << endl;
        cout << "6. Update student information by student ID." << endl;
        cout << "7. Search students by first and last name" << endl;
        cout << "8. Exit the program" << endl;
        cin >> choice;
        switch(choice){
            case 1:{
                cout << "Import File Read Name: ";
                cin >> filename;
                readStudentFromFile(filename);
                break;
            }  
            case 2:{
                cout << "Import File Record Name: ";
                cin >> filename;
                writeStudentToFile(filename);
                break;
            }
            case 3:{
                cout << "Import Information Student New:" << endl;
                cout << "ID: "; cin >> id;
                cout << "Name: "; cin.ignore(); getline(cin, name);
                cout << "Date: "; getline(cin, date);
                cout << "Class: "; getline(cin, className);
                cout << "Gender: "; cin >> gender;
                Student newStudent;
                newStudent.setID(id);
                newStudent.setName(name);
                newStudent.setDate(date);
                newStudent.setClass(className);
                newStudent.setGender(gender);
                addStudent(newStudent);
                break;
            }  
            case 4:{
                cout << "Import ID Student Want Remove: ";
                cin >> id;
                deleteStudent(id);
                break;
            }  
            case 5:{
                displayStudent();
                break;
            }   
            case 6:{
                cout << "Enter the student ID that needs updating: ";
                cin >> id;
                cout << "Enter update information:" << endl;
                cout << "Name: "; cin.ignore(); getline(cin, name);
                cout << "Date: "; getline(cin, date);
                cout << "Class: "; getline(cin, className);
                cout << "Gender: "; cin >> gender;
                Student updatedInfo;
                updatedInfo.setID(id);
                updatedInfo.setName(name);
                updatedInfo.setDate(date);
                updatedInfo.setClass(className);
                updatedInfo.setGender(gender);
                updateStudentInfo(id, updatedInfo);
                break;
            }
            case 7:{
                cout << "Enter the name to search: ";
                cin.ignore();
                getline(cin, name);
                searchStudentByName(name);
                break;
            }
            case 8:
                cout << "Exit the program." << endl;
                break;
            default:
                cout << "Invalid selection. Please select again." << endl;
        }
    }while(choice != 8);
}
#endif
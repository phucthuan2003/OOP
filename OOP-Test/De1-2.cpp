#include <bits/stdc++.h>

using namespace std;

class Person
{
private:
    string Name;
    int date;

public:
    Person()
    {
    }
    Person(string Name, int date)
    {
        this->Name = Name;
        this->date = date;
    }
    void Input()
    {
        cin.ignore();
        cout << "Import Name: ";
        getline(cin, Name);
        cout << "Import Date: ";
        cin >> date;
    }
    void Output()
    {
        cout << "Name: " << Name << " || "
             << "Date: " << date;
    }
    string getName()
    {
        return Name;
    }
    int getDate()
    {
        return date;
    }
    void setName(string Name)
    {
        this->Name = Name;
    }
    void setDate(int date)
    {
        this->date = date;
    }
};

class Patient : public Person
{
private:
    char sick;

public:
    Patient()
    {
    }
    Patient(string Name, int date, char sick) : Person(Name, date)
    {
        this->sick = sick;
    }
    void Input()
    {
        Person::Input();
        cout << "Import Sick:";
        cin >> sick;
    }
    void Output()
    {
        Person::Output();
        cout << " || Sick: " << sick << endl;
    }
    char getSick()
    {
        return sick;
    }
    int getAge()
    {
        return 2023 - Person::getDate();
    }
};

class List : public Patient
{
private:
    vector<Patient> list;

public:
    List() {}
    void addList(Patient p)
    {
        list.push_back(p);
    }
    void Input()
    {
        Patient::Input();
    }
    void Output()
    {
        for(int i=0 ; i<list.size() ; i++ ){
            list[i].Output();
        }
    }
    void thongke()
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].getSick() == 'A')
            {
                cout << "List Patient Sick of A! \n";
                Output();
            }
            if (list[i].getSick() == 'B')
            {
                cout << "List Patient Sick of B! \n";
                Output();
            }
            if (list[i].getSick() == 'C')
            {
                cout << "List Patient Sick of C! \n";
                Output();
            }
            if (list[i].getSick() == 'D')
            {
                cout << "List Patient Sick of D! \n";
                Output();
            }
        }
    }

    void AgeminOfD()
    {
        int min = INT16_MAX;
        int k = -1;
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].getSick() == 'D')
            {
                if (list[i].getAge() < min){
                    min = list[i].getAge();
                    k = i;
                }
            }
        }
        if(k != -1 ){
            cout << "Patient Age Min Of D ! \n" ; list[k].Output();
        }else cout << "Not Found Patient!";
    }
};
int main()
{
    int n;
    cout << "Import List: ";
    cin >> n;
    List l;
    Patient *p = new Patient[n];
    for (int i = 0; i < n; i++)
    {
        p[i].Input();
        l.addList(p[i]);
    }
    l.Output();
    cout << endl;
    l.thongke();
    cout << endl;
    l.AgeminOfD();
}
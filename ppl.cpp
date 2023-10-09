#include<bits/stdc++.h>
using namespace std;

class Employee{
public:
double Aadhar;
string name;
Employee(){}
Employee(double x,string s){
    Aadhar=x;
    cin>>s;
     name=s;
}

 virtual void display(){
    cout<<Aadhar<<endl;
    cout<<name;
}
};
class Faculty:public Employee{
    public:
    string subject;
    Faculty(string st){
          cin>>st;
          subject=st;
    }

    void display(){
        cout<<subject;
    }
};

class Staff:public Employee{
    public:
    double salary;

    Staff(double y){
        salary=y;
    }
   void display(){
    cout<<salary<<endl;
    cout<<Aadhar<<endl;
   }
};

class Lab_staff:public Faculty,public Staff{
    public:
     void display(){
        cout<<subject<<endl;
        cout<<salary<<endl;
     }


};

int main(){
    Faculty F("programminglanguage");
    Staff s(10000);
    s.display();
}
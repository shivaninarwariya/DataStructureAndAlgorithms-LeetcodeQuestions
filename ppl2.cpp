#include <bits/stdc++.h>
using namespace std;

class Employee
{
    public :
    string name ;
    int aadhar ;

    Employee()
    {}

    Employee (string name , int aadhar)
    {
        this->name = name ;
        this->aadhar = aadhar ;
    }

    void display()
    {
        cout << " name of an employee is " << name << " and its aadhar number is " << aadhar <<endl ; 
    }
};


class Faculty :virtual public Employee
{
    public : 
    string subject ;


    Faculty()
    {
       
    }


    Faculty(string subject)
    {
       this->subject = subject ; 
    }
    void display()
    {
        cout << "Subject cotrolled by the faculty is " <<subject  <<endl ; 
    }

};


class Staff :virtual public Employee
{
    public : 
    int salary_per_hours ;

    Staff()
    {
       
    }  

    Staff(int salary_per_hours)
    {
       this->salary_per_hours = salary_per_hours ; 
    }

    void display()
    {
        cout << "salary per hours paid to this staff memeber is  " <<salary_per_hours  <<endl ; 
    }
};

class Lab_staff : public Staff,public Faculty
{
    public : 
    
    Lab_staff(int salary_per_hours,string subject,string name ,int aadhar )
    {
        this->salary_per_hours = salary_per_hours ; 
        this->subject = subject ; 
        this->name = name ;
        this->aadhar = aadhar ;
    }

    void display()
    {
        cout << "salary per hours paid to this staff memeber is  " <<salary_per_hours  <<endl 
        << "Subject cotrolled by the faculty is " <<subject  <<endl;
        cout << " name of an employee is " << name << " and its aadhar number is " << aadhar <<endl ;  
    }
};



int main ()
{
    string subject = "math" ;
    int salary_per_hours = 10 ;

    string name = "dj";
    int aadhar = 2541 ;
    
    Lab_staff LS(salary_per_hours,subject,name,aadhar)  ;

    LS.display() ;

    return 0 ;
}
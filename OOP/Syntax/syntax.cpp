#include<iostream>
using namespace std;
#include<string>

class Teacher{
    //properties or attributes
    private:
    double salary;
    
    public:
    string name;
    string dept;
    string subject;
    
    //methods or member functios
    void changeDept(string newDept){
        dept=newDept;
    }

    //setter function

    void setSalary(double salary){
        this->salary=salary;
    }

    //getter function

    double getSalary(){
        return salary;
    }

    void display(){
        cout<<name<<endl;
        cout<<dept<<endl;
        cout<<subject<<endl;
        cout<<getSalary()<<endl;
        cout<<endl;
    }

    
};

//Encapsulation
class Acount{
    private:
    double balance;
    string password; //data hiding
    public:
    string accountID;
    string username;
};

class Student{
    public:
    string name;
    int roll;
    int age;

    Student(string name,int roll,int age){
        this->name=name;
        this->roll=roll;
        this->age=age;
    }
};

int main(){

    //object
    Teacher t1; //constructor call automatically

    t1.name="SHOUMYO"; 
    t1.subject="C++";
    t1.dept="CSE";
    // t1.salary=25000;  not accessible cuz it is private
    t1.setSalary(25000);

    t1.display();

    return 0;
}
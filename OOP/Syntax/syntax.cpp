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

    //copy constructor
    Student(Student &orgObj){  //pass by reference
        cout<<"Custom copy constructor called"<<endl;
        this->name=orgObj.name;
        this->roll=orgObj.roll;
        this->age=orgObj.age;
    }

    void display(){
        cout<<name<<endl;
        cout<<roll<<endl;
        cout<<age<<endl;
    }
};

class Boys{
    public:
    string name;
    double* cgpaptr;
    Boys(string name,double cgpa){
        this->name=name;
        cgpaptr=new double;  //dynamically memory allocation
        *cgpaptr=cgpa;
    }

    Boys(Boys &obj){
        this->name=obj.name;
        this->cgpaptr=obj.cgpaptr;
    }

    void getInfo(){
        cout<<name<<endl;
        cout<<*cgpaptr<<endl;
    }
};

int main(){

    Boys b1("shoumyo",3.3);
    Boys b2(b1);   // shallow copy
    b2.getInfo();
    *(b2.cgpaptr)=9.2;  //can be changed by dynamic memory allocation
    // deep copy
    b2.getInfo();

    //object
    Teacher t1; //constructor call automatically

    t1.name="SHOUMYO"; 
    t1.subject="C++";
    t1.dept="CSE";
    // t1.salary=25000;  not accessible cuz it is private
    t1.setSalary(25000);
    Teacher t2(t1);  // default copy constructor invoke

    t1.display();
    t2.display();

    Student s1("shoumyo",2304132,23);
    Student s2(s1);   //custom copy constructor called
    s2.display();

    return 0;
}
#include<iostream>
using namespace std;
#include<string>

class Teacher{
    public:
    string subject;
    int salary;
};

class Student{
    public:
    string name;
    int roll;
};

class TA:public Student,public Teacher{

};

int main(){

    TA t1;
    t1.name="Shoumyo";
    t1.subject="CSE";

    cout<<t1.name<<endl;
    cout<<t1.subject<<endl;

    return 0;
}
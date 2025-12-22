#include<iostream>
using namespace std;
#include<string>

class Person{
    public:
    string name;
    int age;

    Person(string name,int age){
        this->name=name;
        this->age=age;
    }

};

class Student:public Person{
    public:
    int roll;

    Student(string name,int age,int roll):Person(name,age){
        this->roll=roll;
    }

    void getInfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<roll<<endl;
    }
};

class GradStudent :public Student{
    public:
    string researchArea;
};

int main(){

    Student s1("Shoumyo",23,2304132);

    s1.getInfo();

    return 0;
}
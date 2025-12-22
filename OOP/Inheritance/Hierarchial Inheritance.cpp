#include<iostream>
using namespace std;
#include<string>

class Person{

    public:
    string name;
    int age;

};

class Student:public Person{
    public:
    int roll;
};

class Teacher:public Person{
    public:
    int salary;
};

int main(){

    return 0;
}
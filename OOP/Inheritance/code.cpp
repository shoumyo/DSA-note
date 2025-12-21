#include<iostream>
using namespace std;
#include<string>

class Person{
    public:
    string name;
    int age;

    Person(){

    }

};

class Student:public Person{
    public:
    int roll;

    void getInfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<roll<<endl;
    }
};

int main(){

    Student s1;
    s1.name="shoumyo";
    s1.age=20;
    s1.roll=2304132;

    s1.getInfo();

    return 0;
}
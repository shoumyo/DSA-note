#include<iostream>
using namespace std;
#include<string>

class Student{
    public:
    string name;

    Student(){
        cout<<"non parameterized"<<endl;
    }
    Student(string name){
        this->name=name;
        cout<<"parameterized"<<endl;
    }
};

int main(){
    Student s1;
    Student s2("Shoumyo");

    return 0;
}
#include<iostream>
using namespace std;
#include<string>

class Parent{
    public:
    void show(){
        cout<<"Parent class"<<endl;
    }

    virtual void hello(){
        cout<<"hello from parent"<<endl;
    }
};
class child:public Parent{
    public:
    void show(){
        cout<<"Child class"<<endl;
    }

    void hello(){
        cout<<"hello from child"<<endl;
    }
};

int main(){

    child c1;
    c1.show();
    c1.hello();

    Parent p1;
    p1.show();

    return 0;
}
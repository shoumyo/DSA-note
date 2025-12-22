#include<iostream>
using namespace std;
#include<string>

class Shape{  // automatically abstract
    virtual void draw()=0;  // pure virtual function
};

class Circle:public Shape{
    public:
    void draw(){
        cout<<"drawing a circle"<<endl;
    }
};

int main(){

    Circle c1;
    c1.draw();

    return 0;
}
#include<iostream>
using namespace std;
#include<string>

class Abc{
    public:
    Abc(){
        cout<<"constructor "<<endl;
    }
    ~Abc(){
        cout<<"Destructor"<<endl;
    }
};

class A{
    public:
    int x;

    void inX(){
        x=x+1;
    }
};

void fun(){
    static int x=0;
    cout<<"x= "<<x<<endl;
    x++;
}

int main(){
    fun();
    fun();
    fun();

    A obj1;
    A obj2;
    obj1.x=200;
    obj2.x=100;
    cout<<obj1.x<<endl;
    obj1.inX();
    cout<<obj1.x<<endl;
    cout<<obj2.x<<endl;

    if(true){
        static Abc aa;
    }
    cout<<"End of main function"<<endl;

    return 0;
}
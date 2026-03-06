#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack{
    public:
    stack<long long int>s;
    long long int minVal;
    MinStack(){}

    void push(int val){
        if(s.empty()){
            s.push(val);
            minVal=val;
        }
        else{
            if(val<minVal){
                s.push((long long)2*val-minVal);
                minVal=val;
            }
            else{
                s.push(val);
            }
        }
    }

    void pop(){
        if(s.top()<minVal) {
            minVal=2*minVal-s.top();
        }
        s.pop();
    }

    int top(){
        if(s.top()<minVal) {
            return minVal;
        }
        else{
            return s.top();
        }
    }

    int getMin(){
       return minVal;
    }
};

int main() {
    cout << "=== MinStack Demonstration ===\n\n";
    
    // Create a MinStack object
    MinStack myStack;
    
    // Perform some operations
    cout << "Pushing elements: 5, 3, 7, 2\n";
    myStack.push(5);
    cout << "After pushing 5 - Top: " << myStack.top() << ", Min: " << myStack.getMin() << endl;
    
    myStack.push(3);
    cout << "After pushing 3 - Top: " << myStack.top() << ", Min: " << myStack.getMin() << endl;
    
    myStack.push(7);
    cout << "After pushing 7 - Top: " << myStack.top() << ", Min: " << myStack.getMin() << endl;
    
    myStack.push(2);
    cout << "After pushing 2 - Top: " << myStack.top() << ", Min: " << myStack.getMin() << endl;
    
    // Pop an element
    cout << "\nPopping one element...\n";
    myStack.pop();
    cout << "After pop - Top: " << myStack.top() << ", Min: " << myStack.getMin() << endl;
    
    // Pop another element
    cout << "Popping another element...\n";
    myStack.pop();
    cout << "After pop - Top: " << myStack.top() << ", Min: " << myStack.getMin() << endl;
    
    return 0;
}
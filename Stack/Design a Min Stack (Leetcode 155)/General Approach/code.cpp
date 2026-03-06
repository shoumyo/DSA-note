#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack{
    public:
    stack<pair<int,int>> s;
    MinStack(){}

    void push(int val){
        if(s.empty()){
            s.push({val,val});
        }
        else{
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }

    void pop(){
        if(!s.empty()) {
            s.pop();
        }
    }

    int top(){
        if(!s.empty()) {
            return s.top().first;
        }
        return -1;
    }

    int getMin(){
        if(!s.empty()) {
            return s.top().second;
        }
        return -1;
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
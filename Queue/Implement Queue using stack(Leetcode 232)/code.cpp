#include<iostream>
#include<stack>
using namespace std;

class MyQueue{
    public:
    stack<int>s1;
    stack<int>s2;
    MyQueue(){
    }
    void push (int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop(){
        int ans=s1.top();
        s1.pop();
        return ans;
    }
    int peek(){
        return s1.top();
    }
    bool empty(){
        return s1.empty();
    }

};

int main(){

    MyQueue q;
    
    // Push elements to queue
    q.push(1);
    q.push(2);
    q.push(3);
    
    cout << "Front element (peek): " << q.peek() << endl;   // Expected: 1
    
    cout << "Pop: " << q.pop() << endl;                     // Expected: 1
    cout << "Front after pop: " << q.peek() << endl;        // Expected: 2
    
    cout << "Pop: " << q.pop() << endl;                     // Expected: 2
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Expected: No
    
    q.push(4);
    cout << "After pushing 4, front: " << q.peek() << endl; // Expected: 3
    
    cout << "Pop: " << q.pop() << endl;                     // Expected: 3
    cout << "Pop: " << q.pop() << endl;                     // Expected: 4
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Expected: Yes

    return 0;
}
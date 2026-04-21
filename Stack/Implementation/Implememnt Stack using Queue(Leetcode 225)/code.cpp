#include<iostream>
#include<queue>

using namespace std;

class MyStack{
    public:
    queue<int>q1;
    queue<int>q2;

    MyStack(){

    }
    void push(int val){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop(){
        int ans=q1.front();
        q1.pop();
        return ans;
    }
    int top(){
        return q1.front();
    }
    bool empty(){
        return q1.empty();
    }
};

int main(){
    MyStack st;
    
    // Push elements
    st.push(1);
    st.push(2);
    st.push(3);
    
    cout << "Top element: " << st.top() << endl;   // Expected: 3
    
    cout << "Pop: " << st.pop() << endl;           // Expected: 3
    cout << "Top after pop: " << st.top() << endl; // Expected: 2
    
    cout << "Pop: " << st.pop() << endl;           // Expected: 2
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // Expected: No
    
    cout << "Pop: " << st.pop() << endl;           // Expected: 1
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // Expected: Yes

    return 0;
}

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string str){
    stack<char>s;

    for(int i=0;i<str.size();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            s.push(str[i]);
        }
        else{
            if(s.size()==0){
                return false;
            }
            if((s.top()=='(' && str[i]==')') || (s.top()=='{' && str[i]=='}') || (s.top()=='[' && str[i]==']')){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return s.size()==0;
}

int main(){
    // Test cases
    string testCases[] = {
        "()",           // valid
        "()[]{}",       // valid
        "(]",           // invalid
        "([)]",         // invalid
        "{[]}",         // valid
        "(",            // invalid
        ")",            // invalid
        "({[]})",       // valid
        "(((",          // invalid
        "",             // valid (empty string)
        "{[()]}",       // valid
        "{[(])}",       // invalid
        "{{[[(())]]}}"  // valid
    };
    
    int numTests = sizeof(testCases);
    
    cout << "Bracket Validation Tests:\n";
    cout << "=========================\n";
    
    for(int i = 0; i < numTests; i++){
        bool result = isValid(testCases[i]);
        
        cout << "Test " << i+1 << ": \"" << testCases[i] << "\" ";
        cout << "-> " << (result ? "✓ Valid" : "✗ Invalid") << endl;
    }
    
    // Interactive mode
    cout << "\nEnter your own strings to test (enter 'quit' to exit):\n";
    string input;
    
    while(true){
        cout << "\nEnter brackets string: ";
        getline(cin, input);
        
        if(input == "quit"){
            break;
        }
        
        if(isValid(input)){
            cout << "✓ Valid bracket sequence!\n";
        } else {
            cout << "✗ Invalid bracket sequence!\n";
        }
    }
    
    return 0;
}
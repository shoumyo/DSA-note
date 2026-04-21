#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

int firstString(string s){
    unordered_map<char,int>m;
    queue<int>q;

    for(int i=0;i<s.size();i++){
        if(m.find(s[i])==m.end()){
            q.push(i);
        }
        m[s[i]]++;
    }
    while (q.size()>0 && m[s[q.front()]]>1)
    {
        q.pop();
    }

    return q.empty()?-1:q.front();
    
}

int main(){

      // Test cases
    string test1 = "leetcode";
    string test2 = "loveleetcode";
    string test3 = "aabb";
    string test4 = "abcabc";
    string test5 = "abcd";
    
    int result1 = firstString(test1);
    int result2 = firstString(test2);
    int result3 = firstString(test3);
    int result4 = firstString(test4);
    int result5 = firstString(test5);
    
    cout << "String: \"" << test1 << "\" -> First non-repeating character index: " << result1;
    if(result1 != -1) cout << " (character: '" << test1[result1] << "')";
    cout << endl;
    
    cout << "String: \"" << test2 << "\" -> First non-repeating character index: " << result2;
    if(result2 != -1) cout << " (character: '" << test2[result2] << "')";
    cout << endl;
    
    cout << "String: \"" << test3 << "\" -> First non-repeating character index: " << result3;
    if(result3 != -1) cout << " (character: '" << test3[result3] << "')";
    else cout << " (No non-repeating character found)";
    cout << endl;
    
    cout << "String: \"" << test4 << "\" -> First non-repeating character index: " << result4;
    if(result4 != -1) cout << " (character: '" << test4[result4] << "')";
    else cout << " (No non-repeating character found)";
    cout << endl;
    
    cout << "String: \"" << test5 << "\" -> First non-repeating character index: " << result5;
    if(result5 != -1) cout << " (character: '" << test5[result5] << "')";
    cout << endl;
    
    // Additional test with user input
    string input;
    cout << "\nEnter a string to find first non-repeating character: ";
    cin >> input;
    
    int result = firstString(input);
    if(result != -1) {
        cout << "First non-repeating character is at index " << result 
             << " and it is '" << input[result] << "'" << endl;
    } else {
        cout << "No non-repeating character found in the string." << endl;
    }

    return 0;
}
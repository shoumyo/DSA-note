#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

bool ispal(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());
    return s==s2;
}

void getAllParts(string s, vector<vector<string>> &ans, vector<string> &part)
{
    if(s.size()==0){
        ans.push_back(part);
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        string p = s.substr(0, i + 1);
        if (ispal(p))
        {
            part.push_back(p);
            getAllParts(s.substr(i + 1), ans, part);
            part.pop_back();
        }
    }
}

vector<vector<string>> partitions(string s)
{
    vector<vector<string>> ans;
    vector<string> part;

    getAllParts(s, ans, part);
    return ans;
}

int main()
{

     // Test cases
    vector<string> testCases = {"aab", "racecar", "hello", "a", "aaab", "nitin"};
    
    for (const string& testStr : testCases) {
        cout << "String: \"" << testStr << "\"" << endl;
        cout << "All palindrome partitions:" << endl;
        cout << "==========================" << endl;
        
        vector<vector<string>> result = partitions(testStr);
        
        if (result.empty()) {
            cout << "No palindrome partitions found!" << endl;
        } else {
            for (int i = 0; i < result.size(); i++) {
                cout << "Partition " << i + 1 << ": [";
                for (int j = 0; j < result[i].size(); j++) {
                    cout << "\"" << result[i][j] << "\"";
                    if (j < result[i].size() - 1) {
                        cout << ", ";
                    }
                }
                cout << "]" << endl;
            }
        }
        cout << "Total partitions: " << result.size() << endl;
        cout << "\n" << string(50, '-') << "\n\n";
    }
    
    // Interactive example
    cout << "Interactive example:" << endl;
    string userInput;
    cout << "Enter a string to find its palindrome partitions (or 'exit' to quit): ";
    
    while (cin >> userInput && userInput != "exit") {
        vector<vector<string>> userResult = partitions(userInput);
        
        cout << "\nPalindrome partitions for \"" << userInput << "\":" << endl;
        
        if (userResult.empty()) {
            cout << "No palindrome partitions found!" << endl;
        } else {
            for (int i = 0; i < userResult.size(); i++) {
                cout << i + 1 << ": ";
                for (const string& part : userResult[i]) {
                    cout << part << " ";
                }
                cout << endl;
            }
        }
        
        cout << "\nTotal partitions: " << userResult.size() << endl;
        cout << "\nEnter another string (or 'exit' to quit): ";
    }
    
    cout << "Program ended. Goodbye!" << endl;
    return 0;
}
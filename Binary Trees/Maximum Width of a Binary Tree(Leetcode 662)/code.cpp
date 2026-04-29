#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

static int idx=-1;
Node* BuildTree(vector<int>preorder){
    idx++;
    if(preorder[idx]==-1){
        return NULL;
    }
    Node* root=new Node(preorder[idx]);
    root->left=BuildTree(preorder);
    root->right=BuildTree(preorder);

    return root;
}

int maxWidth(Node* root) {
    if (!root) return 0;
    
    queue<pair<Node*, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int curr = q.size();
        unsigned long long stidx = q.front().second;
        unsigned long long endidx = q.back().second;
        
        // Calculate width safely
        unsigned long long width = endidx - stidx + 1;
        if (width > (unsigned long long)maxWidth) {
            maxWidth = (int)width;
        }

        for (int i = 0; i < curr; i++) {
            Node* currNode = q.front().first;
            unsigned long long currIdx = q.front().second;
            q.pop();
            
            if (currNode->left) {
                q.push({currNode->left, 2 * currIdx + 1});
            }
            if (currNode->right) {
                q.push({currNode->right, 2 * currIdx + 2});
            }
        }
    }
    return maxWidth;
}

int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preorder);
    cout<<maxWidth(root)<<endl;
    
    
    return 0;
}
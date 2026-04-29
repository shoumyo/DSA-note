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

void allPaths(Node* root,string path,vector<string>&ans){
    if(root->left==NULL && root->right==NULL){
        ans.push_back(path);
        return;
    }
    if(root->left){
        allPaths(root->left,path+"->"+to_string(root->left->data),ans);
    }
    if(root->right){
        allPaths(root->right,path+"->"+to_string(root->right->data),ans);
    }
}


int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preorder);
    vector<string>ans;
    string path=to_string(root->data);
    allPaths(root,path,ans);
    for(auto i:ans){
        cout<<i<<endl;
    }
    
    return 0;
}
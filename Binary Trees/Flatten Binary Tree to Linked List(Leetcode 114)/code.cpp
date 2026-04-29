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

Node* nextright=NULL;

void flatten(Node* root){
    if(root==NULL){
        return;
    }
    flatten(root->right);
    flatten(root->left);

    root->left=NULL;
    root->right=nextright;
    nextright=root;
}

int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preorder);
    return 0;
}
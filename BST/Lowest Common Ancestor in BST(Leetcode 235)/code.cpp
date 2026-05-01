#include<iostream>
#include<vector>
#include<climits>
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

Node* Insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=Insert(root->left,val);
    }
    else{
        root->right=Insert(root->right,val);
    }
    return root;
}

Node* buildBST(vector<int>arr){
    Node* root=NULL;
    for(auto val:arr){
        root=Insert(root,val);
    }
    return root;
}

Node* LCA(Node* root,int p,int q){
    if(root==NULL){
        return NULL;
    }
    if(root->data<p && root->data<q){
        return LCA(root->right,p,q);
    }
    else if(root->data>p && root->data>q){
        return LCA(root->left,p,q);
    }
    else{
        return root;
    }
}

int main(){
    vector<int>arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    int p=4;
    int q=5;
    Node* ans=LCA(root,p,q);
    cout<<ans->data<<endl;
    return 0;
}
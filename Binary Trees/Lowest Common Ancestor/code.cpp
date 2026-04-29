#include<iostream>
#include<vector>
#include<queue>
#include<map>

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

Node* LCA(Node* root,int p,int q){
    if(root==NULL){
        return NULL;
    }
    if(root->data==p || root->data==q){
        return root;
    }
    Node* lLCA=LCA(root->left,p,p);
    Node* rLCA=LCA(root->right,p,q);

    if(lLCA && rLCA){
        return root;
    }
    else if(lLCA!=NULL){
        return lLCA;
    }
    else{
        return rLCA;
    }
}


int main(){

    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preorder);


    int p=2,q=5;
    Node* LCAval=LCA(
        root,p,q
    );

    cout<<LCAval->data<<endl;
    return 0;
}
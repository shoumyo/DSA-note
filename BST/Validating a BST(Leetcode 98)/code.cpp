#include<iostream>
#include<vector>
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


bool isBST(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    return isBST(root->left,min,root) && isBST(root->right,root,max);
}

bool BSTcheck(Node *root){
    Node* min=NULL;
    Node* max=NULL;

    return isBST(root,min,max);
}

int main(){

    vector<int>arr={3,2,1,5,6,4};
    Node* root=buildBST(arr);
    if(BSTcheck(root)){
        cout<<"valid"<<endl;
    }
    else{
        cout<<"not valid"<<endl;
    }

    return 0;
}
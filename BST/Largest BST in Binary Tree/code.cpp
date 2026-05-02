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

class Info{

    public:
    int min,max,size;
    Info(int min,int max,int size){
        this->min=min;
        this->max=max;
        this->size=size;
    }
};

Info helper(Node* root){
    if(root==NULL){
        return Info(INT_MAX,INT_MIN,0);
    }
    Info left=helper(root->left);
    Info right=helper(root->right);

    if(root->data>left.max && root->data<right.min){
        int currmin=min(root->data,left.min);
        int currmax=max(root->data,right.max);
        int currsize=left.size+right.size+1;

        return Info(currmin,currmax,currsize);
    }
    int ss=max(left.size,right.size);
    return Info(INT_MIN,INT_MAX,ss);
}

int largestBST(Node* root){
    Info info=helper(root);
    return info.size;
}

int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->left->left=new Node(1);
    root->left->right=new Node(8);
    root->right->right=new Node(7);

    cout<<largestBST(root)<<endl;
    
    return 0;
}
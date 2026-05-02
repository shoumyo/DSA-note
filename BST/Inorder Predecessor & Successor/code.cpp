#include<iostream>
#include<vector>
#include<stack>

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

Node* RightMostInLeftSubtree(Node* root){
    Node* ans;
    while(root!=NULL){
        ans=root;
        root=root->right;
    }
    return ans;
}

Node* LeftMostInRightSubtree(Node* root){
    Node* ans;
    while(root!=NULL){
        ans=root;
        root=root->left;
    }
    return ans;
}

vector<int>getPreSuc(Node* root,int key){
    Node* curr=root;
    Node* pred=NULL;
    Node* succ=NULL;
    while(curr!=NULL){
        if(key<curr->data){
            succ=curr;
            curr=curr->left;
        }
        else if(key>curr->data){
            pred=curr;
            curr=curr->right;
        }
        else{
            if(curr->left!=NULL){
                pred=RightMostInLeftSubtree(curr->left);
            }
            if(curr->right!=NULL){
                succ=LeftMostInRightSubtree(curr->right);
            }
            break;
        }
    }
    return {pred->data,succ->data};
}

int main(){
    Node* root=new Node(6);
    root->left=new Node(4);
    root->right=new Node(8);
    root->left->left=new Node(1);
    root->left->right=new Node(5);
    root->right->left=new Node(7);
    root->right->right=new Node(9);

    int key=7;
    vector<int>ans=getPreSuc(root,key);
    cout<<"predecessor="<<ans[0]<<endl;
    cout<<"Successor="<<ans[1]<<endl;

    return 0;
}
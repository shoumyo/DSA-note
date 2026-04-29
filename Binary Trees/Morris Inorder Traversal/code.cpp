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

vector<int>inorderTraversal(Node* root){
    vector<int>ans;
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            ans.push_back(curr->data);
            curr=curr->right;
        }

        else{
            Node* IP=curr->left;
            while(IP->right!=NULL && IP->right!=curr){
                IP=IP->right;
            }

            if(IP->right==NULL){
                IP->right=curr;
                curr=curr->left;
            }
            else{
                IP->right=NULL;
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }
    }

    return ans;
}

int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preorder);
    vector<int>ans=inorderTraversal(root);
    for(auto i:ans){
        cout<<i<<" ";
    }

    cout<<endl;
    return 0;
}
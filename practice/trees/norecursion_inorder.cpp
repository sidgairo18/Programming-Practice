#include <bits/stdc++.h>

using namespace std;

typedef struct Node{
    int data;
    struct Node *left, *right;
    Node(int data){

        this->data = data;
        this->left = this->right = NULL;
    }
} Node;

void inorder_m2(Node *root){

    //this uses stack
    stack<Node*> st;
    Node *curr = root;
    while(curr!=NULL  || !st.empty()){

        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }

        if(!st.empty()){
            curr = st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}

void inorder_m3(Node *root){

    if(root==NULL)
        return;

    Node *curr, *pre;
    curr = root;

    while(curr!=NULL){

        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr =  curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;

            if(pre->right == NULL){
                pre->right = curr;
                curr =  curr->left;
            }
            else{
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}



int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"M2: ";
    inorder_m2(root);
    cout<<endl;

    cout<<"M3: ";
    inorder_m3(root);
    cout<<endl;
    return 0;
}

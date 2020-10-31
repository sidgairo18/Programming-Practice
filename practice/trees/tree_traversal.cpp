#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    struct Node* left;
    struct Node* right;

    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

void preorder(struct Node* root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void inorder(struct Node* root){

    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct Node* root){

    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}


int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n"; 
    preorder(root); 

    cout << "\nInorder traversal of binary tree is \n"; 
    inorder(root);  

    cout << "\nPostorder traversal of binary tree is \n"; 
    postorder(root); 

    return 0;
}

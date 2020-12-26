#include <bits/stdc++.h>

using namespace std;

class tree_node{

    public:
        int data;
        tree_node *left, *right;
        tree_node(int data){
            this->data = data;
        }

};

void pre_order(tree_node *root){
    
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(tree_node *root){
    
    if(root == NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}

void in_order(tree_node *root){
    
    if(root == NULL)
        return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

int main(){

    tree_node *root = new tree_node(1);
    root->left = new tree_node(2);
    root->right = new tree_node(3);
    root->left->left = new tree_node(4);
    root->left->right = new tree_node(5);

    cout<<"Print pre-order"<<endl;
    pre_order(root);
    cout<<endl;

    cout<<"Print post-order"<<endl;
    post_order(root);
    cout<<endl;

    cout<<"Print in-order"<<endl;
    in_order(root);
    cout<<endl;

    return 0;
}

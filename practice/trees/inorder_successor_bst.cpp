#include <bits/stdc++.h>

Node *findmin(Node *root){

    if(root == NULL || root->left == NULL)
    return root;

    return findmin(root->left);
}
// returns the inorder successor of the Node x in BST (rooted at 'root')
Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    if(x->right != NULL)
        return findmin(x->right);

    Node *succ = NULL;

    while(root!=NULL){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        }
        else if(x->data > root->data){
            root = root->right;
        }
        else
        break;
    }
    return succ;
}

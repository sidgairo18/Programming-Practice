#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        int isThreaded;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
            isThreaded = false;
        }
};

Node* makeThreaded(Node *root){

    if(root == NULL)
        return root;
    if(root->left && root->right == NULL)
        return root;

    if(root->left != NULL){
        Node *temp = makeThreaded(root->left);
        temp->right = root;
        temp->isThreaded = true;
    }

    if(root->right == NULL){
        return root;
    }

    return createThreaded(root->right);
}

Node* leftmost(Node *root){
    if(root->left == NULL || root == NULL)
        return root;

    if(root->left != NULL)
        return leftmost(root->left);
}

void inOrder(Node *root){

    if(root == NULL)
        return;    
    Node *curr = leftmost(root);

    while(curr!=NULL){
        cout<<curr->data<<" ";

        if(curr->isThreaded){
            curr = curr->right;
        }
        else
            curr = leftmost(root->right);
    }
}

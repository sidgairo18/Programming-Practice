#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

Node* insert(Node *root, int val){

    if(root==NULL){
        return new Node(val);
    }

    if(root->data < val)
        root->right = insert(root->right, val);
    else
        root->left = insert(root->left, val);

    return root;
}

Node *minValNode(Node *root){

    if(root == NULL || root->left == NULL)
        return root;

    return minValNode(root->left);
}

Node *deleteNode(Node *root, int val){

    if(root == NULL)
        return root;

    if(root->data < val)
        return deleteNode(root->right, val);
    else if(root->data > val)
        return deleteNode(root->left, val);
    else{

        if(root->left == NULL){

            Node *temp = root->right;
            free(root);
            return temp;
        }
        else  if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);

    }

    return root;

}



void inorder(Node *root){


    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    int n;
    cin>>n;

    Node *root=NULL;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        root = insert(root, x);
    }

    cout<<"INORDER"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Enter node to be deleted: ";
    int val;
    cin>>val;
    root = deleteNode(root, val);
    cout<<"INORDER"<<endl;
    inorder(root);
    cout<<endl;

    return 0;
}

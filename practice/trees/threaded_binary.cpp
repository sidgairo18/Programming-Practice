#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int data;
    Node *left, *right;
    bool rightThread;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
        this->rightThread = false;
    }

} Node;

void inorder(Node *root){
    Node *curr = root;
    while(curr!=NULL){

        if(curr->left){
            Node *find_succ = curr->left;
            while(find_succ->right != NULL)
                find_succ = find_succ->right;
            find_succ->right = curr;
            find_succ->rightThread = true;
        }

        while(curr->left != NULL)
            curr = curr->left;

        cout<<curr->data<<" ";

        if(curr->right && curr->rightThread){
            cout<<curr->data<<" ";
            Node *temp = curr->right;
            curr->right = NULL;
            curr->rightThread = false;
            curr = temp->right;
        }
        else
            curr = curr->right;
    }
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    inorder(root);
    return 0;
}

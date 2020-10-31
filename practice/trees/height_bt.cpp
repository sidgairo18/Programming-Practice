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

int height_bt(Node *root){

    if(root==NULL)
        return 0;

    int lh = height_bt(root->left);
    int rh = height_bt(root->right);

    return max(lh,rh)+1;
}


int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<height_bt(root)<<endl;

    return 0;
}

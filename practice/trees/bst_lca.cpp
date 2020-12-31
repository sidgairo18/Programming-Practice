#include <bits/stdc++.h>

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

Node* lca(Node *root, int n1, int n2){
    
    if(root == NULL)
        return root;

    if(root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
    if(root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);

    return root;
}

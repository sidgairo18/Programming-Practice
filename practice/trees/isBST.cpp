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

bool isBST(Node *root, int mn, int mx){
    
    if(root==NULL)
        return 1;

    if(root->data < mn || root->data > mx)
        return 0;

    return isBST(root->left, mn, root->data-1) &&
        isBST(root->right, root->data+1, mx);
}

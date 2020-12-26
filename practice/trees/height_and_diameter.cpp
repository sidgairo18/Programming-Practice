#include <bits/stdc++.h>

using namespace std;

class tree_node{

    public:
        int data;
        tree_node *left, *right;
        tree_node(int data){

            this->data = data;
            left = right = NULL;
        }
};

int height(tree_node *root){

    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

int diameter(tree_node *root, int *d){

    if(root == NULL){
        *d = 0;
        return 0;
    }
    int lh, rh;
    int ld, rd;

    lh = diameter(root->left, &ld);
    rh = diameter(root->right, &rd);

    *d = (lh + rh) + 1;
    *d = max(*d, max(ld, rd));
    return max(lh, rh) + 1;
}

int main(){
    
    tree_node *root = new tree_node(1);
    root->left = new tree_node(2);
    root->right = new tree_node(3);
    root->left->left = new tree_node(4);
    root->left->right = new tree_node(5);

    int ans;
    int height = diameter(root, &ans);
    cout<<ans<<endl;


    return 0;
}

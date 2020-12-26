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

bool print_ancestors(tree_node *root, int target){

    if(root == NULL)
        return false;

    if(root->data == target)
        return true;

    if(print_ancestors(root->left, target) || print_ancestors(root->right, target))
    {
        cout<<root->data<<" ";
        return true;
    }

    return false;

}

int main(){
    
    tree_node *root = new tree_node(1);
    root->left = new tree_node(2);
    root->right = new tree_node(3);
    root->left->left = new tree_node(4);
    root->left->left->left = new tree_node(7);
    root->left->right = new tree_node(5);
    print_ancestors(root, 7);
    cout<<endl;
    return 0;
}

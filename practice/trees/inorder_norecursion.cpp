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

void inorder_norecursion(tree_node *root){

    stack<tree_node *> st;

     while(true){

         while(root!=NULL){
            st.push(root);
            root = root->left;
         }
         tree_node *curr = st.top();
         st.pop();
         cout<<curr->data<<" ";
         root = curr->right;

         if(root == NULL && st.empty())
             break;
     }
     cout<<endl;

    return;
}

void inorder_recursion(tree_node *root){
    
    if(root == NULL)
        return;

    inorder_recursion(root->left);
    cout<<root->data<<" ";
    inorder_recursion(root->right);
}

int main(){

    tree_node *root = new tree_node(1);
    root->left = new tree_node(2);
    root->left->left = new tree_node(3);
    root->left->right = new tree_node(5);
    root->left->left->right = new tree_node(4);
    root->right = new tree_node(6);
    root->right->left = new tree_node(8);
    root->right->right = new tree_node(7);

    cout<<"in order no recursion\n";
    inorder_norecursion(root);
    cout<<"in order recursion\n";
    inorder_recursion(root);
    cout<<endl;


    return 0;
}

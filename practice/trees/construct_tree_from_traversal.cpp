#include <bits/stdc++.h>

using namespace std;

class tree_node{
    public:
        char data;
        tree_node *left, *right;
        tree_node(int data){
            this->data = data;
            left = right = NULL;
        }
};

tree_node *in_pre(int left, int right, int *pre_idx, char in_arr[], char pre_arr[],int n){
        if(left > right || *pre_idx >= n)
            return NULL;

        if(left == right){
            return (new tree_node(pre_arr[*pre_idx]));
        }

        tree_node *curr = new tree_node(pre_arr[*pre_idx]);
        int in_idx = left;
        for( ;in_idx<right; in_idx++)
            if(in_arr[in_idx] == pre_arr[*pre_idx])
                break;
        *pre_idx = *pre_idx + 1;
        curr->left = in_pre(left, in_idx-1, pre_idx, in_arr, pre_arr, n);
        *pre_idx = *pre_idx + 1;
        curr->right = in_pre(in_idx+1, right, pre_idx, in_arr, pre_arr, n);
        
        return curr;
}

void print_inorder(tree_node *root){
    
    if(root == NULL)
        return;
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}

int main(){

    int n;
    cin>>n;
    char in_arr[n], pre_arr[n];
    for(int i = 0; i<n; i++)
        cin>>in_arr[i];

    for(int i = 0; i<n; i++)
        cin>>pre_arr[i];
    
    int pre_idx = 0;
    tree_node *root = in_pre(0, n-1, &pre_idx, in_arr, pre_arr, n);
    cout<<"prining tree inorder"<<endl;
    print_inorder(root);
    cout<<endl;

    return 0;
}

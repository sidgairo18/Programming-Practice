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

void print_k(tree_node *root, int dist, int k){
    
    if(root == NULL)
        return;

    if(dist == k)
        cout<<root->data<<" ";

    print_k(root->left, dist+1, k);
    print_k(root->right, dist+1, k);

}

int main(){

    return 0;
}

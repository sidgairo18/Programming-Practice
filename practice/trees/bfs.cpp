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

void bfs(tree_node *root){
    
    if(root == NULL)
        return;
    queue<tree_node *> q;
    q.push(root);

    while(!q.empty()){

        tree_node *curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }

    cout<<endl;
}

int main(){

    tree_node *root = new tree_node(1);
    root->left = new tree_node(2);
    root->right = new tree_node(3);
    root->left->left = new tree_node(4);
    root->left->right = new tree_node(5);

    bfs(root);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int start[100005];
int endtime[100005];
vector<int> dfs_order;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

void dfs(Node *root, int &b){
    
    b++;
    start[root->data] = b;
    dfs_order.push_back(root->data);
    if(root->left)
        dfs(root->left, b);
    if(root->right)
        dfs(root->right, b);

    endtime[root->data] = b;
}

void print_subtrees(int n){
        
    for(int i = 0; i<n; i++){
        
        if(start[i] == endtime[i])
            cout<<"Leaf Node: "<<i<<endl;
        else{
            cout<<"Subtree of Node: "<<i<<" : ";
            for(int j = start[i]; j<endtime[i]; j++)
                cout<<dfs_order[j]<<" ";

            cout<<endl;
        }
    }
}


int main(){
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right = new Node(6);
    root->right->right->right = new Node(9);
    
    int c = 0;
    dfs(root, c);
    print_subtrees(9);

    return 0;
}

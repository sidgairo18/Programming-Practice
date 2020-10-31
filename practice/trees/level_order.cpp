#include <bits/stdc++.h>

using namespace std;

//this is also called bfs for trees

struct Node{
    int data;
    struct Node *left, *right;
    Node(int data){

        this->data = data;
        this->left = this->right = NULL;
    }
};

void doBFS(struct Node* root);

int main(){

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    doBFS(root);
    cout<<endl;

    return 0;
}

void doBFS(struct Node* root){

    if(root==NULL)
        return;

    queue<struct Node*> q;
    map<struct Node*, int> visited;
    q.push(root);
    visited[root] = 1;

    while(!q.empty()){

        struct Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left!=NULL && visited.find(curr->left) == visited.end()){
            q.push(curr->left);
            visited[curr->left] = 1;
        }

        if(curr->right!=NULL &&  visited.find(curr->right) == visited.end()){

            q.push(curr->right);
            visited[curr->right] = 1;

        }
    }
}


#include <bits/stdc++.h>

using namespace std;

class Node{

    public:
        int data;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right = NULL;

};

void MorrisTraversal(Node *root){
    
    Node *curr = root, *pre;

    while(curr!=NULL){

        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            
            pre = curr->left;
            while(pre->right!=NULL && pre->right != curr)
                pre = pre->right;

            if(pre->right == NULL){
                pre->right = curr;
               curr = curr->left;
            }
            else{
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }

        }
    }
}

int main(){
    
    return 0;
}

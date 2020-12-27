#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
} Node;

void connect(Node *p){
    queue<Node*> q;
    q.push(p);
    q.push(NULL);

    while(!q.empty()){
        
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){
            if(q.size() > 0)
                q.push(NULL);
            continue;
        }
        curr->nextRight = q.front();
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }

}

int main(){

    return 0;
}

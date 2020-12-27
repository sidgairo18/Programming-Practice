#include <bits/stdc++.h>

using namespace std;

int getMaxWidth(Node* root)
{

   queue<Node *> q;
   q.push(root);
   int ans = -1;
   while(!q.empty()){
       int count = q.size();
       ans = max(ans, count);

       while(count--){
           Node *curr = q.front();
           q.pop();
           if(curr->left)
           q.push(curr->left);
           if(curr->right)
           q.push(curr->right);

       }
   }
   return ans;
}

int main(){

    return 0;
}

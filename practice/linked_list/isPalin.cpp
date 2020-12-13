#include <bits/stdc++.h>

using namespace std;

bool isPalindromeUtil(Node **left, Node *right){
    if(right==NULL)
        return true;

    bool isPalin = isPalindromeUtil(left, right->next);
    if(!isPalin)
        return false;

    isPalin = (*left)->data == right->data;
    //cout<<"left "<<(*left)->data<<" right "<<(right)->data<<" flag "<<isPalin<<endl;
    (*left) = (*left)->next;
    return isPalin;
}

int main(){

    return 0;
}

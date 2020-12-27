#include <bits/stdc++.h>

bool isIdentical(Node *T, Node *S){
    if(T==NULL && S==NULL)
        return true;
    
    if(T==NULL || S==NULL)
        return false;
    
    return (T->data == S->data) && (isIdentical(T->left, S->left)) && (isIdentical(T->right, S->right));
}
bool isSubTree(Node* T, Node* S) {
    // Your code here
    // return 1 if S is subtree of T else 0
    if(S == NULL)
        return true;
        
    if(T==NULL)
        return false;
        
    if(T->data == S->data)
    return (isIdentical(T->left, S->left) && isIdentical(T->right, S->right)) || isSubTree(T->left, S) || isSubTree(T->right, S);

    return isSubTree(T->left, S) || isSubTree(T->right, S);    
}

int inorderUtil(Node *root, int& count, int k){
    
    if(root == NULL)
        return -1;
    
    int l = -1, r = -1;
    if(root->left)
        l =  inorderUtil(root->left, count, k);
        
    count++;
    if(count == k)
        return root->data;
    
    if(root->right)
        r = inorderUtil(root->right, count, k);
        
    if(l!=-1)
        return l;
    if(r!=-1)
        return r;
        
    return -1;
        
        
}

// Return the Kth smallest element in the given BST 
int KthSmallestElement(Node *root, int K)
{
    int count = 0;
    return inorderUtil(root, count, K);
    //add code here.
}

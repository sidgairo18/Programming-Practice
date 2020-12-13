#include <bits/stdc++.h>
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<struct Node*> us;
    while(head1!=NULL){
        us.insert(head1);
        head1 = head1->next;
    }
    
    while(head2!=NULL){
        if(us.find(head2)!=us.end())
            return head2->data;
        head2 = head2->next;
    }
    
    return -1;
}

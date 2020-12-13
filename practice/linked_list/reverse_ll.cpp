#include <bits/stdc++.h>

using namespace std;

// a recursive version
// it is more elegant
//
struct Node
{
    int data;
    struct Node *next;
}


// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    if(head->next == NULL) return head;
    
    struct Node* temp = head->next;
    struct Node* new_head = reverseList(head->next);
    temp->next = head;
    head->next = NULL;
    return new_head;
    
}

int main(){

    return 0;
}

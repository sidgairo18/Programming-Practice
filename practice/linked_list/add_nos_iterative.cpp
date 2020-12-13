// this assumes least significant bit is at head
#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int data;
    struct node *next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
} node;

struct Node *reverse(struct Node *head){
    if(head->next == NULL)
        return head;
    
    struct Node *head_next = head->next;    
    struct Node *new_head = reverse(head->next);
    head_next->next = head;
    head->next = NULL;
    return new_head;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    
    // reverse lists
    first = reverse(first);
    second = reverse(second);
    // code here
    struct Node *result = new Node(0);
    struct Node *tail = result;
    int carry = 0, sum;
    while(first!=NULL && second!=NULL){
        sum = first->data + second->data + carry;
        carry = sum/10;
        tail->data = sum%10;
        first = first->next, second = second->next;
        tail->next = new Node(0);
        tail = tail->next;
    }
    while(first!=NULL){
        sum = first->data + carry;
        carry = sum/10;
        tail->data = sum%10;
        first = first->next;
        tail->next = new Node(0);
        tail = tail->next;
    }
    while(second!=NULL){
        sum = second->data + carry;
        carry = sum/10;
        tail->data = sum%10;
        second = second->next;
        tail->next = new Node(0);
        tail = tail->next;
    }
    if(carry!=0)
        tail->data = carry;
        
    result = reverse(result);
    while(result!=NULL && result->data == 0)
        result = result->next;
    
    return result;
}

int main(){
    
    return 0;
}

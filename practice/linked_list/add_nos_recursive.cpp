// this assumes the most significant bit is at  head

#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int data;
    struct node *next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
} node;

node *add_same_len(node *a, node *b, int *carry){
    
    if(a==NULL)
        return NULL;

    node *result = new node(0);
    result->next = add_same_len(a->next, b->next, carry);

    result->data = (a->data+b->data+ *carry)%10;
    *carry = (a->data +  b->data + *carry)/10;

    return result;
}

node *add_carry(node *head, int carry){
    
    while(carry!=0){
        node *result = new node(0);
        result->data = carry%10;
        carry /= 10;
        result->next = head;
        head = result;
    }
    return head;
}

void add_single(node *head, node *curr, int *carry, node **ans){    
    
    if(head != curr){
        node *result = new node(0);
        int sum = head->data;
        add_single(head->next, curr, carry, ans);
        sum = sum + *carry;
        result->data = sum%10;                                          
        *carry = sum/10;                                                
        result->next = *ans;                                            
        *ans = result;
        //cout<<(*ans)->data<<endl;
        
    }    
}

int size_ll(node *head){
    
    if(head == NULL)
        return 0;

    return size_ll(head->next) + 1;
}

node *add_ll(node* head1, node* head2){
    
    int l1 = size_ll(head1);
    int l2 = size_ll(head2);
    
    if (l1 <= l2){
        
        node *temp = head1;
        head1 = head2;
        head2 = temp;
    }

    int carry = 0; 
    node *result;
    if(l1 == l2){
        result = add_same_len(head1, head2, &carry);
        return add_carry(result, carry);
    }
    else{
        
        int diff = abs(l1-l2);
        node *curr = head1;
        while(diff>0){
            curr = curr->next;
            diff--;
        }
        result = add_same_len(curr, head2, &carry);
        add_single(head1, curr, &carry, &result);
        return add_carry(result, carry);
    }
} 

int main(){

    return 0;
}

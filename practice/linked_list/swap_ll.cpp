#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int  data;
    struct node *next;

    node(int d){
        data = d;
        next = NULL;
    }
} node;

void swap(node*& a, node*& b){

    cout<<"In swap"<<endl;
    cout<<"A "<<a<<" "<<&a<<endl;
    cout<<"B "<<b<<" "<<&b<<endl;
    cout<<endl;
    node *temp = a;
    a = b;
    b = temp;
}

void print_ll(node *head){
    
    node *head_copy = head;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
    cout<<"Address Locations"<<endl;

    while(head_copy != NULL){
        cout<<head_copy<<" "<<head_copy->next<<endl;
        cout<<"Actual address "<<&(head_copy)<<" "<<&((head_copy->next))<<endl;
        cout<<endl;
        head_copy = head_copy->next;
    }

}

void swapNodes(node **head_ref, int x, int y){
    if(x==y)
        return;

    node **a = NULL, **b = NULL;
    while(*head_ref !=  NULL){

        if((*head_ref)->data == x){
            a = head_ref;
        }
        else if((*head_ref)->data == y){
            b  = head_ref;
        }
        head_ref = &((*head_ref)->next);
    }

    if(a && b){
        swap(*a, *b);
        swap((*a)->next, (*b)->next);
    }
}

int main(){

    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);
    
    print_ll(head);
    swapNodes(&head, 2,6);
    cout<<endl;
    print_ll(head);


    return 0;
}

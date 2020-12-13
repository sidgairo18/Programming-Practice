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

void print_ll(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

node *reverse_k(node *head, int k){

    if(head == NULL)
        return NULL;

    node *prev = NULL, *curr = head, *next;
    int count = 0;
    while(curr!=NULL && count<k){
        
        count++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = reverse_k(curr, k);
    return prev;

}

int main(){

    node *a = new node(1);
    a->next = new  node(2);
    a->next->next = new node(3);
    a->next->next->next = new node(4);
    a->next->next->next->next = new node(5);
    a->next->next->next->next->next = new node(6);

    cout<<"before reverse"<<endl;
    print_ll(a);
    cout<<endl;
    int k = 2;
    cout<<"after reverse, k="<<k<<endl;
    a = reverse_k(a, 2);
    print_ll(a);
    return 0;
}

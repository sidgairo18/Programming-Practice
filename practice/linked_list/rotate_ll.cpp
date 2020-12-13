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

// rotate counter-clockwise
node *rotate_counter(node *head, int k){
    // assuming k is less than length of ll
    node *runner = head;
    node *new_head;

    while(k>1){
        runner = runner->next;
        k--;
    }
    // case where k = n
    if(runner->next == NULL)
        return head;

    new_head = runner->next;
    runner->next = NULL;
    runner = new_head;

    while(runner->next != NULL)
        runner = runner->next;
    
    runner->next = head;
    return new_head;
}

//  print
void print_ll(node *head){
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){

    node *a = new node(10);
    a->next =  new node(20);
    a->next->next = new node(30);
    a->next->next->next = new  node(40);
    a->next->next->next->next= new node(50);
    a->next->next->next->next->next = new node(60);

    cout<<"Before rotate"<<endl;
    print_ll(a);
    cout<<endl;
    cout<<"After rotate"<<endl;
    a = rotate_counter(a, 4);
    print_ll(a);

    return 0;
}

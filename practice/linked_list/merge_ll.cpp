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

// iterative
node *merge_1(node *a, node *b){

    node *dummy = (node *)malloc(sizeof(node));
    node *tail = dummy;

    while(1){

        if(a==NULL){
            tail->next = b;
            break;
        }
        if(b==NULL){
            tail->next = a;
            break;
        }
        if(a->data <= b->data){
            tail->next = a;
            a = a->next;
        }
        else{
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    return dummy->next;

}

// recursive more elegant
node *merge_2(node *a, node *b){

    node *result;

    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    if(a->data <= b->data){
        result = a;
        result->next = merge_2(a->next, b);
    }
    else{
        result = b;
        result->next = merge_2(a, b->next);
    }

    return result;
}

int main(){

    node *a = new node(1);
    a->next = new node(3);
    a->next->next = new node(5);

    node *b = new node(2);
    b->next = new node(4);
    
    // print a
    cout<<"A LL"<<endl;
    print_ll(a);
    // print b
    cout<<"B LL"<<endl;
    print_ll(b);

    //node *merged = merge_1(a, b);
    node *merged = merge_2(a, b);
    cout<<"merged ll"<<endl;
    print_ll(merged);

    return 0;
}

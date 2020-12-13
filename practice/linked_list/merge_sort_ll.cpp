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


node *merge(node *a, node *b){

    node *result;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;

    if(a->data <=  b->data){
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void half_split(node *head, node **left, node **right){

    node *slow = head;
    node *fast = head->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

void merge_sort(node **head){

    if(*head == NULL ||  (*head)->next == NULL)
        return;

    node *curr_head = *head;
    node *left, *right;
    half_split(curr_head, &left, &right);
    merge_sort(&left);
    merge_sort(&right);

    *head = merge(left, right);
}

int main(){

    node *a = new node(5);
    a->next = new node(3);
    a->next->next = new node(4);
    a->next->next->next = new node(1);
    a->next->next->next->next = new node(2);

    cout<<"before sort"<<endl;
    print_ll(a);
    cout<<endl;
    merge_sort(&a);
    cout<<"after sort"<<endl;
    print_ll(a);

    return 0;

}

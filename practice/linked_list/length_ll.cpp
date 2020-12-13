#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node *next;

    node(int d){
        data = d;
        next = NULL;
    }
} node;

int iter_length(node *head){
    int len = 0;
    while(head!=NULL){
        head = head->next;
        len++;
    }
    return len;
}

int recur_length(node *head){

    if(head==NULL)
        return 0;

    return 1+recur_length(head->next);
}

int main(){

    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);

    cout<<"Iter length "<<iter_length(head)<<endl;
    cout<<"Recur length "<<recur_length(head)<<endl;

    return 0;
}

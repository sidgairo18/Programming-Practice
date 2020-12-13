#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int data;
    struct node *next;

    node(int d){
        data = d;
        next = NULL;
    }
} node;

int main(){

    node *test = new node(3);
    cout<<"Test "<<test<<endl;
    cout<<"Test data "<<test->data<<endl;
    cout<<"Test next "<<test->next<<endl;
    cout<<"Test & address "<<&test<<endl;
    cout<<endl; 
    cout<<"Test "<<test<<endl;
    cout<<"Test data "<<test->data<<endl;
    cout<<"Test next "<<test->next<<endl;
    cout<<"Test & address "<<&test<<endl;

    return 0;
}

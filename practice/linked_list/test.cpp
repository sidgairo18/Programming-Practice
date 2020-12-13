#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};


int main(){

    struct node *node1 = (struct node*)malloc(sizeof(struct node));
    node1->data = 1;

    struct node *node2 = new node(2);

    cout<<"Node 1 data "<<node1->data<<endl;
    cout<<"Node 2 data "<<node2->data<<endl;

    return 0;

}

#include <bits/stdc++.h>

using namespace std;

struct Node{
    int d;
    struct Node *next;
};

void print_nodes(struct Node *head){

    while(head!=NULL){
        cout<<head->d<<" ";
        head = head->next;
    }
    cout<<endl;

}

struct Node *new_node(int d){

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->d = d;
    temp->next = NULL;
    return temp;

}

int main(){

    struct Node *head = new_node(3);
    head->next = new_node(2);
    (head->next)->next = new_node(1);
    (head->next)->next->next = new_node(1009);

    print_nodes(head);

    return 0;
}

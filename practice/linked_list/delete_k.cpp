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

void delete_k(struct Node *head, int k){

    if(k == 1){

        while(head!=NULL){
            
            struct Node *temp = head->next;
            delete (head);
            head = temp;
        }

        return;

    }
    
    int i = 1;
    while(head!=NULL){
        
        cout<<i<<" "<<head->d<<endl;
        if((i+1)%k == 0 && head->next != NULL){
            struct Node *temp = head->next;
            head->next = head->next->next;
            cout<<"Delete "<<" "<<temp->d<<endl;
            delete (temp);
            head = head->next;
            i++;
        }
        else if(head!=NULL)
            head = head->next;
        i++;

    }
    cout<<"Delete done"<<endl;
    return;

}

int main(){

    struct Node *head = new_node(1);
    head->next = new_node(2);
    (head->next)->next = new_node(3);
    (head->next)->next->next = new_node(4);
    (head->next)->next->next->next = new_node(5);
    (head->next)->next->next->next->next = new_node(6);
    (head->next)->next->next->next->next->next = new_node(7);
    (head->next)->next->next->next->next->next->next = new_node(8);

    print_nodes(head);
    delete_k(head, 3);

    print_nodes(head);

    return 0;
}

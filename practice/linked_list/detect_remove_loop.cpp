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

node *floyd_cycle_detect(node *head){
    
    if(head==NULL || head->next == NULL)
        return NULL;

    node *slow = head;
    node *fast = head;

    while(fast != NULL || fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return fast;
    }

    return NULL;
}

void remove_cycle(node *head){

    node *check = floyd_cycle_detect(head);
    if(check==NULL)
        return;

    node *slow = head, *fast = check;
    if(slow == fast){
        while(fast->next!=slow)
            fast = fast->next;
    }
    else{
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;

}

void print_ll(node *head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;

}


int main(){
    
    node *a = new node(10);
    a->next = new node(20);
    a->next->next = new node(15);
    a->next->next->next = new node(4);
    a->next->next->next->next = new node(10);

    // add loop
    a->next->next->next->next->next = a->next->next;

    //print_ll(a);

    // remove loop
    remove_cycle(a);
    print_ll(a);

    return 0;
}

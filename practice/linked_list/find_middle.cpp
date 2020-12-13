#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int data;
    struct node* next;
} Node;

int getMiddle(Node *head)
{
   // Your code here
   Node *slow = head;
   Node *fast = head;

   while(fast && fast->next){
       fast = fast->next->next;
       slow = slow->next;
   }
   return slow->data;
}


int main(){

    return 0;
}

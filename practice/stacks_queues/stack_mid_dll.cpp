#include <bits/stdc++.h>

using namespace std;

class DLLNode{

    public:
    DLLNode *prev, *next;
    int data;
};

class myStack{

    DLLNode *head, *mid;
    int count;

    public:
    myStack(){
        count = 0;
    }
    void push(int x){
        
        DLLNode *add = new DLLNode();
        add->prev = NULL;
        add->next = head;
        add->data = x;
        if(count==0){
            mid = add;
        }
        else{
            head->prev = add;
            if(!(count & 1))
                mid = mid->prev;
        }
        count++;
        head = add;
    }

    int pop(){

        if(count==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int ret = head->data;
        DLLNode *tofree = head;
        head = head->next;
        count--;
        if(!(count&1))
            mid = mid->next;
        free(tofree);
        return ret;
    }

    int findMiddle(){
        if(count==0){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return mid->data;
    }
};


int main()
{
    /* Let us create a stack using push() operation*/
    myStack ms;
    ms.push(11);
    ms.push(22);
    ms.push( 33);
    ms.push(44);
    ms.push(55);
    ms.push(66);
    ms.push(77);

    cout << "Item popped is " << ms.pop() << endl;
    cout << "Item popped is " << ms.pop() << endl;
    cout << "Middle Element is " << ms.findMiddle() << endl;
    return 0;
}

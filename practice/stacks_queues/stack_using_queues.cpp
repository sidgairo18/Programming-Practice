#include <bits/stdc++.h>

using namespace std;
// push operation is expensive O(n)
class stack_using_queues{
    queue<int> q1, q2;
    int curr_size;;
    public:
    stack_using_queues(){
        this->curr_size = 0;
    }
    void push(int);
    void  pop();
    int top();
    int size();
};

void stack_using_queues::push(int x){
    
    q1.push(x);
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }

    // copy q1 to q2
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp; 
    curr_size++;
}

void stack_using_queues::pop(){

    if(curr_size==0){
        return;
    }
    
    q2.pop();
    curr_size--;
}

int stack_using_queues::top(){
    if(curr_size == 0)
        return -1;

    return q2.front();
}

int stack_using_queues::size(){
    return curr_size;
}

// Driver code
int main()
{
    stack_using_queues s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size()
         << endl;
    return 0;
}

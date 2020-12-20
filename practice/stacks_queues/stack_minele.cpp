#include <bits/stdc++.h>

using namespace std;

class _stack{

    stack<int> s;
    int minele;

    public:
    int getMin();
    int pop();
    void push(int);

};

int _stack::getMin(){
    if(s.empty())
        return -1;
    return minele;
}

int _stack::pop(){
    
    if(s.empty())
        return -1;
    
    int ret  = s.top();
    if(s.top() >= minele){
        s.pop();
        return ret;
    }
    
    ret = minele;
    minele = 2*minele - s.top();
    s.pop();
    return ret;
}

void _stack::push(int x){
    
    if(s.empty() || x >= minele){
        if(s.empty())
            minele = x;
        s.push(x);
    }
    else{
        s.push(2*x-minele);
        minele  = x;
    }
}
int main(){

    return 0;
}

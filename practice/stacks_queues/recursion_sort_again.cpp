#include <bits/stdc++.h>
using namespace std;

void insert_sorted(stack<int>& st, int x){
    if(st.empty() || st.top() < x)
        st.push(x);
    if(st.top() > x){
        int temp = st.top();
        st.pop();
        insert_sorted(st, x);
        st.push(temp);
    }
}

void sort_stack(stack<int> &st){
    if(st.empty())
        return;

    int temp = st.top();
    st.pop();
    sort_stack(st);
    insert_sorted(st, temp);
}

void print_stack(stack<int> st){
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){

    stack<int> st;
    st.push(5);
    st.push(20);
    st.push(1);
    st.push(4);
    st.push(7);
    print_stack(st);
    sort_stack(st);
    print_stack(st);
    return 0;
}

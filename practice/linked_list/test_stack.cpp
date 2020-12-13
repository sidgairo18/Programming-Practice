#include <bits/stdc++.h>

using namespace std;

void change_stack(stack<int>& st){
    st.pop();
}
void change_stack_2(stack<int> st){
    st.pop();
}

int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
    change_stack_2(st);
    cout<<st.top()<<endl;
    change_stack(st);
    cout<<st.top()<<endl;

    return 0;
}

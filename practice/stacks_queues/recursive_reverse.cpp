#include<bits/stdc++.h>

using namespace std;

void insert_at_bottom(stack<int>& st, int x){
    
    if(st.size() == 0)
        st.push(x);
    else{
          int temp = st.top();
          st.pop();
          insert_at_bottom(st, x);
          st.push(temp);
        }
}

void reverse_stack(stack<int>& st){

    if(st.size() > 0){
        
        int temp = st.top();
        st.pop();
        reverse_stack(st);
        insert_at_bottom(st, temp);
    }
}

int main(){

    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    reverse_stack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    

    return 0;

}

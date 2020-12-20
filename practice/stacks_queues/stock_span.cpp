#include <bits/stdc++.h>

using namespace std;

void span(int prices[], int n, int s[]){
    
    stack<int> st;
    s[0] = 1;
    st.push(0);
    for(int i = 1; i<n; i++){
        
        while(!st.empty() && prices[st.top()] <= prices[i])
            st.pop();

        s[i] = st.empty()?i+1:i-st.top();
        st.push(i);
    }
}

void span_nostack(int prices[], int n, int s[]){
    
    s[0] = 1;
    for(int i = 1; i<n; i++){
        
        int counter = 1;
        while((i-counter)>=0 && prices[i] >= prices[i-counter])
            counter += s[i-counter];
        s[i] = counter;
    }
}

int main(){

    return 0;
}

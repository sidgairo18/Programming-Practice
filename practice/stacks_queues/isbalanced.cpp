#include <bits/std++.h>
bool ispar(string x)
{
    // Your code here
    stack<char> st;
    for(int i = 0; i<x.size(); i++){
        if(x[i] == '(' || x[i] == '[' || x[i] == '{')
            st.push(x[i]);
        else if(x[i] == ')' && !st.empty() && st.top() == '(')
            st.pop();
        else if(x[i] == ']' && !st.empty() && st.top() == '[')
            st.pop();
        else if(x[i] == '}' && !st.empty() && st.top() == '{')
            st.pop();
        else
            return false;
    }
    return st.empty();
}

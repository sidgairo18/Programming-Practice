#include <bits/stdc++.h>

using namespace std;

map<char, int> order;

void infix_to_postfix(string s){
    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        if(order.find(s[i]) == order.end()){
            cout<<s[i];
        }
        else if(s[i] == ')'){
            while(st.top() != '('){
                cout<<st.top();
                st.pop();
            }
            //cout<<st.top();
            st.pop();
        }
        else if(st.empty() || s[i] == '(' || order[s[i]] > order[st.top()])
            st.push(s[i]);
        else{
            
            while(!st.empty() && st.top() != '(' && order[s[i]] <= order[st.top()]){
                cout<<st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return;
}

int main(){

    order['-'] = 0;
    order['+'] = 0;
    order['*'] = 2;
    order['/'] = 2;
    order['^'] = 4;
    order['('] = 5;
    order[')'] = 6;

    string s;
    cin>>s;
    infix_to_postfix(s);

    return 0;
}

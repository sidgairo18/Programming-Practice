#include <bits/stdc++.h>

using namespace std;
map<char, int> order;

int evaluate(int a, int b, char op){

    if(op == '+')
        return a+b;
    if(op == '-')
        return a-b;
    if(op == '/')
        return a/b;
    if(op == '*')
        return a*b;
    if(op == '^')
        return pow(a,b);
}

int evaluatePostfix(string &str)
{
    stack<int> st;
    for(int i = 0; i<str.size(); i++){
        
        if(order.find(str[i]) == order.end())
            st.push(str[i]-'0');
        else{
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            st.push(evaluate(b,a,str[i]));
        }
    }
    return st.top();
}

int main(){
    order['-'] = 0;
    order['+'] = 0;
    order['*'] = 2;
    order['/'] = 2;
    order['^'] = 4;
    order['('] = 5;
    order[')'] = 6;

    string s; cin>>s;
    cout<<evaluatePostfix(s)<<endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace  std;

int main(){

    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;
        stack<char> st;
        int flag = -1;

        for(int i = 0; i<s.size(); i++){

            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            else 
            {
                if(!st.empty() && s[i] == '}' && st.top() == '{')
                    st.pop();
                else if(!st.empty() && s[i] == ')' && st.top() == '(')
                    st.pop();
                else if(!st.empty() && s[i] == ']' && st.top() == '[')
                    st.pop();
                else{
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1 || !st.empty())
            cout<<"not balanced"<<endl;
        else
            cout<<"balanced"<<endl;

    }

    return 0;
}

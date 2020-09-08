#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        stack<char> st;
        string s;
        cin>>s;
        
        int count = 0;
        for(int i = 0; i<n; i++){

            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')'){
                if(!st.empty())
                    st.pop();
                else
                    count++;
            }
        }

        count += st.size();
        cout<<count/2<<endl;

    }

    return 0;
}

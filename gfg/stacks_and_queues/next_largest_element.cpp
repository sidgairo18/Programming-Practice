#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> out(n, -1);

        for(int i = 0; i<n; i++)
            cin>>v[i];

        stack<int> st;

        for(int i = 0; i<n; i++){

            if(st.empty() || v[st.top()] >= v[i])
                st.push(i);
            else{

                while(!st.empty() && v[st.top()] < v[i]){
                    out[st.top()] = v[i];
                    st.pop();
                }
                st.push(i);

            }
        }

        for(int i = 0; i<n; i++)
            cout<<out[i]<<" ";
        cout<<endl;

    }

    return 0;
}

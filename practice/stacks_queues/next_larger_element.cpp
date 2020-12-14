#include <bits/stdc++.h>

using namespace std;

vector <long long> nextLargerElement(long long arr[], int n){
    // Your code here
    
    vector<long long> ans(n, -1);
    stack<int> st;
    for(int i = 0; i<n; i++){
        if(st.empty()){
            st.push(i);
        }
        else if(arr[st.top()] >= arr[i]){
            st.push(i);
        }
        else{
            while(!st.empty() && arr[st.top()] < arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    
    return ans;
}

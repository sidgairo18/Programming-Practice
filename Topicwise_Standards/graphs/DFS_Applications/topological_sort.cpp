#include <bits/stdc++.h>

using namespace std;

stack<int> st;
int visited[100005];

int topoSort(int v, vector<int> *G){

    visited[v] = 1;
    int sz = G[v].size();

    for(int i = 0; i<sz; i++)
        if(!visited[G[v][i]])
            topoSort(G[v][i], G);

    st.push(v);
}

int main(){

    int m,n,x,y;
    cin>>m>>n;

    for(int i = 0; i<n; i++)
        visited[i] = 0;

    vector<int> G[100005];

    for(int i = 0; i<m; i++){
        cin>>x>>y;
        G[x].push_back(y);
    }
    
    for(int i = 0; i<n; i++){
        if(!visited[i])
            topoSort(i, G);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}

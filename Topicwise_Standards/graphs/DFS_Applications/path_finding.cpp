#include <bits/stdc++.h>

//References : http://ww3.algorithmdesign.net/handouts/DFS.pdf
//
//Note - This program and it's working has not been fully tested.

using namespace std;

int visited[100005];

stack<int> st;

int path_finding(int v, int z, vector<int> *G){

    visited[v] = 1;
    st.push(v);

    int sz = G[v].size();

    if ( v == z){
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }

    for(int i = 0; i<sz; i++)
        if(!visited[G[v][i]])
            path_finding(G[v][i], z, G);

    st.pop();

}

int main(){

    int m,n,x,y;
    cin>>m>>n;

    int u,z;
    cin>>u>>z;

    for(int i = 0; i<n; i++)
        visited[i] = 0;

    vector<int> G[100005];

    for(int i = 0; i<m; i++){
        cin>>x>>y;
        G[x].push_back(y);
    }

    path_finding(u,z,G);

    return 0;
}

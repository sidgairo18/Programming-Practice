#include <bits/stdc++.h>

using namespace std;

stack<int> st;
void dfs(vector<int> *G, int v, int flag, bool visited[]){

    visited[v] = true;
    if(flag)
        cout<<v<<" ";
    int sz = G[v].size();

    for(int i = 0; i<sz; i++)
        if(!visited[G[v][i]])
            dfs(G, G[v][i], flag, visited);

    st.push(v);
}

int main(){

    int m,n,x,y;
    cin>>m>>n;

    vector<int> G[n];
    vector<int> GT[n];

    bool visited[n];
    for(int i = 0; i<n; i++)
        visited[i] = false;

    for(int i = 0; i<m; i++){
        cin>>x>>y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }

    for(int i = 0; i<n; i++)
        if(!visited[i])
            dfs(G, i, 0, visited);

    for(int i = 0; i<n; i++)
        visited[i] = false;

    while(!st.empty()){

        int v = st.top();
        st.pop();

        if(!visited[v]){
            dfs(GT, v, 1, visited);
            cout<<endl;
        }
    }


}

#include <bits/stdc++.h>

//Assumimg graph G is stored as an adjacency list.
//G is a directed, unqweighted graph.

using namespace std;

void dfs(int v, vector<int> *G, vector<int> vis){

    vis[v] = 1;
    cout<<v<<" ";

    int sz = G[v].size();

    for(int i = 0; i<sz; i++)
        if(vis[G[v][i]] == -1){
            dfs(G[v][i], G, vis);
        }
    
    return;
}

int main(){
    
    vector<int> G[100005];
    int m, n;
    cin>>m>>n;
    vector<int> vis(n,-1);

    int x,y;
    for(int i = 0; i<m; i++){
        cin>>x>>y;
        G[x].push_back(y);
    }

    dfs(2, G, vis);
    cout<<endl;

    return 0;
}

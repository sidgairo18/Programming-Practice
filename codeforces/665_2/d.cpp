#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> > g, int v, int p, int *visited, int *counts){

    visited[v] = 1;
    counts[v] = 1;

    for(int i = 0; i<g[v].size(); i++){
        int u = g[v][i];
        if(visited[u] == -1){
            dfs(g, u, v, visited, counts);
            counts[v] += counts[u];
        }
    }

    cout<<v<<" counts: "<<counts[v]<<endl;
}

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<vector<int> > g(n+1);
        int visited[n+1];
        memset(visited, -1, sizeof(visited));

        int x, y;
        vector<pair<int, pair<int,int> > >  edges;

        for(int i = 0; i<n-1; i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
            edges.push_back(make_pair(-1, make_pair(x,y)));
        }

        int counts[n+1];
        memset(counts, 0, sizeof(counts));

        dfs(g, 1, -1, visited, counts);

        int ans = -1;

        cout<<ans<<endl;

    }

    return 0;
}

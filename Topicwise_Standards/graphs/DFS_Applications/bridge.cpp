/*A brigde is an edge analogous to an articulation point(vertex)
 *
 * An edge (u,v) is a bridge if u is the parent of v in the DFS tree, and there is no way to reach u or any of
 * it's ancestors from sub-tree rooted with v.
 *
 * condition for an edge (u,v) to be a bridge - low[v] > disc[u]
 */

#include <bits/stdc++.h>

using namespace std;

void dfs_bridge(vector<int> *G, int *disc, int *low, int *visited, int *parent, int u){

    static int time = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    int sz = G[u].size();

    for(int i = 0; i<sz; i++){

        int v = G[u][i];

        if(visited[v] == -1){

            parent[v] = u;
            dfs_bridge(G, disc, low, visited, parent, v);

            low[u] = min(low[u], low[v]);

            if(low[v] > disc[u])
                printf("%d %d\n", u, v);
        }
        else if(v != parent[u])
            low[u] = min(low[u], disc[v]);

    }
    return;
}

int main(){
    
    int n,m;
    scanf("%d%d", &n, &m);
    vector<int> G[n];

    for(int i = 0; i<m; i++){
        int x,y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int parent[n];
    int visited[n];
    int low[n];
    int disc[n];

    for(int i = 0; i<n; i++){
        visited[i] = parent[i] = -1;
        low[i] = disc[i] = INT_MAX;
    }

    dfs_bridge(G, disc, low, visited, parent, 0);

    return 0;
}

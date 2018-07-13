/*An articulation point is a vertex/node in a connected graph removing which makes the graph not connected.
 * For graphs which have components, then it is a node removing which increases the number of components.
 * For a node u to be an articulation point one of the following 2 must hold
 * 1. If u is the root of the DFS tree, then it should have atleast 2 children.
 * 2. If u is not the root of the DFS tree, then it should have a child v such that there is no back edge from any
 *    of the vertices in the subtree rooted at v to one of the ancestors of u.
 *
 * low[u] = min(disc[u], disc[w]) - where w is an acestor of u, and there is a back edge from one the descendents of
 * u to w.
 */

#include <bits/stdc++.h>

using namespace std;

void dfs_ap(vector<int> *G, int *parent, int *disc, int *low, int *visited, int *ap, int u){

    static int time = 0;
    int children = 0;
    visited[u] = 1;

    low[u] = disc[u] = ++time;
    int sz = G[u].size();

    for(int i = 0; i<sz; i++){
        int v = G[u][i];
        if(visited[v] == -1){

            parent[v] = u;
            children++;

            dfs_ap(G, parent, disc, low, visited, ap, v);

            low[u] = min(low[u], low[v]);

            //condition 1
            if (parent[u] == -1 && children > 1)
                ap[u] = 1;

            if (parent[u]!=-1 && low[v] >= disc[u])
                ap[u] = 1;

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
    int disc[n];
    int low[n];
    int visited[n];
    int ap[n];

    for(int i = 0; i<n; i++){
        parent[i] = visited[i] = ap[i] = -1;
        low[i] = disc[i] = INT_MAX;
    }

    dfs_ap(G, parent, disc, low, visited, ap, 0);

    for(int i = 0; i<n; i++)
        if(ap[i] == 1)
            printf("%d\n", i);

    return 0;
}

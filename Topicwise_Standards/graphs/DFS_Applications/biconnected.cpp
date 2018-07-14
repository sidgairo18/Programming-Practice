/* An undirected graph is called Biconnected if there are two vertex-disjoint paths between any two vertices. 
 * In a Biconnected Graph, there is a simple cycle through any two vertices.
 * A connected graph is Biconnected if it is connected and doesn’t have any Articulation Point. We mainly need to check two things in a graph.
 * 1) The graph is connected. 
 * 2) There is not articulation point in graph.
 *
 */

#include <bits/stdc++.h>

using namespace std;
bool dfs_bicon(vector<int> *G, int *visited, int *parent, int *disc, int *low, int u){
   
    int children = 0; 
    static int time = 0;
    //cout<<u<<" ";
    visited[u] = 1;
    disc[u] = low[u] = ++time;
    int sz = G[u].size();

    for(int i = 0; i<sz; i++){

        int v = G[u][i];

        if(visited[v] == -1){
            children++;
            parent[v] = u;

            if(dfs_bicon(G, visited, parent, disc, low, v))
                return true;

            low[u] = min(low[u], low[v]);

            //check 1
            if(parent[u] == -1 && children>1)
                return true;

            if(parent[u] != -1 && low[v] >= disc[u])
                return true;

        }
        else if(v != parent[u])
            low[u] = min(low[u], disc[v]);

    }

    return false;
}

int main(){

    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> G[n];
    int parent[n];
    int visited[n];
    int disc[n];
    int low[n];


    for(int i = 0; i<m; i++){
        int x,y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int i = 0; i<n; i++){
        visited[i] = parent[i] = -1;
        disc[i] = low[i] = INT_MAX;
    }

    bool ans = !dfs_bicon(G, visited, parent, disc, low, 0);
    //cout<<endl;
    //cout<<ans<<endl;

    for(int i = 0; i<n; i++)
        if(visited[i] == -1)  
        {   
            //cout<<"YES "<<i<<endl;
            ans = false;
            break;
        }

    if(ans)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}

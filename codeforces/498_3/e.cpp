#include <bits/stdc++.h>

using namespace std;

vector<int> G[200005];
vector<int> dfs_vec;
map<int, pair<int, int> > mp;

void dfs(int u, int *visited){
    
    dfs_vec.push_back(u);
    mp[u].first = dfs_vec.size();
    mp[u].second = dfs_vec.size();
    visited[u] = 1;

    int sz = G[u].size();

    for(int i = 0; i<sz; i++){

        int v = G[u][i];
        if(visited[v] == -1)
            dfs(v, visited);
    }

    mp[u].second = dfs_vec.size();
}


int main(){

    int n, q;
    scanf("%d%d", &n, &q);

    for(int i = 1; i<n; i++){

        int x;
        scanf("%d", &x);
        x--;
        G[x].push_back(i);
    }

    for(int i = 0; i<n; i++)
        if(G[i].size() > 0)
            sort(G[i].begin(), G[i].end());

    int u, k;

    int visited[n];
    for(int i = 0; i<n; i++)
        visited[i] = -1;

    dfs(0, visited);

    while(q--){

        scanf("%d%d", &u, &k);
        u--;

        if(mp[u].second - mp[u].first + 1 < k){
            printf("-1\n");
            continue;
        }

        int ans = mp[u].first + k-1 - 1;
        printf("%d\n", dfs_vec[ans]+1);
    }

    return 0;

}

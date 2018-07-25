#include <bits/stdc++.h>

using namespace std;

vector<int> G[10005];
vector<int> D[10005];
vector<int> dist(10005);
vector<int> mx(10005);
int visited[10005];

int dfs(int u, int d){

    visited[u] = 1;
    int sz = G[u].size();
    mx[u] = d;
    dist[u] = d;

    for(int i = 0; i<sz; i++){
        int v = G[u][i];
        if(visited[v] != 1){
            mx[u] = max(dfs(v, d+1), mx[u]);
            D[u].push_back(mx[v]-dist[v]+1);
        }
    }
    return mx[u];
}


int main(){

    int n;
    scanf("%d", &n);

    for(int i = 0; i<n-1; i++){
        int x,y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(0,0);
    
    int ans = 0;
    for(int i = 0; i<n; i++){
        //cout<<i<<" MAX "<<mx[i]<<" DIST "<<dist[i]<<endl;
        sort(D[i].rbegin(), D[i].rend());
        /*cout<<i<<" ";
        for(int j = 0; j < D[i].size(); j++)
            cout<<D[i][j]<<" ";
        cout<<endl;
        */
        if (D[i].size() >= 2)
            ans = max(D[i][0]+D[i][1], ans);
        else if(D[i].size() == 1)
            ans = max(D[i][0], ans);
    }

    printf("%d\n", ans);

    return 0;
}


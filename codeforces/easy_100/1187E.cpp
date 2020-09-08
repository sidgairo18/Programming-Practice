#include <bits/stdc++.h>

using namespace std;

vector<int> g[200005];
vector<long long int> dp(200005);
vector<long long int> Size(200005);

void get_Size(int v, int p){

    Size[v] = 1;
    for(int i=0; i<g[v].size(); i++)
        if(g[v][i] != p){
            get_Size(g[v][i], v);
            Size[v] += Size[g[v][i]];
        }
}

void get_dp(int v, int p){

    dp[v] = Size[v];

    for(int i=0;i<g[v].size();i++){
        int u = g[v][i];
        if(u!=p){
            get_dp(u,v);
            dp[v] += dp[u];
        }
    }
}

long long int ans = -1;

void dfs(int v, int p){

    ans = max(ans, dp[v]);
    
    for(int i = 0; i<g[v].size(); i++){
        int u = g[v][i];
        // re-rooting happening here
        if(u ==  p)
            continue;

        dp[v] -= (dp[u]+Size[u]);
        Size[v] -= Size[u];
        dp[u] += (Size[v] + dp[v]);
        Size[u] += Size[v];
        dfs(u,v);

        dp[u] -= (dp[v] + Size[v]);
        Size[u] -= Size[v];
        dp[v] += (Size[u] + dp[u]);
        Size[v] += Size[u];

    }
}

int main(){

    int n;
    cin>>n;

    int x,y;

    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        x--,y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    get_Size(0,-1);
    get_dp(0,-1);
    dfs(0,-1);
    cout<<ans<<endl;

    return 0;
}

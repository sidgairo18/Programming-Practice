#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

vector<long long int> ans;
vector<vector<int> >  g(100005);
long long int n;
int visited[100005];
long long int counts[100005];

void dfs(int v, int p){

    visited[v] = 1;
    counts[v] = 1;

    for(int i = 0; i<g[v].size(); i++){
        int u = g[v][i];
        if(visited[u] == -1){
            dfs(u, v);
            counts[v] += counts[u];
            ans.push_back((counts[u]*(n-counts[u])));
        }
    }
}

int main(){

    int t;
    cin>>t;

    while(t--){

        cin>>n;

        memset(visited, -1, sizeof(visited));

        // resetting  the graph
        for(int i = 1; i<=n; i++)
            g[i].clear();

        int x, y;
        for(int i = 0; i<n-1; i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        memset(counts, 0, sizeof(counts));
        
        ans.clear();
        dfs(1, -1);

        sort(ans.rbegin(), ans.rend());

        int m;
        cin>>m;
        vector<long long int> k(m);
        for(int i=0; i<m; i++)
            cin>>k[i];

        while(k.size() < n-1)
            k.push_back(1);
        sort(k.begin(), k.end());

        vector<long long int> k_2;
        int i = k.size()-1;
        long long int p = k[i--];
        while(i>=0){
            if(i>=n-2)
                p = (p*k[i--])%mod;
            else if(k_2.size() == 0)
                k_2.push_back(p);
            else
                k_2.push_back(k[i--]);
        }

        if(k_2.size() == 0)
            k_2.push_back(p);

        p = 0;
        for(int i = 0; i<n-1; i++)
            p = (p+ ((ans[i]%mod)*k_2[i])%mod)%mod;

        cout<<p<<endl;

    }

    return 0;
}

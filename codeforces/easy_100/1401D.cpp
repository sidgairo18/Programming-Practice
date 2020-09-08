#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

vector<int> g[200005];
vector<long long int> prod;
vector<long long int> Size(200005);
long long int n;

long long int dfs_reroot(int u, int p){

    Size[u] = 1;

    for(int i = 0; i<g[u].size(); i++){

        int v = g[u][i];
        if(v == p)
            continue;

        Size[v] = dfs_reroot(v,u);
        Size[u] += Size[v];
        prod.push_back(Size[v]*(n-Size[v]));
    }
    
    return Size[u];
}

int main(){

    int t;
    cin>>t;

    while(t--){

        cin>>n;

        // clear prod;
        prod.clear();

        // clear graph g
        for(int i = 0; i<n; i++)
            g[i].clear();

        for(int i = 0; i<n-1; i++){
            int x,y;
            cin>>x>>y;
            x--,y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int m;
        cin>>m;

        vector<long long int> k(m);
        for(int i = 0; i<m; i++)
            cin>>k[i];

        while(k.size() < n-1)
            k.push_back(1);

        sort(k.begin(), k.end());

        vector<long long int> k2;
        int i = k.size()-1;
        long long int p = k[i--];

        while(i >= n-2){
            p = (p*k[i--])%mod;
        }
        
        k2.push_back(p);
        while(i>=0){
            k2.push_back(k[i--]);
        }

        dfs_reroot(0, -1);

        //  sort prod
        sort(prod.rbegin(), prod.rend());

        long long int ans = 0;
        //cout<<prod.size()<<" "<<k2.size()<<endl;

        for(int i = 0; i<n-1; i++)
            ans = (ans + (prod[i]%mod * k2[i])%mod)%mod;

        cout<<ans<<endl;
    }

    return 0;
}

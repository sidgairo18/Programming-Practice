#include <bits/stdc++.h>

using namespace std;

vector<pair<int,long long int> > g[200005];
vector<long long  int>  Size(200005);
long long int max_ans = 0;
long long int min_ans = 0;
long long int k;

void dfs(int v, int p){

    Size[v] = 1;

    for(int i = 0; i<g[v].size(); i++){
        
        int u = g[v][i].first;
        long long int w = g[v][i].second;

        if(u == p)
            continue;
        
        dfs(u,v);
        Size[v] += Size[u];
        max_ans += min(Size[u], 2*k-Size[u])*w;
        min_ans += (Size[u]%2)*w;
        //#cout<<"Yes "<<max_ans<<" "<<min_ans<<" "<<Size[u]<<endl;
    }

}

int main(){

    int t;
    cin>>t;

    while(t--){
        cin>>k;

        for(int i=0; i<2*k; i++)
            g[i].clear();

        for(int i = 0; i<2*k-1; i++){
            int  x,y;
            long long int w;
            cin>>x>>y>>w;
            x--,y--;
            g[x].push_back(make_pair(y,w));
            g[y].push_back(make_pair(x,w));
        }
        max_ans = min_ans = 0;
        dfs(0, -1);
        cout<<min_ans<<" "<<max_ans<<endl;
    }

    return 0;
}

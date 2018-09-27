#include <bits/stdc++.h>

#define sz 1000005
#define il (int)ceil(log2(sz))
using namespace std;

int n, q;
vector<int> g[sz];
vector<int> arr(sz);
int vis[sz];
int tb[sz][il+1];
int mx[sz];
int ct[sz];
int l;

void dfs(int v, int p){

    tb[v][0] = p;
    vis[v] = 1;
    if(v == 1){
        ct[v] = 1;
        mx[v] = arr[1];
    }
    else{

        if(mx[p] < arr[v])
        {
            mx[v] = arr[v];
            ct[v] = 1+ct[p];
        }
        else{
            mx[v] = mx[p];
            ct[v] = ct[p];
        }

    }

    for(int i = 0; i<g[v].size(); i++){

        int cur = g[v][i];
        if(vis[cur] == -1)
            dfs(cur, v);
    }

}

int main(){

    int t, a, b, v, w;
    scanf("%d", &t);


    while(t--){
        scanf("%d", &n);
        l = ceil(log2(n));

        for(int i = 0; i<=n; i++)
        {
            g[i].clear();
            mx[i] = -1;
            ct[i] = 0;
        }

        for(int i = 1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        int p;
        for(int i = 2; i<=n; i++){
            scanf("%d", &p);
            g[i].push_back(p);
            g[p].push_back(i);
        }
        
        for(int i = 0; i<=n; i++)
            vis[i] = -1;

        dfs(1, 1);
        
        scanf("%d", &q);

        int pr = 0;
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &a, &b);
            v = a^pr;
            w = b^pr;
            int j = l;
            int x = v;
            while(j >= 0)
            {
                if(mx[tb[x][j]] > w)
                    x = tb[x][j];
                j--;
            }
            ct[0] = 0;
            if(x == 1)
                x--;
            else
                x = tb[x][0];
            pr = ct[v] - ct[x];
            printf("%d\n", pr);

        }


    }

    return 0;
}

#include <bits/stdc++.h>

#define MAXN 1<<11

using namespace std;

int g[11][MAXN];

int hamil_path_short(int n){

    int dp[n][MAXN];

    for(int i = 0; i<MAXN; i++)
        for(int j = 0; j<n; j++)
            dp[j][i] = INT_MAX;

    for(int i = 0; i<n; i++)
        dp[i][1<<i] = g[i][i];

    for(int i = 0; i<MAXN; i++){

        for(int j = 0; j<n; j++){

            if(i&(1<<j)){

                for(int k = 0; k<n; k++){

                    if(j!=k && (1<<k)&i && g[j][k]>=0 && dp[k][(1<<j)^i] != INT_MAX){
                        cout<<"YES"<<endl;
                        dp[j][i] = min(dp[j][i], dp[k][(1<<j)^i] + g[j][k]);
                    }
                }
            }
        }
    }
    
    int ans = INT_MAX;
    for(int i = 0; i<n; i++)
        if(dp[i][1<<(n)-1] != INT_MAX){
            ans = min(dp[i][1<<(n) - 1], INT_MAX);
        }
    return ans;
}

int main(){

    //initialize graph
    for(int i = 0; i<10; i++)
        for(int j = 0; j<MAXN; j++){
            g[i][j] = -1;
            if(i == j)
                g[i][j] = 0;
        }

    int n, m;
    cin>>n>>m;

    int x,y, w;
    for(int i = 0; i<m; i++){
        cin>>x>>y>>w;
        x--;
        y--;
        g[x][y] = w;
        g[y][x] = w;
    }

    int ans = hamil_path_short(n);

    cout<<ans<<endl;

    return 0;
}



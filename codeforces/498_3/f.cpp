#include <bits/stdc++.h>

using namespace std;

//meet in the middle solution

int n,m, mid;
long long mat[25][25];
map<long long, int> mp[25][25];
long long ans, k;

void func1(int i, int j, long long sm, int cnt){
    
    if (i >= n || j >= m)
        return;
    sm = sm^mat[i][j];

    if(cnt == mid){
        //cout<<"Yes1 "<<i<<" "<<j<<" "<<sm<<endl;
        mp[i][j][sm]++;
        return;
    }

    func1(i+1, j, sm, cnt+1);
    func1(i, j+1, sm, cnt+1);
}

void func2(int i, int j, long long sm, int cnt){

    if(i<0 || j<0)
        return;


    if(cnt == (n+m-2-mid)){
        //cout<<"Yes2 "<<i<<" "<<j<<" "<<(sm^k)<<endl;
        ans += mp[i][j][(k^sm)];
        return;
    }

    sm = sm^mat[i][j];
    func2(i-1, j, sm, cnt+1);
    func2(i, j-1, sm, cnt+1);
}

int main(){
    
    ans = 0;//initialize ans
    scanf("%d%d%lld", &n, &m, &k);
    mid = (n+m-2)/2;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%lld", &mat[i][j]);

    func1(0,0,0,0);
    func2(n-1,m-1,0,0);

    printf("%lld\n", ans);

    return 0;
}

/* Naive Solution
int n,m;
long long int mat[21][21];

long long int dp[21][21];

long long int func(int i, int j, long long int sm, long long int k){
    
    if(i >= n || j >=m)
        return 0;

    sm = sm^mat[i][j];
    if(i == n-1 && j == m-1 && sm == k)
        return 1;
    return func(i+1, j, sm, k) + func(i, j+1, sm, k);
}



int main(){


    scanf("%d%d", &n, &m);

    long long int k;
    scanf("%lld", &k);

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++){
            scanf("%lld", &mat[i][j]);
            if(i == 0 || j == 0)
                dp[i][j] = mat[i][j];
        }



    long long int ans = func(0, 0, 0, k);

    printf("%lld\n", ans);


    return 0;

}
*/


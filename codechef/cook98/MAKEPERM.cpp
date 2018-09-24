#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);
        int x;
        map<int, int> mp;

        for(int i = 0; i<n; i++){

            scanf("%d", &x);
            mp[x] = 1;
        }

        int ans = 0;
        for(int i = 1; i<=n; i++)
            if(mp[i] == 0)
                ans++;

        printf("%d\n", ans);

    }

    return 0;
}

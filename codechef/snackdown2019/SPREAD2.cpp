#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int t, n, x;
    scanf("%lld", &t);

    while(t--){

        scanf("%lld", &n);
        vector<long long int> a;

        for(long long int i = 0; i<n; i++){
            scanf("%lld", &x);
            a.push_back(x);
        }

        long long int ans = 0;
        long long int left = n-1;
        long long int curr = a[0];
        long long int i = 0;

        while(left > 0){

            ans++;
            left -= curr;
            long long int limit = min(i+curr+1, n);
            i++;
            for(; i<limit; i++)
                curr += a[i];
            i--;
        }

        printf("%lld\n", ans);

    }

    return 0;
}

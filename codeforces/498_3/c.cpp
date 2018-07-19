#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    set<long long> s;

    long long l = 0;
    long long arr[200005];

    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%lld", &arr[i]);
        l += arr[i];
        s.insert(l);
    }

    long long ans = 0;
    long long int r = 0;

    for(int i = n-1; i>=0; i--){

        s.erase(l);
        l -= arr[i];
        r += arr[i];

        if(s.find(r) != s.end())
            ans = max(r, ans);
    }

    printf("%lld\n", ans);

    return 0;
}

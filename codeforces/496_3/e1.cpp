#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    scanf("%d%d", &n, &m);

    vector<int> arr(n);

    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    map<long long int, long long int> s;

    s[0] = 1;
    long long int s_run = 0;

    int flag = 0;

    long long int ans = 0;

    for(int i = 0; i<n; i++){

        if(arr[i] < m)
            s_run--;
        else if(arr[i] > m)
            s_run++;

        if(arr[i] == m)
            flag = 1;

        if(flag)
            ans += s[s_run] + s[s_run-1];
        else
            s[s_run]++;
    }

    printf("%lld\n", ans);

    return 0;
}

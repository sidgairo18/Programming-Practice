#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    scanf("%d%d", &n, &k);

    vector<long long int> a(n);

    for(int i = 0; i<n; i++)
        scanf("%lld", &a[i]);

    long long int g = a[0];
    for(int i = 1; i<n; i++)
        g = __gcd(g, a[i]);

    map<int, int> m;
    vector<int> ans;

    long long int temp = g;

    while(true){

        int d = temp%k;
        if(m.find(d) == m.end())
            m[d] = 1;
        else
            break;
        ans.push_back(d);
        temp += g;
    }

    int sz = ans.size();
    printf("%d\n", sz);
    sort(ans.begin(), ans.end());
    for(int i = 0; i<sz; i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}


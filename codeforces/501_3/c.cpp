#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    scanf("%d%d", &n, &m);

    vector<long long int> a;
    vector<long long int> b;
    vector< pair<long long int, int> > c;

    long long int check = 0;
    long long int diff = 0;

    for(int i = 0; i<n; i++){

        long long int x,y;
        scanf("%lld%lld", &x, &y);

        a.push_back(x);
        b.push_back(y);
        c.push_back(make_pair(x-y, i));
        check += y;
        diff += x;
    }
    
    sort(c.rbegin(), c.rend());

    if(check > m)
    {
        printf("-1\n");
        return 0;
    }

    int ans = 0;

    for(int i = 0; i<n; i++){

        if(diff <= m)
            break;
        diff -= c[i].first;
        ans++;
    }

    printf("%d\n", ans);



    return 0;
}

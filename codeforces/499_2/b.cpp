#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    scanf("%d%d", &n, &m);

    vector<int> a(101,0);

    for(int i = 0; i<m; i++){
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    vector<int> c;
    for(int i = 0; i<=100; i++)
        if(a[i] > 0)
            c.push_back(a[i]);


    sort(c.rbegin(), c.rend());

    int ans = 100;

    while(true){
        
        int sz = c.size();
        vector<int> b(sz);
        for(int i = 0; i<sz; i++)
            b[i] = c[i];
        
        int j = 0;
        int i = 0;
        for(i = 0; i<n; i++){
            if(b[j]>= ans)
                b[j] -= ans;
            else{
                i--;
                j++;
            }
            if(j>=sz)
                break;
        }

        if(i == n && j<sz)
            break;
        ans--;
    }

    printf("%d\n", ans);


    return 0;
}

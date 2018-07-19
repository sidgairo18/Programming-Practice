#include <bits/stdc++.h>

using namespace std;

int main(){

    map<int, int> m;
    int n,k;
    scanf("%d%d", &n, &k);

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i<n; i++){

        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b.rbegin(), b.rend());

    for(int i = 0; i<k; i++)
        if(m.find(b[i]) == m.end())
            m[b[i]] = 1;
        else
            m[b[i]] += 1;

    int sz = 0;
    vector<int> ans;

    for(int i = 0; i<n; i++){

       sz++;
       if(m.find(a[i]) != m.end() && m[a[i]] > 0)
       {
          ans.push_back(sz);
          sz = 0;
          m[a[i]] -= 1;
       }
       if(ans.size() == k-1)
          break; 

    }
    sz = 0;
    for(int i = 0; i<k; i++)
        sz += b[i];
    printf("%d\n", sz);
    sz = 0;
    for(int i = 0; i < (k-1); i++){

        printf("%d ", ans[i]);
        sz += ans[i];
    }

    printf("%d\n", n-sz);



    return 0;

}

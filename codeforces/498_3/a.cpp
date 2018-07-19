#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int a[1005];
    vector<int> b;
    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
        b.push_back(a[i]);
        if(a[i]%2==0)
            b.push_back(a[i]-1);
        else
            b.push_back(a[i]+1);
    }
    
    sort(b.begin(), b.end());
    int sz = b.size();
    map<int, int> m;

    for(int i = 0; i<sz; i++){

        int cur = b[i];

        if(m[cur] == 1)
            continue;

        for(int j = 0; j<n; j++){

            if ( a[j] == cur){
                if (a[j]%2 == 0)
                    a[j]--;
                else
                    a[j]++;

            }

        }

        m[cur] = 1;

    }

    for(int i = 0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x;
    scanf("%d", &n);

    int count = 0, run = 0;

    vector<int> ans;

    for(int i = 0; i<n; i++){

        scanf("%d", &x);
        if( x == 1)
        {
            ans.push_back(run);
            run = 0;
            count++;
        }
        run++;
    }
    ans.push_back(run);

    printf("%d\n", count);
    int sz = ans.size();

    for(int i = 1; i<sz; i++)
        printf("%d ", ans[i]);

    printf("\n");



    return 0;
}

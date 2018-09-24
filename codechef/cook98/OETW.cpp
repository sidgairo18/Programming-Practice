#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);
        int first, last;
        int s = 0;

        for(int i = 0; i<n; i++){

            scanf("%d", &last);
            s += last;
            if(i == 0)
                first = last;
        }

        int ans = -1;

        if(s == n || s == 2*n){
            ans = n;
        }
        else if(first == last && first == 2)
            ans = s-1;
        else
            ans = s;

        printf("%d\n", ans);

    }

    return 0;
}

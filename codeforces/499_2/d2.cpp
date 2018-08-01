#include <bits/stdc++.h>

using namespace std;

int main(){

    int m,n, t;
    scanf("%d%d", &m, &n);

    vector<int> p(n);

    for(int i = 0; i<n; i++){
        printf("1\n");
        fflush(stdout);
        scanf("%d", &t);
        if(t==0){
            return 0;
        }
        if(t == -1)
            p[i] = 0;
        else if(t == 1)
            p[i] = 1;
        else
            return 0;
    }


    int run = 0;
    int l = 1;
    int r = m;

    while(l<=r){
        int x = (l+r)/2;

        printf("%d\n", x);
        fflush(stdout);
        scanf("%d", &t);

        if(p[run] == 1)
            if(t == 1)
                l = x+1;
            else if(t == -1)
                r = x-1;
            else
                return 0;
        else
            if(t == -1)
                l = x+1;
            else if(t == 1)
                r = x-1;
            else
                return 0;
        run = (run+1)%n;
    }

    return 0;
}

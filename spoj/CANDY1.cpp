#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    while(true){

        scanf("%d", &n);
        if(n==-1)
            break;

        int total = 0;
        vector<int> v;
        for(int i = 0; i<n; i++){
            int x;
            scanf("%d", &x);
            total+=x;
            v.push_back(x);
        }
        if(total%n != 0)
        {
            printf("-1\n");
            continue;
        }

        int moves = 0;

        for(int i = 0; i<n; i++)
            if((total/n)>v[i])
                moves += (total/n)-v[i];
        printf("%d\n", moves);

    }

    return 0;
}

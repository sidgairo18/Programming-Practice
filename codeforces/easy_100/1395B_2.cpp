#include <bits/stdc++.h>

using namespace std;

void f(int i, int j, int n, int m, int sx, int sy){

    cout<<(i+sx-2)%n+1<<" "<<(j+sy-2)%m+1<<endl;
}

int main(){

    int n,m,sx,sy;
    cin>>n>>m>>sx>>sy;

    for(int i = 1; i<=n; i++){
        if(i&1)
            for(int j = 1; j<=m; j++)
                f(i,j,n,m,sx,sy);
        else
            for(int j=m; j>=1; j--)
                f(i,j,n,m,sx,sy);
    }

    return 0;
}

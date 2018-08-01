#include <bits/stdc++.h>

using namespace std;

int main(){

    int arr[105];

    int n,m;
    scanf("%d%d", &n, &m);
    int l,r;

    for(int i = 0; i<=m; i++)
        arr[i] = -1;

    for(int i = 0; i<n; i++){

        scanf("%d%d", &l, &r);
        for(int j = l; j<=r; j++)
            arr[j] = 1;
    }
    
    int count = 0;
    for(int i = 1; i<=m; i++){

        if(arr[i] == -1)
            count++;
    }

    printf("%d\n", count);

    for(int i = 1; i<=m; i++)
        if(arr[i] == -1)
            printf("%d ", i);
    printf("\n");


    return 0;
}

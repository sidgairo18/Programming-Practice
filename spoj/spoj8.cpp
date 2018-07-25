#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    while(true){

        scanf("%d", &n);
        if(n == 0)
            break;

        int sum = 0;

        for(int i = 1; i<=n; i++)
            sum += i*i;

        printf("%d\n", sum);

    }

    return 0;
}

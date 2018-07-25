#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,n;
    scanf("%d",&t);

    while(t--){

        scanf("%d", &n);
        int m = 1;
        int a[200];
        a[0] = 1;
        int carry = 0;

        for(int i = 1; i<=n; i++){

            for(int j = 0; j<m; j++){

                int x = a[j]*i + carry;
                a[j] = x%10;
                carry = x/10;
            }

            while(carry){
                a[m] = carry%10;
                m++;
                carry /= 10;
            }

        }

        for(int i = m-1; i>=0; i--)
            printf("%d", a[i]);
        printf("\n");

    }

    return 0;
}

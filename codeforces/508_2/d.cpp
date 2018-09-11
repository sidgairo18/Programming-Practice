#include <bits/stdc++.h>

using namespace std;

int main(){

    //I think this may just work. :)
    

    int n;
    scanf("%d", &n);

    int pos = 0;
    int neg = 0;

    long long int ans = 0;

    long long int a[500005];
    for(int i = 0; i<n; i++){
        scanf("%lld", &a[i]);
        if(a[i] >= 0)
            pos++;
        else
            neg++;
    }

    if(n == 1){
        printf("%lld\n", a[0]);
        return 0;
    }
    if(pos > 0 && neg > 0){

        for(int i = 0; i<n; i++)
            if(a[i] < 0)
                ans = ans-a[i];
            else
                ans += a[i];
    }
    else{

        if(neg == n)
            for(int i = 0; i<n; i++)
                a[i] = -1*a[i];
        
        long long int sm = 1000000000+1;
        for(int i = 0; i<n; i++){
            sm = min(sm, a[i]); 
        }

        for(int i = 0; i<n; i++)
            ans += a[i];

        ans = ans-2*sm;
    }

    printf("%lld\n", ans);


    return 0;
}

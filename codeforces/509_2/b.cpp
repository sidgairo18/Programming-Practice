#include <bits/stdc++.h>

using namespace std;

long long int my_gcd(long long int x, long long int y){

    if(y == 0)
        return x;

    return my_gcd(y, x%y);
}

int main(){

    long long int a, b, x, y;
    scanf("%lld%lld%lld%lld", &a,&b,&x,&y);

    long long int g = my_gcd(max(x,y), min(x,y));

    x = x/g;
    y = y/g;

    long long int ans1 = a/x;
    long long int ans2 = b/y;

    long long int ans = min(ans1, ans2);

    printf("%lld\n", ans);

    return 0;
}

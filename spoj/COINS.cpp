#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

map<ll, ll> mp;

ll func(ll n){

    if(mp.find(n) != mp.end())
        return mp[n];

    if( n == 0 || n == 1 || n == 2 || n == 3 || n == 4 || n == 5){
        mp[n] = n;
        return mp[n];
    }

    mp[n] = max(n, func(n/2)+func(n/3)+func(n/4));

    return mp[n];
}



int main(){

    ll n;

    while(true){
        
        if(scanf("%lld", &n)==EOF)
            break;
        printf("%lld\n", func(n));
    }

    

    return 0;
}

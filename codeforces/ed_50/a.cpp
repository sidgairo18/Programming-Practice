#include <bits/stdc++.h>

using namespace std;

int main(){

    long double n,k;
    cin>>n>>k;
    
    k = 2*k;
    n = 2*n;
    //cout<<"k : "<<k<<" n : "<<n<<endl;
    long double ans = ceil(k/n);

    printf("%lld\n", (long long int)ans);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int q, n,m,k;

    cin>>q;

    while(q--){

        cin>>n>>m>>k;

        if(k < max(n,m)){
            cout<<"-1"<<endl;
            continue;
        }

        long long int ans = min(n,m);
        long long int left = k-max(n,m);
        if(left%2 != 0)
        {
            ans--;
            left--;
        }
        ans += left;

        cout<<ans<<endl;

    }

    return 0;
}

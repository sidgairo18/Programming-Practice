#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int x,y,n;
        cin>>x>>y>>n;

        int ans2 = floor((n-y)/x)*x+y;
        cout<<ans2<<endl;

    }

    return 0;
}

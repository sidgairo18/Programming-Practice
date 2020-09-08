#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector<long long int> b;

        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            b.push_back(x);
        }

        long long int ans = 0;
        for(int i = 0; i<n-1; i++)
            ans += max(b[i]-b[i+1],b[i]-b[i]);

        cout<<ans<<endl;

    }

    return 0;
}

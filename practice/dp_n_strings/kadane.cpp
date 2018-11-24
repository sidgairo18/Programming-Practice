#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        int a[n];

        for(int i = 0; i<n; i++)
            cin>>a[i];

        int ans = INT_MIN;
        int cur_sum = 0;

        for(int i = 0; i<n; i++){

            cur_sum = max(cur_sum+a[i], a[i]);
            ans = max(ans, cur_sum);
        }

        cout<<ans<<endl;

    }

    return 0;
}

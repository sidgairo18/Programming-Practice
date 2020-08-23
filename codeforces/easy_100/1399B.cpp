#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        long long int min_a = 1e9+7, min_b = 1e9+7;

        long long int a[n];
        long long int b[n];

        for(int i = 0; i<n; i++){
            cin>>a[i];
            min_a = min(min_a, a[i]);
        }

        for(int i=0;  i<n; i++){
            cin>>b[i];
            min_b = min(min_b, b[i]);
        }

        long long int moves = 0;

        for(int i = 0; i<n; i++){

            moves += max(a[i]-min_a, b[i]-min_b);
        }

        cout<<moves<<endl;

    }

    return 0;
}

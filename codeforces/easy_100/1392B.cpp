#include  <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        long long int k;
        cin>>n>>k;

        long long int arr[n];
        long long int min_val = 1e9+7, max_val= -1e9-7;
        for(int i = 0; i<n; i++){
            cin>>arr[i];
            min_val = min(min_val, arr[i]);
            max_val = max(max_val, arr[i]);
        }

        if(k%2 == 1){
            for(int i = 0; i<n; i++)
                cout<<max_val-arr[i]<<" ";
        }
        else{
            for(int i=0; i<n; i++)
                cout<<arr[i]-min_val<<" ";
        }
        cout<<endl;

    }

    return 0;
}

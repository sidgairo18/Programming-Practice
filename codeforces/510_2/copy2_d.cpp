#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int n, t;
    cin>>n>>t;

    long long int arr[n];

    long long int small = INT_MAX;
    for(long long int i = 0; i<n; i++){
        scanf("%lld", &arr[i]);
        small = min(arr[i], small);
    }
   
    if(small< 0){
        t+= n*(-small);

        for(long long int i = 0; i<n; i++)
            arr[i] += (-small);
        
        cout<<t<<endl;
        for(int i = 0; i<n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;

    }

    long long int l = 0, r = 0, ans = 0, cur_sum = 0;

    for(r = 0; r<n; r++){

        cur_sum += arr[r];

        while (cur_sum >= t && l<=r){
            cur_sum -= arr[l];
            l++;
        }
        if(cur_sum < t)
        ans += r-l+1;

    }
    ans++;

    printf("%lld\n", ans);


    return 0;
}

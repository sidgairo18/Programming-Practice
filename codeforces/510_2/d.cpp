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

    while(r<n){
        cur_sum += arr[r];

        if(cur_sum < t){
            
            cout<<l<<" "<<r<<" "<<endl;
            ans += r-l +1;
            r++;
        }

        if(cur_sum >= t){
            cur_sum -= arr[l];
            l++;
            if(l >=r)
                r = l;
        }
    }

    printf("%lld\n", ans);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        long long int k;
        cin>>n>>k;
        long long a[n];
        map<long long int,long long int> mp;
        long long int mx = -1;
        long long val = -1;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            if(a[i]%k !=0){
                if(mp.find(a[i]%k) == mp.end())
                    mp[a[i]%k]=0;
                mp[a[i]%k]++;
                if(mx<mp[a[i]%k]){
                    mx = mp[a[i]%k];
                    val = a[i]%k;
                }
                else if(mx==mp[a[i]%k] && a[i]%k<val)
                    val = a[i]%k;
            }
        }
        long long  count =  0;

        if(mx == -1)
            cout<<0<<endl;
        else{
            count = (mx-1)*k+(k-val+1);
            cout<<count<<endl;
        }


    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;
        int  n = s.size();

        long long int pre_sum[n];

        if(s[0] == '+')
            pre_sum[0] = 1;
        else
            pre_sum[0] = -1;

        for(int i = 1; i<n; i++)
            if (s[i] == '+')
                pre_sum[i] = pre_sum[i-1] + 1;
            else
                pre_sum[i] = pre_sum[i-1] - 1;

        long long curr = -1;
        long long ans = 0;
        long long int prev = -1;

        int i;
        for(i = 0; i<n; i++){

            if(pre_sum[i]<0ll && pre_sum[i]<-curr){

                ans += (i+1)*(-curr-pre_sum[i]);
                if(prev !=-1)
                    ans += (i-prev);
                curr =  -pre_sum[i];
                prev = i;
            }

        }

        ans += (i-prev-1);
        cout<<ans<<endl;


    }

    return 0;
}

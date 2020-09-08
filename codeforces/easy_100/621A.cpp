#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){

    int n;
    cin>>n;
    vector<lli> odd;
    lli ans = 0;

    for(int i = 0; i<n; i++){
        lli x;
        cin>>x;
        if((x&1)==1)
            odd.push_back(x);
        else
            ans += x;
    }
    
    if(odd.size() > 0)
        sort(odd.rbegin(), odd.rend());

    for(int i = 0; i<odd.size()-1 && odd.size()>0;i+=2)
        ans += (odd[i]+odd[i+1]);


    cout<<ans<<endl;

    return 0;
}

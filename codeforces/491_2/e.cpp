#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll my_fact(ll n){

    ll f = 1;
    for(ll i = 2; i<=n; i++)
        f *= i;

    return f;
}

int main(){

    ll n;
    cin>>n;

    vector<int> number;

    ll temp = n;

    int orig_dig[] = {0,0,0,0,0,0,0,0,0,0};

    while(temp!=0){

        int d = temp%10;
        temp/=10;
        number.push_back(d);
        orig_dig[d] += 1;
    }

    int nod = number.size();
    map<string, int> mp;
    ll limit = pow(2, nod);

    ll ans = 0;

    for(ll x = 0; x<limit; x++){


        int dig[] = {0,0,0,0,0,0,0,0,0,0};
        string check = "";
        for(int k = 0; k<nod; k++){
            if(x&(1<<k)){
                dig[number[k]] += 1;
                check += '0'+number[k];
            }
            sort(check.begin(), check.end());
            int flag = 0;
            for(int i = 0; i<10; i++){
                if(orig_dig[i] > 0 && dig[i] == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0 && mp[check] == 0){

//                cout<<x<<" "<<check<<endl;

                ll sz = check.size();
                ll zeros = dig[0];
                ll rest = sz - zeros;
                ll count = 1;
                for(int i = 0; i<sz; i++)
                    if(i == 0){
                        count *= rest;
                        rest--;
                        rest += zeros;
                    }
                    else{
                        count *= rest;
                        rest--;
                    }
                for(int i = 0; i<10; i++)
                    if(dig[i] > 0)
                        count /= my_fact(dig[i]);
                ans += count;
                mp[check] = 1;
            }
        }
    }



    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int sieve[100005];
vector<int> primes;

void make_sieve(){

        primes.push_back(1);

        sieve[0] = sieve[1] = 1;
        for(int i = 2; i*i<=1e5; i++)
                if(!sieve[i]){
                        for(int j = i+i; j<=1e5; j+=i)
                                sieve[j] = 1;
                }

        for(int i = 0; i*i<=1500000; i++)
                if(!sieve[i])
                        primes.push_back(i);
}

int main()
{       
        int n;
        cin>>n;

        make_sieve();
        //cout<<primes.size()<<endl;
        map<int, int> mp;

        for(int i = 0; i<n; i++){

                int x;
                scanf("%d",&x);

                //finding factors
                int flag = 0;


                for(int j = 0; j<primes.size(); j++){
                        int curr = primes[j];
                        int curr2 = curr;

                        while(x%curr2 == 0){
                                if (curr2 != 1)
                                        flag=1;
                                mp[curr2]++;
                                if(curr == 1)
                                        break;
                                curr2*=curr;
                        }
                }
                if (flag == 0 && x!=1)
                {
                        //mp[x]++;
                        continue;
                }
        }

        set<int> s;
        for(auto i:mp){ 
                cout<<i.first<<" "<<i.second<<endl;
                s.insert(i.second);
        }
        if(s.size() == 1){
                cout<<"-1"<<endl;
                return 0;
        }

        auto second_last = s.end();
        second_last--;
        int ans = *second_last;
        second_last--;
        ans -= *second_last;

        cout<<ans<<endl;

        return 0;
}

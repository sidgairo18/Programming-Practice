#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int n,k,s;
    scanf("%lld%lld%lld", &n, &k, &s);

    long long int check = (n-1)*k;
    if( check < s || k > s)
    {
        printf("NO\n");
        return 0;
    }

    vector<long long int> ans;
    ans.push_back(1);

    while(k>0){

        int sz = ans.size();
        if(s-(n-1) >= (k-1)){
            s -= (n-1);
            k--;
            ans.push_back(ans[sz-1] == 1? n:1);
        }
        else if(k>=2){

            s--;
            k--;
            if(ans[sz-1] == n)
                ans.push_back(n-1);
            else if(ans[sz-1] == (n-1))
                ans.push_back(n);
            else if(ans[sz-1] == 1)
                ans.push_back(2);
            else if(ans[sz-1] == 2)
                ans.push_back(1);
            //ans.push_back(ans[sz-1] < n ? ans[sz-1]+1 :ans[sz-1]-1);
        }
        else if(k == 1){
            k--;
            if((ans[sz-1]+s) <= n)
                ans.push_back(ans[sz-1]+s);
            else if(ans[sz-1] - s >=1)
                ans.push_back(ans[sz-1]-s);
            s -= s;
        }
    }

    printf("YES\n");
    int sz = ans.size();
    for(int i = 1; i<sz; i++)
        printf("%lld ", ans[i]);
    printf("\n");

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    scanf("%d%d", &n, &k);

    char s[100];
    scanf("%s", s);

    vector<int> v;

    for(int i = 0; i<n; i++){
        v.push_back(s[i]-'a'+1);
    }

    sort(v.begin(), v.end());


    vector<int> ans;
    ans.push_back(v[0]);

    for(int i = 1; i<n; i++){

        int sz = ans.size();
        if(ans[sz-1]+1 < v[i])
            ans.push_back(v[i]);
    }

    if(ans.size() < k){
        printf("-1\n");
        return 0;
    }
    
    int sm = 0;

    for(int i = 0; i<k; i++)
        sm += ans[i];

    printf("%d\n", sm);


    return 0;
}

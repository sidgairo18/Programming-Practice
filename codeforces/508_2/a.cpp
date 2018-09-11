#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    scanf("%d%d", &n, &k);

    int counts[26];
    char s[100005];

    scanf("%s", s);

    for(int i = 0; i<26; i++)
        counts[i] = 0;
    
    int cut = INT_MAX;
    for(int i = 0; i<n; i++)
        counts[(int)(s[i]-'A')] += 1;


    int ans = n;

    for(int i = 0; i<k; i++)
        cut = min(cut, counts[i]);

    for(int i = 0; i<k; i++){

        if(counts[i] < cut){
            cout<<i<<endl;
            ans = 0;
            break;
        }

        ans = ans - (counts[i]-cut);
        counts[i] = counts[i]-cut;
    }

    printf("%d\n", ans);


    return 0;
}

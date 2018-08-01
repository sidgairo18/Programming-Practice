#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    vector<int> ans;

    char s[55];
    char t[55];

    scanf("%s", s);
    scanf("%s", t);

    int flag = 0;

    for(int i = 0; i<n; i++){

        if(s[i] == t[i])
            continue;

        int j = i;
        while(j<n && s[j] != t[i])
            j++;

        if(j >= n){
            flag = 1;
            //cout<<"YES "<<i<<endl;
            break;
        }

        for(int k = j-1; k>=i; k--){
            char temp = s[k];
            s[k] = s[k+1];
            s[k+1] = temp;
            ans.push_back(k);
        }
    }
    
    if(flag == 1){
        printf("-1\n");
        return 0;
    }
    int k = ans.size();
    printf("%d\n", k);
    for(int i = 0; i<k; i++)
        printf("%d ", ans[i]+1);
    printf("\n");

    return 0;
}

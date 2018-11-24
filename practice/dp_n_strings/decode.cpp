#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        
        int n;
        cin>>n;
        string s;
        cin>>s;

        int ans[n];
        ans[0] = 1;

        for(int i = 1; i<n; i++){

            ans[i] = 0;
            
            if(s[i]!='0')
                ans[i] += ans[i-1];

            int d = (s[i-1]-'0')*10+(s[i]-'0');

            if(i>1 && d>9 && d<=26)
                ans[i] += ans[i-2];
            if(i == 1 && d>9 && d<=26)
                ans[i] += 1;


        }

        cout<<ans[n-1]<<endl;



    }


    return 0;
}

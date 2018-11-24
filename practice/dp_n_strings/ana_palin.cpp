#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;
        int l = s.size();

        int count[26];
        for(int i = 0; i<26; i++)
            count[i] = 0;

        for(int i = 0; i<l; i++)
            count[s[i]-'a'] += 1;
        
        int sm = 0;
        for(int i = 0; i<26; i++)
            sm += count[i]%2;

        if(l%2 == 0 && sm == 0)
            cout<<"Yes"<<endl;
        else if(l%2 != 0 && sm == 1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;



    }

    return 0;
}

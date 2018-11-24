#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        string s1, s2;
        cin>>s1>>s2;

        int k;
        cin>>k;

        int a[26];
        int b[26];

        for(int i = 0; i<26; i++)
            a[i] = b[i] = 0;
        
        if(s1.size() != s2.size()){
            cout<<0<<endl;
            continue;
        }
        for(int i = 0; i<s1.size(); i++){
            a[s1[i] - 'a'] += 1;
            b[s2[i] - 'a'] += 1;
        }

        int count = 0;

        for(int i = 0; i<26; i++)
            cout<<a[i]<<",";
        cout<<endl;
        for(int i = 0; i<26; i++)
            cout<<b[i]<<",";
        cout<<endl;


        for(int i = 0; i<26; i++)
            count += abs(a[i] - b[i]);
        
        count /= 2;
        if(count <= k)
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }

    return 0;
}

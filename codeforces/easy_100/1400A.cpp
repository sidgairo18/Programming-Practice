#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        string s, w;
        cin>>s;
        w = "";
        
        int j = 0;
        for(int i = 0; i<n; i++)
            w = w+s[i+j++];

        cout<<w<<endl;

    }

    return 0;
}

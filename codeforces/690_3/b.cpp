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

        if((s.substr(n-4,4)).compare("2020") == 0)
            cout<<"YES"<<endl;
        else if(s[0] == '2' && (s.substr(n-3,3)).compare("020") == 0)
            cout<<"YES"<<endl;
        else if(s[0] == '2' && s[1] =='0' && s[n-2] == '2' && s[n-1] == '0')
            cout<<"YES"<<endl;
        else if((s.substr(0,3)).compare("202") == 0 && s[n-1] == '0')
            cout<<"YES"<<endl;
        else if ((s.substr(0,4)).compare("2020") == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}

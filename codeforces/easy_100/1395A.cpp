#include <bits/stdc++.h>

using  namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int r,g,b,w;
        cin>>r>>g>>b>>w;
        int odd = r%2 + g%2 + b%2 + w%2;
        if(odd <= 1){
            cout<<"Yes"<<endl;
            continue;
        }

        if(r>=1 && g >= 1 && b >= 1){

            r--,  g--, b--;
            w+=3;
            odd = r%2 + g%2 + b%2 + w%2;
            if(odd <= 1)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

        }
        else
            cout<<"No"<<endl;

    }

    return 0;
}

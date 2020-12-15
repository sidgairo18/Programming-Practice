#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    int digits[9] = {1,2,3,4,5,6,7,8,9};

    while(t--){

        int x;
        cin>>x;

        int vis[9];
        memset(vis, -1, 9*sizeof(vis[0]));

        if(x<10){
            cout<<x<<endl;
            continue;
        }

        if(x>45){
            cout<<-1<<endl;
            continue;
        }

        string ans = "";

        while(x>0){
            for(int i = 8; i>=0; i--){
                if(vis[i] == -1 && digits[i]<=x){
                    x -= digits[i];
                    ans = (char)('0'+digits[i])+ans;
                    vis[i] = 1;
                    break;
                }
            }
        }
        //cout<<t<<" "<<ans<<endl;


        cout<<ans<<endl;


    }

    return 0;
}

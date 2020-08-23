#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> small;
        vector<int> out(n,-1);
        
        int mn = 1e9+1;
        for(int i = 0; i<n; i++){
            cin>>v[i];
            mn = min(v[i], mn);
        }

        for(int i = 0; i<n; i++){
            if(v[i] % mn == 0)
                small.push_back(v[i]);
            else
                out[i] = v[i];
        }

        sort(small.begin(), small.end());
        int j = 0;

        for(int i = 0; i<n;  i++){

            if(out[i] > -1)
                continue;
            else
                out[i] = small[j++];
        }

        int check = 1;
        for(int i = 1; i<n; i++){
            if(out[i] >= out[i-1])
                continue;
            else{
                check =0;
                break;
            }
        }

        if(check)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;

}

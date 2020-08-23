#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i<n; i++)
            cin>>v[i];

        sort(v.begin(), v.end());

        int check = 1;

        for(int i = 1; i<n; i++){
            if(v[i]-v[i-1] > 1){

                check=0;
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

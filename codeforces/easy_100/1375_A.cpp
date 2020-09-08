#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int a[n],b[n];

        for(int i = 0; i<n; i++)
            cin>>a[i];

        // first half
        for(int i=0; i<n; i++)
            if(i%2 == 0)
                cout<<-abs(a[i])<<" ";
            else
                cout<<abs(a[i])<<" ";
        cout<<endl;


    }

    return 0;
}

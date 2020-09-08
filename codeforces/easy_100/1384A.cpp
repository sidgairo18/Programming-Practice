#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int a[n];
        for(int i = 0; i<n; i++)
            cin>>a[i];

        string start = "";
        for(int i = 0; i<200; i++)
            start = start+'a';

        cout<<start<<endl;

        for(int i = 0; i<n; i++){

            string curr;
            curr.assign(start);
            char change = curr[a[i]];
            if(change == 'z')
                change = 'a';
            else
                change = change+1;
            curr[a[i]] = change;

            start.assign(curr);
            cout<<curr<<endl;
        }

    }

    return 0;

}

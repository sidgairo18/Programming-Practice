#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int a[n];
        int ones=0;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            if(a[i] == 1)
                ones++;
        }
        int k = 0;
        while(k<n && a[k]==1)
           k++; 
        if (ones == n && ones%2==0)
            cout<<"Second"<<endl;
        else if(ones == n && ones%2==1)
            cout<<"First"<<endl;
        else if(k%2==0)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;

    }

    return 0;
}

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
        
        int flag = 0; 
        int i,j,k;
        for(j = 1; j<n; j++){

            for(i = j-1; i>=0;i--)
                if(a[i]<a[j])
                    break;
            for(k = j+1; k<n; k++)
                if(a[k]<a[j])
                    break;

            if(i>=0 && k<n &&  a[i] < a[j] && a[j] > a[k])
            {
                flag = 1;
                cout<<"YES"<<endl;
                cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                break;
            }
        }

        if(flag==0)
            cout<<"NO"<<endl;

    }

    return 0;
}

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

        int i = 0, j = n-1;
        int flag = 0;
        while(i<=j){
            if(flag == 0){
                cout<<a[i++]<<" ";
                flag = 1;
            }
            else{
                cout<<a[j--]<<" ";
                flag = 0;
            }
        }
        cout<<endl;
    }

        return 0;
}

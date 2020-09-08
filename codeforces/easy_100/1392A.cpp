#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        int arr[n];

        for(int i = 0; i<n; i++)
            cin>>arr[i];

        int check = 0;
        for(int i = 0; i<n-1; i++)
            if(arr[i] != arr[i+1]){
                check=1;
                break;
            }

        if(check==1)
            cout<<1<<endl;
        else
            cout<<n<<endl;

    }

    return 0;

}

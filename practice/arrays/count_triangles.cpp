#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    int a[n];

    for(int i = 0; i<n; i++)
        cin>>a[i];

    sort(a, a+n);
    int ans = 0;

    for(int i = 0; i<n-2; i++){
        int k = i+2;

        for(int j = i+1; j<n-1; j++){

            while(k<n && (a[i]+a[j]) > a[k])
                k++;

            if(k > j)
                ans += k-j-1;


        }

    }

    cout<<ans<<endl;

    return 0;
}

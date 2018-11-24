#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        string a, b;
        cin>>a;
        cin>>b;

        int i = 0, j = 0;

        int n = a.size();
        int m = b.size();

//        cout<<a<<endl;
  //      cout<<b<<endl;

        while(i < n && j < m){

            while(a[i] != b[j] && j<m)
                j++;
            if(j == m)
                break;
            i++;
            j++;

        }

        if(i == n)
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }

    return 0;
}

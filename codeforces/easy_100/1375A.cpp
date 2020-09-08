#include <bits/stdc++.h>

using  namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n,m;
        cin>>n>>m;
        int a[n][m];
        
        int check = 0;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){
                cin>>a[i][j];

                int neighs = 0;

                if(i-1>=0)
                    neighs++;
                if(j-1>=0)
                    neighs++;
                if(i+1<n)
                    neighs++;
                if(j+1<m)
                    neighs++;

                if(a[i][j] > neighs)
                    check=1;
                else
                    a[i][j] = neighs;
            }
        
        if(check==0){
            cout<<"YES"<<endl;
        for(int i = 0; i<n; i++){

            for(int j = 0; j<m; j++)
                cout<<a[i][j]<<" ";
            cout<<endl;

        }
        }
        else
            cout<<"NO"<<endl;


    }

    return 0;
}

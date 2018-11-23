#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int m,n;
        cin>>m>>n;
        int a[m][n];

        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                cin>>a[i][j];


        int row_start = 0;
        int row_end = m-1;
        int col_start = 0;
        int col_end = n-1;

        while(true){

            for(int i = col_start; i<=col_end; i++)
                cout<<a[row_start][i]<<" ";

            row_start++;

            for(int i = row_start; i<=row_end; i++)
                cout<<a[i][col_end]<<" ";

            col_end--;

            for(int i = col_end; i>=col_start; i--)
                cout<<a[row_end][i]<<" ";

            row_end--;

            for(int i = row_end; i>=row_start; i--)
                cout<<a[i][col_start]<<" ";

            col_start++;

            if(col_start> col_end || row_start>row_end)
                break;


        }
        cout<<endl;

    }

    return 0;
}

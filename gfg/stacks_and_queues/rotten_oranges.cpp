#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int r, c;
        cin>>r>>c;
        int arr[r][c];

        queue<pair<int,int> > qu;

        for(int i = 0; i<r; i++)
            for(int j = 0; j<c; j++){
                cin>>arr[i][j];
                if (arr[i][j] == 2)
                    qu.push(make_pair(i,j));

            }

        qu.push(make_pair(-1, -1));
        int ans = 0;

        while(!qu.empty()){

            if(qu.front().first == -1 && qu.front().second == -1){
                ans++;
                qu.pop();
                if(!qu.empty())
                    qu.push(make_pair(-1,-1));
                continue;
            }

            int i, j;
            i = qu.front().first, j = qu.front().second;

            if(i < r-1 && arr[i+1][j] == 1){
                qu.push(make_pair(i+1, j));
                arr[i+1][j] = 2;
            }
            if(j < c-1 && arr[i][j+1] == 1){
                qu.push(make_pair(i, j+1));
                arr[i][j+1] = 2;
            }
            if(i > 0 && arr[i-1][j] == 1){
                qu.push(make_pair(i-1, j));
                arr[i-1][j] = 2;
            }
            if(j > 0 && arr[i][j-1] == 1){
                qu.push(make_pair(i, j-1));
                arr[i][j-1] = 2;
            }

            qu.pop();
        }

        int check = 1;
        for(int i = 0; i<r; i++)
            for(int j = 0; j<c; j++)
                if(arr[i][j] == 1){
                    check = 0;
                    break;
                }

        if(check == 0)
            cout<<-1<<endl;
        else
            cout<<ans-1<<endl;

    }

    return 0;
}

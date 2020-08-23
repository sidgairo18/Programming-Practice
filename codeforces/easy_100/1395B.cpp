#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    t  = 1;

    while(t--){

        int n,m,sx,sy;
        cin>>n>>m>>sx>>sy;

        int visited[n][m];
        for(int i = 0; i<n; i++)
            for(int j =0; j<n; j++)
                visited[i][j] = -1;

        visited[sx-1][sy-1] = 1;
        queue<pair<int, int> > qu;
        qu.push(make_pair(sx-1, sy-1));

        while(!qu.empty()){

            int x,y;
            x = qu.front().first;
            y = qu.front().second;
            qu.pop();

            cout<<x+1<<" "<<y+1<<endl;

            for(int i =0; i<n; i++){
                int flag = 0;
                for(int j = 0; j<m; j++)
                {

                    if(visited[i][j] == -1 && ((i==x && j!=y) || (i!=x &&  j==y))){
                        qu.push(make_pair(i,j));
                        visited[i][j] = 1;
                        flag = 1;
                        break;
                    }

                }
                if(flag == 1)
                    break;
            }

        }


    }

    return 0;

}

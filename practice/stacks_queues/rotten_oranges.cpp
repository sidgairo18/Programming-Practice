#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    // Your code goes here
    queue<pair<int, int> > q;
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
            if(matrix[i][j] == 2)
                q.push(make_pair(i,j));

    q.push(make_pair(-1, -1));
    int counts = 0;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        if(curr.ff == -1 && curr.ss == -1){
            q.push(make_pair(-1,-1));
            counts++;
            if(q.empty())
                break;
            continue;
        }
        int i = curr.ff, j = curr.ss;
        if(i> 0 && matrix[i-1][j] ==1){
            q.push(make_pair(i-1, j));
            matrix[i-1][j] = 2;
        }
        if(i<R-1 && matrix[i+1][j] == 1){
            q.push(make_pair(i+1, j));
            matrix[i+1][j] = 2;
        }
        if(j>0 && matrix[i][j-1] == 1){
            q.push(make_pair(i,j-1));
            matrix[i][j-1] = 2;
        }
        if(j<C-1 && matrix[i][j+1] == 1){
            q.push(make_pair(i,j+1));
            matrix[i][j+1] = 2;
        }
    }


    int flag = 0;
    for(int i = 0; i<R && flag==0; i++)
        for(int j = 0; j<C; j++)
            if(matrix[i][j] == 1)
                {
                    flag = 1;
                    break;
                }
    if(flag)
        return counts;
    else
        return -1;

}


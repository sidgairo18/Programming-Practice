#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    scanf("%d%d", &n, &m);

    vector<string> mat(1005);

    for(int i = 0; i<n; i++)
        cin>>mat[i];

    int l[1005][1005];
    int r[1005][1005];
    int u[1005][1005];
    int d[1005][1005];
    int h[1005][1005];
    int v[1005][1005];

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++){
            l[i][j] = 0;
            r[i][j] = 0;
            u[i][j] = 0;
            d[i][j] = 0;
            h[i][j] = 0;
            v[i][j] = 0;
        }

    for(int i = 0; i<n; i++){

        for(int j = 0; j<m; j++){

            if(j>0){
                if(mat[i][j] != '.')
                    l[i][j] = l[i][j-1]+1;
            }
            else
                l[i][j] = mat[i][j] != '.';
            if(i > 0){
                if(mat[i][j] != '.')
                    u[i][j] = u[i-1][j] + 1;
            }
            else 
                u[i][j] = mat[i][j] != '.';
        }
    }

    for(int i = n-1; i>=0; i--){

        for(int j = m-1; j>=0; j--){

            if(j < m-1){
                if(mat[i][j] != '.')
                    r[i][j] = r[i][j+1] + 1;
            }
            else
                r[i][j] = mat[i][j] != '.';

            if(i < n-1){
                if(mat[i][j] != '.')
                    d[i][j] = d[i+1][j] + 1;
            }
            else
                d[i][j] = mat[i][j] != '.';
        }
    }

    map< pair<int, int> , int> mp;
    vector< pair<int, int> > vec;

    for(int i = 0; i<n; i++){

        for(int j = 0; j<m; j++){

            int left = l[i][j];
            int right = r[i][j];
            int up = u[i][j];
            int down = d[i][j];
            left = min(left, right);
            up = min(up, down);
            int sz = min(left, up) - 1;

            if(sz > 0){
                mp[make_pair(i,j)] = sz;
                vec.push_back(make_pair(i,j));
                if( i-sz >= 0)
                    v[i-sz][j] += 1;
                if(i+sz+1 < n)
                    v[i+sz+1][j] -= 1;
                if(j-sz >=0)
                    h[i][j-sz] += 1;
                if(j+sz+1 < m)
                    h[i][j+sz+1] -= 1;
            }
        }
    }

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++){
            if(j>0)
                h[i][j] += h[i][j-1];
            if(i>0)
                v[i][j] += v[i-1][j];
        }

    char check[1005][1005];

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            if(h[i][j] > 0 || v[i][j] > 0)
                check[i][j] = '*';
            else
                check[i][j] = '.';

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            if(mat[i][j] != check[i][j])
            {
                printf("-1\n");
                return 0;
            }
    }

    int sz = vec.size();
    printf("%d\n", sz);
    
    for(int i = 0; i<sz; i++)
        cout<<(vec[i].first+1)<<" "<<(vec[i].second+1)<<" "<<mp[make_pair(vec[i].first, vec[i].second)]<<endl;

    return 0;
}

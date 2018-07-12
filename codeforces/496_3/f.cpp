#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m,k;

    scanf("%d%d%d", &n, &m ,&k);

    vector<int> G[n];
    vector<int> a(m);
    vector<int> b(m);

    vector<int> inc[n];
    vector<int> f(n, 0);

    for(int i = 0; i<m; i++){
        scanf("%d%d", &a[i], &b[i]);
        a[i]--, b[i]--;

        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    vector<int> d(n, INT_MAX);
    vector<int> visited(n, -1);

    d[0] = 0;
    queue<int> q;
    q.push(0);

    visited[0] = 1;


    while(!q.empty()){

        int curr = q.front();
        q.pop();

        int sz = G[curr].size();

        for(int i = 0; i<sz; i++){

            int neigh = G[curr][i];
            if(visited[neigh] == 1)
                continue;
            if(d[neigh] > d[curr] +1)
                d[neigh] = d[curr]+1;
            q.push(neigh);
            visited[neigh] = 1;
        }
    }

    for(int i = 0; i<m; i++){

        if(d[a[i]] + 1 == d[b[i]])
            inc[b[i]].push_back(i);
        if(d[b[i]] + 1 == d[a[i]])
            inc[a[i]].push_back(i);
    }

    vector<string> result;

    for(int i = 0; i<k; i++){

        string s(m, '0');

        for(int j = 0; j<n; j++)
            if(f[j] < inc[j].size())
                s[inc[j][f[j]]] = '1';

        int flag = 0;

        for(int j = 0; j<n; j++){

            if(f[j] + 1 < inc[j].size()){

                f[j]++;
                flag = 1;
                break;
            }
            else{
                f[j] = 0;
            }
        }

        result.push_back(s);

        if(flag == 0)
            break;
    }

    int sz = result.size();

    printf("%d\n", (int)sz);

    for(int i = 0; i<sz; i++)
        cout<<result[i]<<endl;



    return 0;
}

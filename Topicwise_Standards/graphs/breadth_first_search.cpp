#include <bits/stdc++.h>

//Assumimg graph G is stored as an adjacency list.
//G is a directed, unqweighted graph.

using namespace std;

void BFS(int v, vector<int> *G, int n ){

    vector<int> vis(n,-1);
    queue<int> q;
    vis[v] = 1;
    q.push(v);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout<<curr<<" ";

        int sz = G[curr].size();

        for(int i = 0; i<sz; i++)
            if(vis[G[curr][i]] == -1){
                vis[G[curr][i]] = 1;
                q.push(G[curr][i]);
            }
    }

    cout<<endl;

}

int main(){

    vector<int> G[100005];
    int m, n;
    cin>>m>>n;

    int x,y;
    for(int i = 0; i<m; i++){
        cin>>x>>y;
        G[x].push_back(y);
    }

    BFS(2, G, n);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int visited[100005];
int reStack[100005];

int isCyclic(int v, vector<int> *G){

    if(!visited[v]){

    visited[v] = 1;
    reStack[v] = 1;

    int sz = G[v].size();

    for(int i =0; i<sz; i++)
        if (!visited[G[v][i]] && isCyclic(G[v][i], G))
            return 1;
        else if (reStack[G[v][i]])
            return 1;
    }

    reStack[v] = 0;
    return 0;

}

int main(){

    vector<int> G[100005];
    int m,n,x,y;

    cin>>m>>n;

    for(int i = 0; i<n; i++){
        visited[i] = 0;
        reStack[i] = 0;
    }

    for(int i = 0; i<m; i++){
        cin>>x>>y;
        G[x].push_back(y);
    }

    int ans = isCyclic(0, G);

    if(ans)
        cout<<"Is Cyclic"<<endl;
    else
        cout<<"Not Cyclic"<<endl;

    return 0;
}

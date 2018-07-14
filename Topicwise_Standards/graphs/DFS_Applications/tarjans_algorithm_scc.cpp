#include <bits/stdc++.h>

using namespace std;

stack<int> st;
int in_stack[100005];

void dfs_tarjan(vector<int> *G, int *visited, int *low, int *disc, int u){

    static int time = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++time;
    st.push(u);
    in_stack[u] = 1;

    //printf("%d\n", u);

    int sz = G[u].size();

    for(int i = 0; i<sz; i++){

        int v = G[u][i];

        if(visited[v] == -1){

            dfs_tarjan(G, visited, low, disc, v);
            low[u] = min(low[u], low[v]);

        }
        else if(in_stack[v] == 1)
            low[u] = min(low[u] , disc[v]);
    }
    //condition to check for head node of a SCC
    if(disc[u] == low[u]){

        printf("HEAD %d\n", u);
        printf("PRINTING Scc ");

        int w;

        while(st.top() != u){

            w = st.top();
            st.pop();
            in_stack[w] = -1;
            printf("%d ", w);
        }

        w = st.top();
        st.pop();
        in_stack[w] = -1;
        printf("%d\n", w);
    }

    return;
}

int main(){

    int n,m;
    scanf("%d%d", &n, &m);
    vector<int> G[n];
    int visited[n];
    int low[n];
    int disc[n];
    //in_stack = new int[n];
    
    for(int i = 0; i<n; i++){

        visited[i] = in_stack[i] = -1;
        low[i] = disc[i] = INT_MAX;
    }

    for(int i = 0; i<m; i++){
        int x,y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        //G[y].push_back(x);
    }

    dfs_tarjan(G, visited, low, disc, 0);



    return 0;
}

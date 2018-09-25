#include <bits/stdc++.h>

using namespace std;

typedef struct node{

    int l, r;
}node;
int n;
char s[13*100000];

vector<node> stree(13*100000);

void build_tree(int l, int r, int i){

    if(l == r){
        if(s[l] == '('){
            stree[i].l = 1;
            stree[i].r = 0;
        }
        else{
            stree[i].r = 1;
            stree[i].l = 0;
        }
        return;
    }

    if(r<l)
        return;

    int mid = (l+r)/2;
    build_tree(l, mid, 2*i+1);
    build_tree(mid+1, r, 2*i+2);
    stree[i].l = stree[2*i+2].l; //adding l of right node;
    stree[i].r = stree[2*i+1].r;

    if(stree[2*i+1].l <= stree[2*i+2].r){
        stree[i].r += abs(stree[2*i+1].l-stree[2*i+2].r);
    }
    else{
        stree[i].l += abs(stree[2*i+1].l-stree[2*i+2].r);
    }
}

void update(int l, int r, int i, int up, node val){

    if(l > up || r < up || l>r)
        return;

    if(l == r && l == up){
        stree[i].l = val.l;
        stree[i].r = val.r;
        //cout<<"YES UPDATED "<<l<<endl;
        return;
    }

    if(l!=r){
        int mid = (l+r)/2;
        update(l, mid, 2*i+1, up, val);
        update(mid+1, r, 2*i+2, up, val);
    }

    stree[i].l = stree[2*i+2].l; //adding l of right node;
    stree[i].r = stree[2*i+1].r;

    if(stree[2*i+1].l <= stree[2*i+2].r){
        stree[i].r += abs(stree[2*i+1].l-stree[2*i+2].r);
    }
    else{
        stree[i].l += abs(stree[2*i+1].l-stree[2*i+2].r);
    }
}

int main(){

    int q, m;
    int t = 1;
    while(true){
        
        if(t>10)
            break;
        scanf("%d", &n);
        printf("Test %d:\n", t);
        t++;

        scanf("%s", s);
        scanf("%d", &m);
        for(int i = 0; i<=2*n; i++)
            stree[i].l = stree[i].r = 0;
        build_tree(0, n-1, 0);

        for(int i = 0; i<m; i++){

            //cout<<"ROOT "<<stree[0].l<<" "<<stree[1].r<<endl;

            //create treee
            scanf("%d", &q);

            if(q == 0){
                if(stree[0].l == stree[0].r && stree[0].l == 0)
                    printf("YES\n");
                else
                    printf("NO\n");

                continue;
            }

            node val;
            if(s[q-1] == '('){
                val.l = 0;
                val.r = 1;
                s[q-1] = ')';
            }
            else
            {
                val.r = 0;
                val.l = 1;
                s[q-1] = '(';
            }

            update(0,n-1, 0, (q-1), val);
            /*
            for(int j = 0; j<=2*n; j++)
                cout<<j<<" : "<<stree[j].l<<" "<<stree[j].r<<",";
            cout<<endl;
            */
        }
    }

    return 0;
}

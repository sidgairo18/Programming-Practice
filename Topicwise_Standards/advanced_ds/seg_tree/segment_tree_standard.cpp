#include <bits/stdc++.h>

using namespace std;

// A segtree has 3 main functions:
// 1.) Create the segtree
// 2.) Query a range (l,r)
// 3.) Update an index


int createSegTree(int *arr, int *st, int ss, int se, int si);
void updateIndex(int *st, int ss, int se, int i, int si, int diff);
int getQuery(int *st, int ss, int se, int l, int r, int si);


int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    //height of tree = ceil(log2(n))
    //max_size of segtree = 2*pow(2, height)-1

    int h = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,h) - 1;
    int st[max_size];

    createSegTree(arr, st, 0, n-1, 0);
    int counter = 0;
    for(int i = 0; i<=h; i++){
        for(int j = 0; j<(int)pow(2,i);j++)
            cout<<st[counter++]<<" ";
        cout<<endl;
    }

    cout<<"Sum in range "<<getQuery(st, 0, n-1, 1,3, 0)<<endl;

    // updating value
    int diff = 10 - arr[1];
    arr[1] = 10;
    updateIndex(st, 0, n-1, 1, 0, diff);
    cout<<"Sum in range after update "<<getQuery(st, 0, n-1, 1,3, 0)<<endl;



        return 0;
}

int createSegTree(int *arr, int *st, int ss, int se, int si){

    if(ss == se){
        st[si] = arr[ss];
        return st[si];
    }

    int mid = (ss+se)/2;
    st[si] = createSegTree(arr, st, ss, mid, 2*si+1)+
        createSegTree(arr, st, mid+1, se, 2*si+2);
    return st[si];
}

void updateIndex(int *st, int ss, int se, int i, int si, int diff){

    if(i < ss || i > se)
        return;

    st[si] += diff;
    if(ss != se){
    int mid = (ss+se)/2;
    updateIndex(st, ss, mid, i, 2*si+1, diff);
    updateIndex(st, mid+1, se, i, 2*si+2, diff);
    }
}

int getQuery(int *st, int ss, int se, int l, int r, int si){

    if(l > se || r < ss)
        return 0;

    if(ss >= l && se <= r)
        return st[si];

    int mid = (ss+se)/2;
    return getQuery(st, ss, mid, l, r, 2*si+1) +
        getQuery(st, mid+1, se, l, r, 2*si+2);

}
